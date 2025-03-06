#include "G2dPixelFormatConverter.hpp"
#include "G2dFormatManager.hpp"
#include "FileReaderWriter.hpp"

#include <vector>
#include <iostream>
#include <functional>

enum class G2dConvertTestSuiteStatus {
    SUCCESS = 0,
    FAILURE = -1
};

enum class TestStatus {
    PASS = 0,
    GENERAL_TEST_FAILURE = -1,
    INCORRECT_RESULT_FAILURE = -2,
};

void formatsPrintTest() {
    G2dFormatManager::listAllFormats();
}

TestStatus YUYVToRGBAConversionTest() {
    G2dPixelFormatConverter converter;
    FileReaderWriter fileReaderWriter;

    std::vector<uint8_t> yuyvBuffer;
    std::vector<uint8_t> rgbaBuffer;
    std::vector<uint8_t> rgbaExcpectedBuffer;

    fileReaderWriter.readFileRaw("tests/inputs/input.yuyv", yuyvBuffer);
    fileReaderWriter.readFileRaw("tests/expected/yuyv.rgba", rgbaExcpectedBuffer);
    
    G2dPixelFormatConverterStatus result = converter.convertImage(
        OrqaG2dFormat::FMT_YUYV, 
        OrqaG2dFormat::FMT_RGBA8888, 
        yuyvBuffer, 
        rgbaBuffer, 
        640, 
        480,
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
TestStatus I420ToRGBAConversionTest() {
    G2dPixelFormatConverter converter;
    FileReaderWriter fileReaderWriter;

    std::vector<uint8_t> i420Buffer;
    std::vector<uint8_t> rgbaBuffer;
    std::vector<uint8_t> rgbaExcpectedBuffer;

    fileReaderWriter.readFileRaw("tests/inputs/input.i420", i420Buffer);
    fileReaderWriter.readFileRaw("tests/expected/i420.rgba", rgbaExcpectedBuffer);
    
    G2dPixelFormatConverterStatus result = converter.convertImage(
        OrqaG2dFormat::FMT_I420, 
        OrqaG2dFormat::FMT_RGBA8888, 
        i420Buffer, 
        rgbaBuffer, 
        640, 
        480,
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

TestStatus NV12ToRGBAConversionTest() {
    G2dPixelFormatConverter converter;
    FileReaderWriter fileReaderWriter;

    std::vector<uint8_t> nv12Buffer;
    std::vector<uint8_t> rgbaBuffer;
    std::vector<uint8_t> rgbaExcpectedBuffer;

    fileReaderWriter.readFileRaw("tests/inputs/input.nv12", nv12Buffer);
    fileReaderWriter.readFileRaw("tests/expected/nv12.rgba", rgbaExcpectedBuffer);

    G2dPixelFormatConverterStatus result = converter.convertImage(
        OrqaG2dFormat::FMT_NV12, 
        OrqaG2dFormat::FMT_RGBA8888, 
        nv12Buffer, 
        rgbaBuffer, 
        640, 
        480,
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

TestStatus NV21ToRGBAConversionTest() {
    G2dPixelFormatConverter converter;
    FileReaderWriter fileReaderWriter;

    std::vector<uint8_t> nv21Buffer;
    std::vector<uint8_t> rgbaBuffer;
    std::vector<uint8_t> rgbaExcpectedBuffer;

    fileReaderWriter.readFileRaw("tests/inputs/input.nv21", nv21Buffer);
    fileReaderWriter.readFileRaw("tests/expected/nv21.rgba", rgbaExcpectedBuffer);
    
    G2dPixelFormatConverterStatus result = converter.convertImage(
        OrqaG2dFormat::FMT_NV21, 
        OrqaG2dFormat::FMT_RGBA8888, 
        nv21Buffer, 
        rgbaBuffer, 
        640, 
        480,
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

TestStatus UYVYToRGBAConversionTest() {
    G2dPixelFormatConverter converter;
    FileReaderWriter fileReaderWriter;

    std::vector<uint8_t> uyvyBuffer;
    std::vector<uint8_t> rgbaBuffer;
    std::vector<uint8_t> rgbaExcpectedBuffer;

    fileReaderWriter.readFileRaw("tests/inputs/input.uyvy", uyvyBuffer);
    fileReaderWriter.readFileRaw("tests/expected/uyvy.rgba", rgbaExcpectedBuffer);
    
    G2dPixelFormatConverterStatus result = converter.convertImage(
        OrqaG2dFormat::FMT_UYVY, 
        OrqaG2dFormat::FMT_RGBA8888, 
        uyvyBuffer, 
        rgbaBuffer, 
        640, 
        480,
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

TestStatus YV12ToRGBAConversionTest() {
    G2dPixelFormatConverter converter;
    FileReaderWriter fileReaderWriter;

    std::vector<uint8_t> yv12Buffer;
    std::vector<uint8_t> rgbaBuffer;
    std::vector<uint8_t> rgbaExcpectedBuffer;

    fileReaderWriter.readFileRaw("tests/inputs/input.yv12", yv12Buffer);
    fileReaderWriter.readFileRaw("tests/expected/yv12.rgba", rgbaExcpectedBuffer);

    G2dPixelFormatConverterStatus result = converter.convertImage(
        OrqaG2dFormat::FMT_YV12, 
        OrqaG2dFormat::FMT_RGBA8888, 
        yv12Buffer, 
        rgbaBuffer, 
        640, 
        480,
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

TestStatus YVYUToRGBAConversionTest() {
    G2dPixelFormatConverter converter;
    FileReaderWriter fileReaderWriter;

    std::vector<uint8_t> yvyuBuffer;
    std::vector<uint8_t> rgbaBuffer;
    std::vector<uint8_t> rgbaExcpectedBuffer;

    fileReaderWriter.readFileRaw("tests/inputs/input.yvyu", yvyuBuffer);
    fileReaderWriter.readFileRaw("tests/expected/yvyu.rgba", rgbaExcpectedBuffer);
    
    G2dPixelFormatConverterStatus result = converter.convertImage(
        OrqaG2dFormat::FMT_YVYU, 
        OrqaG2dFormat::FMT_RGBA8888, 
        yvyuBuffer, 
        rgbaBuffer, 
        640, 
        480,
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

TestStatus YUYVToRGBAConversionTestWithResize() {
    G2dPixelFormatConverter converter;
    FileReaderWriter fileReaderWriter;
    std::vector<uint8_t> yuyvBuffer;
    std::vector<uint8_t> rgbaBuffer;
    std::vector<uint8_t> rgbaExcpectedBuffer;
    fileReaderWriter.readFileRaw("tests/inputs/input.yuyv", yuyvBuffer);
    fileReaderWriter.readFileRaw("tests/expected/yuyv.rgba", rgbaExcpectedBuffer);

    G2dPixelFormatConverterStatus result = converter.convertImage(
        OrqaG2dFormat::FMT_YUYV, 
        OrqaG2dFormat::FMT_RGBA8888, 
        yuyvBuffer, 
        rgbaBuffer, 
        640, 
        480,
        300,
        300
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

int main() {
    std::vector<std::function<TestStatus()>> tests = {
        YUYVToRGBAConversionTest,
        I420ToRGBAConversionTest,
        NV12ToRGBAConversionTest,
        NV21ToRGBAConversionTest,
        UYVYToRGBAConversionTest,
        YV12ToRGBAConversionTest,
        YVYUToRGBAConversionTest,
        YUYVToRGBAConversionTestWithResize
    };

    for (size_t i = 0; i < tests.size(); i++) {
        TestStatus result = tests[i]();
        if (result == TestStatus::PASS) {
            std::cout << "Test " << i+1 << " passed" << "\n";
        }
        else if (result == TestStatus::GENERAL_TEST_FAILURE) {
            std::cout << "Test " << i+1 << " failed with general test failure" << "\n";
            return -1;
        }
        else if(result == TestStatus::INCORRECT_RESULT_FAILURE) {
            std::cout << "Test " << i+1 << " failed" << "\n";
            return -1;
        }
    }
    
    std::cout << "All tests passed" << "\n";
    return 0;
}