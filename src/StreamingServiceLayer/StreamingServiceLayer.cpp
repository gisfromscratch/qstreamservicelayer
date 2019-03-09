#include "StreamingServiceLayer.h"
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>

#include <iostream>

StreamingServiceLayer::StreamingServiceLayer(QObject *parent) : QObject (parent)
{
    m_networkManager = new QNetworkAccessManager(this);
}

/*!
 * \brief Connects to the websocket endpoint defined by \a url.
 * \param url the streaming service websocket endpoint.
 */
void StreamingServiceLayer::connect(const QString &url)
{
    QNetworkRequest request;
    request.setUrl(url);
    //m_networkManager->get(request);
    QObject::connect(m_networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(finished(QNetworkReply*)));

    QObject::connect(&m_webSocket, SIGNAL(connected()), this, SLOT(connected()));
    QObject::connect(&m_webSocket, SIGNAL(disconnected()), this, SLOT(disconnected()));
    m_webSocket.open(url);

    /*QObject::connect(reply, &QNetworkReply::finished, this, [reply, &content]() {
        QJsonDocument serviceDef = QJsonDocument::fromJson(content);

        // Housekeeping of the network reply
        //reply->deleteLater();
        //content.clear();
    });

    /*
    m_websocketEndpoint = new QWebSocket(url, QWebSocketProtocol::VersionLatest, this);

    QObject::connect(m_websocketEndpoint, &QWebSocket::connected, []() {
        qDebug() << "Connected";
    });

    QObject::connect(m_websocketEndpoint, &QWebSocket::disconnected, []() {
        qDebug() << "Disconnected";
    });

    QObject::connect(m_websocketEndpoint, &QWebSocket::sslErrors, [this](const QList<QSslError> &errors) {
        qDebug() << "SSL errors";

        this->m_websocketEndpoint->ignoreSslErrors(errors);
    });

    m_websocketEndpoint->open(url);
    m_websocketEndpoint->ping();
    */
}

void StreamingServiceLayer::finished(QNetworkReply *reply)
{
    if (QNetworkReply::NoError != reply->error())
    {
        std::cout << reply->errorString().toStdString();
        return;
    }

    QByteArray content = reply->readAll();
    QJsonDocument serviceDef = QJsonDocument::fromJson(content);
    QString strJson(serviceDef.toJson(QJsonDocument::Compact));
    qDebug() << serviceDef;

    reply->deleteLater();
}

void StreamingServiceLayer::connected()
{
    qDebug() << "Connected";
    QObject::connect(&m_webSocket, SIGNAL(textMessageReceived(QString)), this, SLOT(textMessageReceived(QString)));
}

void StreamingServiceLayer::textMessageReceived(QString message)
{
    //qDebug() << message;
    QJsonDocument json = QJsonDocument::fromJson(message.toUtf8());
    if (json.isObject())
    {
        qDebug() << "JSON object received.";

        QJsonObject jsonObject = json.object();
        print(jsonObject);
    }
}

void StreamingServiceLayer::disconnected()
{
    qDebug() << "Disonnected";
}

void StreamingServiceLayer::print(const QJsonObject &element)
{
    Q_FOREACH (QString subKey, element.keys())
    {
        QJsonValue value = element.value(subKey);
        if (value.isString())
        {
            qDebug() << "\t" << subKey << ":\t" << value.toString();
        }
        else if (value.isBool())
        {
            qDebug() << "\t" << subKey << ":\t" << value.toBool();
        }
        else if (value.isDouble())
        {
            qDebug() << "\t" << subKey << ":\t" << value.toDouble();
        }
        else if (value.isObject())
        {
            qDebug() << "\t{";
            qDebug() << subKey << ":";
            print(value.toObject());
            qDebug() << "\t}";
        }
    }
}
