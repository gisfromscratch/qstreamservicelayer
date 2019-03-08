#ifndef STREAMINGSERVICELAYER_H
#define STREAMINGSERVICELAYER_H

#include "streamingservicelayer_global.h"

#include <QtWebSockets/QWebSocket>

QT_FORWARD_DECLARE_CLASS(QNetworkAccessManager)
QT_FORWARD_DECLARE_CLASS(QNetworkReply)

class STREAMINGSERVICELAYERSHARED_EXPORT StreamingServiceLayer : public QObject
{
    Q_OBJECT

public:
    StreamingServiceLayer(QObject *parent = nullptr);

    void connect(const QString &url);

public slots:
    void ready();
    void finished();

private:
    QWebSocket *m_websocketEndpoint = nullptr;
    QNetworkAccessManager *m_networkManager;
    QNetworkReply *m_networkReply;
    QByteArray m_content;
};

#endif // STREAMINGSERVICELAYER_H
