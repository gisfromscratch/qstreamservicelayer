#include "StreamingServiceLayer.h"
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>

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
    if (m_websocketEndpoint)
    {
        // TODO: Housekeeping close and delete
        delete m_websocketEndpoint;
        m_websocketEndpoint = nullptr;
    }

    QNetworkRequest request;
    request.setUrl(url);
    m_networkReply = m_networkManager->get(request);
    QByteArray content;
    QObject::connect(m_networkReply, SIGNAL(readyRead()), this, SLOT(ready()));
    QObject::connect(m_networkReply, SIGNAL(finished()), this, SLOT(finished()));

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

void StreamingServiceLayer::ready()
{
    m_content = m_networkReply->readAll();
}

void StreamingServiceLayer::finished()
{
    QJsonDocument serviceDef = QJsonDocument::fromJson(m_content);
    QString strJson(serviceDef.toJson(QJsonDocument::Compact));
    qDebug() << serviceDef;

    m_networkReply->deleteLater();
}
