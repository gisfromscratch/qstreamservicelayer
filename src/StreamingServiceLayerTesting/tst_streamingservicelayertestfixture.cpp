#include <QtTest>

// add necessary includes here
#include "StreamingServiceLayer.h"

class StreamingServiceLayerTestFixture : public QObject
{
    Q_OBJECT

public:
    StreamingServiceLayerTestFixture();
    ~StreamingServiceLayerTestFixture();

private slots:
    void test_case1();

};

StreamingServiceLayerTestFixture::StreamingServiceLayerTestFixture()
{

}

StreamingServiceLayerTestFixture::~StreamingServiceLayerTestFixture()
{

}

void StreamingServiceLayerTestFixture::test_case1()
{
    StreamingServiceLayer layer;
    layer.connect("wss://geoeventsample1.esri.com:6143/arcgis/ws/services/AirportTraffics/StreamServer");
}

QTEST_APPLESS_MAIN(StreamingServiceLayerTestFixture)

#include "tst_streamingservicelayertestfixture.moc"
