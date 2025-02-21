#include "../include/G2dPixelFormatConverter.hpp"
#include "../include/image-io.hpp"
#include "include/G2dConvertTestSuite.hpp"

#include <vector>
#include <iostream>
#include <functional>

void G2dConvertTestSuite::formatsPrintTest() {
    G2dPixelFormatConverter converter;
    converter.listAllFormats();
}

int G2dConvertTestSuite::YUYVToRGBAConversionTest() {
    G2dPixelFormatConverter converter;

    std::vector<uint8_t> yuyvBuffer;
    std::vector<uint8_t> rgbaBuffer;
    std::vector<uint8_t> rgbaExcpectedBuffer;

    readImageRaw("tests/inputs/input.yuyv", yuyvBuffer);
    readImageRaw("tests/expected/yuyv.rgba", rgbaExcpectedBuffer);
    
    int result = converter.convertImage(
        ORQA_G2D_FORMAT::G2D_YUYV, 
        ORQA_G2D_FORMAT::G2D_RGBA8888, 
        yuyvBuffer, 
        rgbaBuffer, 
        640, 
        480
    );

    if (result != 0) {
        return result;
    }
    if (std::equal(rgbaBuffer.begin(), rgbaBuffer.end(), rgbaExcpectedBuffer.begin())) {
        return 0;
    }
    else {
        return -1;
    }
}
int G2dConvertTestSuite::I420ToRGBAConversionTest() {
    G2dPixelFormatConverter converter;

    std::vector<uint8_t> i420Buffer;
    std::vector<uint8_t> rgbaBuffer;
    std::vector<uint8_t> rgbaExcpectedBuffer;

    readImageRaw("tests/inputs/input.i420", i420Buffer);
    readImageRaw("tests/expected/i420.rgba", rgbaExcpectedBuffer);
    
    int result = converter.convertImage(
        ORQA_G2D_FORMAT::G2D_I420, 
        ORQA_G2D_FORMAT::G2D_RGBA8888, 
        i420Buffer, 
        rgbaBuffer, 
        640, 
        480
    );

    if (result != 0) {
        return result;
    }
    if (std::equal(rgbaBuffer.begin(), rgbaBuffer.end(), rgbaExcpectedBuffer.begin())) {
        return 0;
    }
    else {
        return -1;
    }
}

int G2dConvertTestSuite::NV12ToRGBAConversionTest() {
    G2dPixelFormatConverter converter;

    std::vector<uint8_t> nv12Buffer;
    std::vector<uint8_t> rgbaBuffer;
    std::vector<uint8_t> rgbaExcpectedBuffer;

    readImageRaw("tests/inputs/input.nv12", nv12Buffer);
    readImageRaw("tests/expected/nv12.rgba", rgbaExcpectedBuffer);

    int result = converter.convertImage(
        ORQA_G2D_FORMAT::G2D_NV12, 
        ORQA_G2D_FORMAT::G2D_RGBA8888, 
        nv12Buffer, 
        rgbaBuffer, 
        640, 
        480
    );

    if (result != 0) {
        return result;
    }

    // see if the output is the same as the expected
    if (std::equal(rgbaBuffer.begin(), rgbaBuffer.end(), rgbaExcpectedBuffer.begin())) {
        return 0;
    }
    else {
        return -1;
    }
}

int G2dConvertTestSuite::NV21ToRGBAConversionTest() {
    G2dPixelFormatConverter converter;

    std::vector<uint8_t> nv21Buffer;
    std::vector<uint8_t> rgbaBuffer;
    std::vector<uint8_t> rgbaExcpectedBuffer;

    readImageRaw("tests/inputs/input.nv21", nv21Buffer);
    readImageRaw("tests/expected/nv21.rgba", rgbaExcpectedBuffer);
    
    int result = converter.convertImage(
        ORQA_G2D_FORMAT::G2D_NV21, 
        ORQA_G2D_FORMAT::G2D_RGBA8888, 
        nv21Buffer, 
        rgbaBuffer, 
        640, 
        480
    );

    if (result != 0) {
        return result;
    }
    if (std::equal(rgbaBuffer.begin(), rgbaBuffer.end(), rgbaExcpectedBuffer.begin())) {
        return 0;
    }
    else {
        return -1;
    }
}

