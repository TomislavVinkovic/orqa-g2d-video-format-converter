#include "../include/G2dPixelFormatConverter.hpp"
#include "../include/G2dFormatManager.hpp"
#include "../include/FileReaderWriter.hpp"
#include "include/G2dConvertTestSuite.hpp"

#include <vector>
#include <iostream>
#include <functional>

void G2dConvertTestSuite::formatsPrintTest() {
    G2dFormatManager::listAllFormats();
}

TestStatus G2dConvertTestSuite::YUYVToRGBAConversionTest() {
    G2dPixelFormatConverter converter;
    FileReaderWriter fileReaderWriter;

    std::vector<uint8_t> yuyvBuffer;
    std::vector<uint8_t> rgbaBuffer;
    std::vector<uint8_t> rgbaExcpectedBuffer;

    fileReaderWriter.readFileRaw("tests/inputs/input.yuyv", yuyvBuffer);
    fileReaderWriter.readFileRaw("tests/expected/yuyv.rgba", rgbaExcpectedBuffer);
    
    G2dPixelFormatConverterStatus result = converter.convertImage(
        ORQA_G2D_FORMAT::FMT_YUYV, 
        ORQA_G2D_FORMAT::FMT_RGBA8888, 
        yuyvBuffer, 
        rgbaBuffer, 
        640, 
        480
    );

    if (result != G2dPixelFormatConverterStatus::SUCCESS) {
        return TestStatus::GENERAL_TEST_FAILURE;
    }
    if (std::equal(rgbaBuffer.begin(), rgbaBuffer.end(), rgbaExcpectedBuffer.begin())) {
        return TestStatus::PASS;
    }
    else {
        return TestStatus::INCORRECT_RESULT_FAILURE;
    }
}
TestStatus G2dConvertTestSuite::I420ToRGBAConversionTest() {
    G2dPixelFormatConverter converter;
    FileReaderWriter fileReaderWriter;

    std::vector<uint8_t> i420Buffer;
    std::vector<uint8_t> rgbaBuffer;
    std::vector<uint8_t> rgbaExcpectedBuffer;

    fileReaderWriter.readFileRaw("tests/inputs/input.i420", i420Buffer);
    fileReaderWriter.readFileRaw("tests/expected/i420.rgba", rgbaExcpectedBuffer);
    
    G2dPixelFormatConverterStatus result = converter.convertImage(
        ORQA_G2D_FORMAT::FMT_I420, 
        ORQA_G2D_FORMAT::FMT_RGBA8888, 
        i420Buffer, 
        rgbaBuffer, 
        640, 
        480
    );

    if (result != G2dPixelFormatConverterStatus::SUCCESS) {
        return TestStatus::GENERAL_TEST_FAILURE;
    }
    if (std::equal(rgbaBuffer.begin(), rgbaBuffer.end(), rgbaExcpectedBuffer.begin())) {
        return TestStatus::PASS;
    }
    else {
        return TestStatus::INCORRECT_RESULT_FAILURE;
    }
}

TestStatus G2dConvertTestSuite::NV12ToRGBAConversionTest() {
    G2dPixelFormatConverter converter;
    FileReaderWriter fileReaderWriter;

    std::vector<uint8_t> nv12Buffer;
    std::vector<uint8_t> rgbaBuffer;
    std::vector<uint8_t> rgbaExcpectedBuffer;

    fileReaderWriter.readFileRaw("tests/inputs/input.nv12", nv12Buffer);
    fileReaderWriter.readFileRaw("tests/expected/nv12.rgba", rgbaExcpectedBuffer);

    G2dPixelFormatConverterStatus result = converter.convertImage(
        ORQA_G2D_FORMAT::FMT_NV12, 
        ORQA_G2D_FORMAT::FMT_RGBA8888, 
        nv12Buffer, 
        rgbaBuffer, 
        640, 
        480
    );

    if (result != G2dPixelFormatConverterStatus::SUCCESS) {
        return TestStatus::GENERAL_TEST_FAILURE;
    }
    if (std::equal(rgbaBuffer.begin(), rgbaBuffer.end(), rgbaExcpectedBuffer.begin())) {
        return TestStatus::PASS;
    }
    else {
        return TestStatus::INCORRECT_RESULT_FAILURE;
    }
}

TestStatus G2dConvertTestSuite::NV21ToRGBAConversionTest() {
    G2dPixelFormatConverter converter;
    FileReaderWriter fileReaderWriter;

    std::vector<uint8_t> nv21Buffer;
    std::vector<uint8_t> rgbaBuffer;
    std::vector<uint8_t> rgbaExcpectedBuffer;

    fileReaderWriter.readFileRaw("tests/inputs/input.nv21", nv21Buffer);
    fileReaderWriter.readFileRaw("tests/expected/nv21.rgba", rgbaExcpectedBuffer);
    
    G2dPixelFormatConverterStatus result = converter.convertImage(
        ORQA_G2D_FORMAT::FMT_NV21, 
        ORQA_G2D_FORMAT::FMT_RGBA8888, 
        nv21Buffer, 
        rgbaBuffer, 
        640, 
        480
    );

    if (result != G2dPixelFormatConverterStatus::SUCCESS) {
        return TestStatus::GENERAL_TEST_FAILURE;
    }
    if (std::equal(rgbaBuffer.begin(), rgbaBuffer.end(), rgbaExcpectedBuffer.begin())) {
        return TestStatus::PASS;
    }
    else {
        return TestStatus::INCORRECT_RESULT_FAILURE;
    }
}

