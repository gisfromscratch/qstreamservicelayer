#include <QCoreApplication>
#include <StreamingServiceLayer.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    StreamingServiceLayer layer;
    layer.connect("https://geoeventsample1.esri.com:6143/arcgis/ws/services/AirportTraffics/StreamServer/subscribe");

    return a.exec();
}
