#include "include/G2dPixelFormatConverter.hpp"
#include "include/image-io.hpp"

#include <vector>
#include <iostream>
#include <functional>

void formatsPrintTest() {
    G2dPixelFormatConverter converter;
    converter.listAllFormats();
}

int YUYVToRGBAConversionTest() {
    G2dPixelFormatConverter converter;

    std::vector<uint8_t> yuyvBuffer;
    std::vector<uint8_t> rgbaBuffer;
    std::vector<uint8_t> rgbaExcpectedBuffer;

    readImageRaw("tests/inputs/input.yuyv", yuyvBuffer);
    readImageRaw("tests/expected/yuyv.rgba", rgbaExcpectedBuffer);
    
    int result = converter.convertImage(
        "YUYV", 
        "RGBA8888", 
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
int I420ToRGBAConversionTest() {
    G2dPixelFormatConverter converter;

    std::vector<uint8_t> i420Buffer;
    std::vector<uint8_t> rgbaBuffer;
    std::vector<uint8_t> rgbaExcpectedBuffer;

    readImageRaw("tests/inputs/input.i420", i420Buffer);
    readImageRaw("tests/expected/i420.rgba", rgbaExcpectedBuffer);
    
    int result = converter.convertImage(
        "I420", 
        "RGBA8888", 
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

int NV12ToRGBAConversionTest() {
    G2dPixelFormatConverter converter;

    std::vector<uint8_t> nv12Buffer;
    std::vector<uint8_t> rgbaBuffer;
    std::vector<uint8_t> rgbaExcpectedBuffer;

    readImageRaw("tests/inputs/input.nv12", nv12Buffer);
    readImageRaw("tests/expected/nv12.rgba", rgbaExcpectedBuffer);

    int result = converter.convertImage(
        "NV12", 
        "RGBA8888", 
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

int NV21ToRGBAConversionTest() {
    G2dPixelFormatConverter converter;

    std::vector<uint8_t> nv21Buffer;
    std::vector<uint8_t> rgbaBuffer;
    std::vector<uint8_t> rgbaExcpectedBuffer;

    readImageRaw("tests/inputs/input.nv21", nv21Buffer);
    readImageRaw("tests/expected/nv21.rgba", rgbaExcpectedBuffer);
    
    int result = converter.convertImage(
        "NV21", 
        "RGBA8888", 
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

int UYVYToRGBAConversionTest() {
    G2dPixelFormatConverter converter;

    std::vector<uint8_t> uyvyBuffer;
    std::vector<uint8_t> rgbaBuffer;
    std::vector<uint8_t> rgbaExcpectedBuffer;

    readImageRaw("tests/inputs/input.uyvy", uyvyBuffer);
    readImageRaw("tests/expected/uyvy.rgba", rgbaExcpectedBuffer);
    
    int result = converter.convertImage(
        "UYVY", 
        "RGBA8888", 
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

int YV12ToRGBAConversionTest() {
    G2dPixelFormatConverter converter;

    std::vector<uint8_t> yv12Buffer;
    std::vector<uint8_t> rgbaBuffer;
    std::vector<uint8_t> rgbaExcpectedBuffer;

    readImageRaw("tests/inputs/input.yv12", yv12Buffer);
    readImageRaw("tests/expected/yv12.rgba", rgbaExcpectedBuffer);

    int result = converter.convertImage(
        "YV12", 
        "RGBA8888", 
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

int YVYUToRGBAConversionTest() {
    G2dPixelFormatConverter converter;

    std::vector<uint8_t> yvyuBuffer;
    std::vector<uint8_t> rgbaBuffer;
    std::vector<uint8_t> rgbaExcpectedBuffer;

    readImageRaw("tests/inputs/input.yvyu", yvyuBuffer);
    readImageRaw("tests/expected/yv12.rgba", rgbaExcpectedBuffer);
    
    int result = converter.convertImage(
        "YVYU", 
        "RGBA8888", 
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

int main() {
    std::vector<int (*)()> tests = {
        YUYVToRGBAConversionTest,
        I420ToRGBAConversionTest,
        NV12ToRGBAConversionTest,
        NV21ToRGBAConversionTest,
        UYVYToRGBAConversionTest,
        YV12ToRGBAConversionTest,
        YVYUToRGBAConversionTest
    };

    for (int i = 0; i < tests.size(); i++) {
        int result = tests[i]();
        if (result == 0) {
            std::cout << "Test " << i << " passed" << std::endl;
        }
        else {
            std::cout << "Test " << i << " failed" << std::endl;
        }
        
    }
}