TestStatus G2dConvertTestSuite::UYVYToRGBAConversionTest() {
    G2dPixelFormatConverter converter;
    FileReaderWriter fileReaderWriter;

    std::vector<uint8_t> uyvyBuffer;
    std::vector<uint8_t> rgbaBuffer;
    std::vector<uint8_t> rgbaExcpectedBuffer;

    fileReaderWriter.readFileRaw("tests/inputs/input.uyvy", uyvyBuffer);
    fileReaderWriter.readFileRaw("tests/expected/uyvy.rgba", rgbaExcpectedBuffer);
    
    G2dPixelFormatConverterStatus result = converter.convertImage(
        ORQA_G2D_FORMAT::FMT_UYVY, 
        ORQA_G2D_FORMAT::FMT_RGBA8888, 
        uyvyBuffer, 
        rgbaBuffer, 
        640, 
        480
    );

    if (result != G2dPixelFormatConverterStatus::SUCCESS) {
        return TestStatus::GENERAL_TEST_FAILURE;
    }
    if (std::equal(rgbaBuffer.begin(), rgbaBuffer.end(), rgbaExcpectedBuffer.begin())) {
        return TestStatus::PASS;
    }
    else {
        return TestStatus::INCORRECT_RESULT_FAILURE;
    }
}

TestStatus G2dConvertTestSuite::YV12ToRGBAConversionTest() {
    G2dPixelFormatConverter converter;
    FileReaderWriter fileReaderWriter;

    std::vector<uint8_t> yv12Buffer;
    std::vector<uint8_t> rgbaBuffer;
    std::vector<uint8_t> rgbaExcpectedBuffer;

    fileReaderWriter.readFileRaw("tests/inputs/input.yv12", yv12Buffer);
    fileReaderWriter.readFileRaw("tests/expected/yv12.rgba", rgbaExcpectedBuffer);

    G2dPixelFormatConverterStatus result = converter.convertImage(
        ORQA_G2D_FORMAT::FMT_YV12, 
        ORQA_G2D_FORMAT::FMT_RGBA8888, 
        yv12Buffer, 
        rgbaBuffer, 
        640, 
        480
    );

    if (result != G2dPixelFormatConverterStatus::SUCCESS) {
        return TestStatus::GENERAL_TEST_FAILURE;
    }
    if (std::equal(rgbaBuffer.begin(), rgbaBuffer.end(), rgbaExcpectedBuffer.begin())) {
        return TestStatus::PASS;
    }
    else {
        return TestStatus::INCORRECT_RESULT_FAILURE;
    }
    
}

TestStatus G2dConvertTestSuite::YVYUToRGBAConversionTest() {
    G2dPixelFormatConverter converter;
    FileReaderWriter fileReaderWriter;

    std::vector<uint8_t> yvyuBuffer;
    std::vector<uint8_t> rgbaBuffer;
    std::vector<uint8_t> rgbaExcpectedBuffer;

    fileReaderWriter.readFileRaw("tests/inputs/input.yvyu", yvyuBuffer);
    fileReaderWriter.readFileRaw("tests/expected/yvyu.rgba", rgbaExcpectedBuffer);
    
    G2dPixelFormatConverterStatus result = converter.convertImage(
        ORQA_G2D_FORMAT::FMT_YVYU, 
        ORQA_G2D_FORMAT::FMT_RGBA8888, 
        yvyuBuffer, 
        rgbaBuffer, 
        640, 
        480
    );

    if (result != G2dPixelFormatConverterStatus::SUCCESS) {
        return TestStatus::GENERAL_TEST_FAILURE;
    }
    if (std::equal(rgbaBuffer.begin(), rgbaBuffer.end(), rgbaExcpectedBuffer.begin())) {
        return TestStatus::PASS;
    }
    else {
        return TestStatus::INCORRECT_RESULT_FAILURE;
    }
}

G2dConvertTestSuiteStatus G2dConvertTestSuite::runAllTests() {
    std::vector<std::function<TestStatus()>> tests = {
        [this]() { return YUYVToRGBAConversionTest(); },
        [this]() { return I420ToRGBAConversionTest(); },
        [this]() { return NV12ToRGBAConversionTest(); },
        [this]() { return NV21ToRGBAConversionTest(); },
        [this]() { return UYVYToRGBAConversionTest(); },
        [this]() { return YV12ToRGBAConversionTest(); },
        [this]() { return YVYUToRGBAConversionTest(); }
    };

    for (int i = 0; i < tests.size(); i++) {
        TestStatus result = tests[i]();
        if (result == TestStatus::PASS) {
            std::cout << "Test " << i+1 << " passed" << std::endl;
        }
        else if (result == TestStatus::GENERAL_TEST_FAILURE) {
            std::cout << "Test " << i+1 << " failed with general test failure" << std::endl;
            return G2dConvertTestSuiteStatus::FAILURE;
        }
        else if(result == TestStatus::INCORRECT_RESULT_FAILURE) {
            std::cout << "Test " << i+1 << " failed" << std::endl;
            return G2dConvertTestSuiteStatus::FAILURE;
        }
    }
    
    std::cout << "All tests passed" << std::endl;
    return G2dConvertTestSuiteStatus::SUCCESS;
}