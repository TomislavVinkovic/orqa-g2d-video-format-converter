# pragma once

enum class G2dConvertTestSuiteStatus {
    SUCCESS = 0,
    FAILURE = -1
};

enum class TestStatus {
    PASS = 0,
    GENERAL_TEST_FAILURE = -1,
    INCORRECT_RESULT_FAILURE = -2,
};

class G2dConvertTestSuite {
    void formatsPrintTest();
    TestStatus YUYVToRGBAConversionTest();
    TestStatus I420ToRGBAConversionTest();
    TestStatus YV12ToRGBAConversionTest();
    TestStatus NV12ToRGBAConversionTest();
    TestStatus NV21ToRGBAConversionTest();
    TestStatus UYVYToRGBAConversionTest();
    TestStatus YVYUToRGBAConversionTest();

    public:
        G2dConvertTestSuite() = default;
        ~G2dConvertTestSuite() = default;
        G2dConvertTestSuiteStatus runAllTests();
};