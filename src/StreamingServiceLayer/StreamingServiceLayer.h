#ifndef STREAMINGSERVICELAYER_H
#define STREAMINGSERVICELAYER_H

#include "streamingservicelayer_global.h"

#include <QtWebSockets/QWebSocket>

class STREAMINGSERVICELAYERSHARED_EXPORT StreamingServiceLayer : public QObject
{
    Q_OBJECT

public:
    StreamingServiceLayer(QObject *parent = nullptr);

    void connect(const QString &url);

private:
    QWebSocket *m_websocketEndpoint = nullptr;
};

#endif // STREAMINGSERVICELAYER_H
