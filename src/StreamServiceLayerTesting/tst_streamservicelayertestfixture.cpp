#include <QtTest>

// add necessary includes here
#include "../QStreamServiceLayer/streamservicelayer.h"

class StreamserviceLayerTestFixture : public QObject
{
    Q_OBJECT

public:
    StreamserviceLayerTestFixture();
    ~StreamserviceLayerTestFixture();

private slots:
    void test_case1();

};

StreamserviceLayerTestFixture::StreamserviceLayerTestFixture()
{

}

StreamserviceLayerTestFixture::~StreamserviceLayerTestFixture()
{

}

void StreamserviceLayerTestFixture::test_case1()
{

}

QTEST_APPLESS_MAIN(StreamserviceLayerTestFixture)

#include "tst_streamservicelayertestfixture.moc"
