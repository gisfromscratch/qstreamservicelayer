#ifndef STREAMINGSERVICELAYER_H
#define STREAMINGSERVICELAYER_H

#include "streamingservicelayer_global.h"

#include <QtWebSockets/QWebSocket>

QT_FORWARD_DECLARE_CLASS(QNetworkAccessManager)
QT_FORWARD_DECLARE_CLASS(QNetworkReply)
QT_FORWARD_DECLARE_CLASS(QJsonObject)

class STREAMINGSERVICELAYERSHARED_EXPORT StreamingServiceLayer : public QObject
{
    Q_OBJECT

public:
    StreamingServiceLayer(QObject *parent = nullptr);

    void connect(const QString &url);

public slots:
    void connected();
    void textMessageReceived(QString message);
    void disconnected();

    void finished(QNetworkReply*);

private:
    void print(const QJsonObject &element);

    QWebSocket m_webSocket;
    QNetworkAccessManager *m_networkManager = nullptr;
};

#endif // STREAMINGSERVICELAYER_H
