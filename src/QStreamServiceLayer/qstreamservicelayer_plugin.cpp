#include "qstreamservicelayer_plugin.h"
#include "streamservicelayer.h"

#include <qqml.h>

void QStreamServiceLayerPlugin::registerTypes(const char *uri)
{
    // @uri edu.gis.streamservice
    qmlRegisterType<StreamServiceLayer>(uri, 1, 0, "StreamServiceLayer");
}

