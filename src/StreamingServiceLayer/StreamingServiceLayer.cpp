#include "StreamingServiceLayer.h"


StreamingServiceLayer::StreamingServiceLayer(QObject *parent) : QObject (parent)
{
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

    m_websocketEndpoint = new QWebSocket(url, QWebSocketProtocol::VersionLatest, this);

    QObject::connect(m_websocketEndpoint, &QWebSocket::connected, this, []() {
        qDebug() << "Connected";
    });

    QObject::connect(m_websocketEndpoint, &QWebSocket::disconnected, this, []() {
        qDebug() << "Disconnected";
    });

    m_websocketEndpoint->open(url);
    m_websocketEndpoint->ping();
}
