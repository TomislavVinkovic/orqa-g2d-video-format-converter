# pragma once

class G2dConvertTestSuite {
    void formatsPrintTest();
    int YUYVToRGBAConversionTest();
    int I420ToRGBAConversionTest();
    int YV12ToRGBAConversionTest();
    int NV12ToRGBAConversionTest();
    int NV21ToRGBAConversionTest();
    int UYVYToRGBAConversionTest();
    int YVYUToRGBAConversionTest();

    public:
        G2dConvertTestSuite() = default;
        ~G2dConvertTestSuite() = default;
        int runAllTests();
};