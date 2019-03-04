#ifndef STREAMSERVICELAYER_H
#define STREAMSERVICELAYER_H

#include <QQuickItem>

class StreamServiceLayer : public QQuickItem
{
    Q_OBJECT
    Q_DISABLE_COPY(StreamServiceLayer)

public:
    StreamServiceLayer(QQuickItem *parent = nullptr);
    ~StreamServiceLayer();
};

#endif // STREAMSERVICELAYER_H