int G2dConvertTestSuite::UYVYToRGBAConversionTest() {
    G2dPixelFormatConverter converter;

    std::vector<uint8_t> uyvyBuffer;
    std::vector<uint8_t> rgbaBuffer;
    std::vector<uint8_t> rgbaExcpectedBuffer;

    readImageRaw("tests/inputs/input.uyvy", uyvyBuffer);
    readImageRaw("tests/expected/uyvy.rgba", rgbaExcpectedBuffer);
    
    int result = converter.convertImage(
        ORQA_G2D_FORMAT::G2D_UYVY, 
        ORQA_G2D_FORMAT::G2D_RGBA8888, 
        uyvyBuffer, 
        rgbaBuffer, 
        640, 
        480
    );

    if (result != 0) {
        return result;
    }
    if (std::equal(rgbaBuffer.begin(), rgbaBuffer.end(), rgbaExcpectedBuffer.begin())) {
        return 0;
    }
    else {
        return -1;
    }
}

int G2dConvertTestSuite::YV12ToRGBAConversionTest() {
    G2dPixelFormatConverter converter;

    std::vector<uint8_t> yv12Buffer;
    std::vector<uint8_t> rgbaBuffer;
    std::vector<uint8_t> rgbaExcpectedBuffer;

    readImageRaw("tests/inputs/input.yv12", yv12Buffer);
    readImageRaw("tests/expected/yv12.rgba", rgbaExcpectedBuffer);

    int result = converter.convertImage(
        ORQA_G2D_FORMAT::G2D_YV12, 
        ORQA_G2D_FORMAT::G2D_RGBA8888, 
        yv12Buffer, 
        rgbaBuffer, 
        640, 
        480
    );

    if (result != 0) {
        return result;
    }
    if (std::equal(rgbaBuffer.begin(), rgbaBuffer.end(), rgbaExcpectedBuffer.begin())) {
        return 0;
    }
    else {
        return -1;
    }
    
}

int G2dConvertTestSuite::YVYUToRGBAConversionTest() {
    G2dPixelFormatConverter converter;

    std::vector<uint8_t> yvyuBuffer;
    std::vector<uint8_t> rgbaBuffer;
    std::vector<uint8_t> rgbaExcpectedBuffer;

    readImageRaw("tests/inputs/input.yvyu", yvyuBuffer);
    readImageRaw("tests/expected/yvyu.rgba", rgbaExcpectedBuffer);
    
    int result = converter.convertImage(
        ORQA_G2D_FORMAT::G2D_YVYU, 
        ORQA_G2D_FORMAT::G2D_RGBA8888, 
        yvyuBuffer, 
        rgbaBuffer, 
        640, 
        480
    );

    if (result != 0) {
        return result;
    }
    if (std::equal(rgbaBuffer.begin(), rgbaBuffer.end(), rgbaExcpectedBuffer.begin())) {
        return 0;
    }
    else {
        return -1;
    }
}

int G2dConvertTestSuite::runAllTests() {
    std::vector<std::function<int()>> tests = {
        [this]() { return YUYVToRGBAConversionTest(); },
        [this]() { return I420ToRGBAConversionTest(); },
        [this]() { return NV12ToRGBAConversionTest(); },
        [this]() { return NV21ToRGBAConversionTest(); },
        [this]() { return UYVYToRGBAConversionTest(); },
        [this]() { return YV12ToRGBAConversionTest(); },
        [this]() { return YVYUToRGBAConversionTest(); }
    };

    for (int i = 0; i < tests.size(); i++) {
        int result = tests[i]();
        if (result == 0) {
            std::cout << "Test " << i+1 << " passed" << std::endl;
        }
        else {
            std::cout << "Test " << i+1 << " failed" << std::endl;
            return -1;
        }
    }
    std::cout << "All tests passed" << std::endl;
    return 0;
}