#include "include/runtime.hpp"
#include "include/image-io.hpp"
#include "include/G2dPixelFormatConverter.hpp"
#include "include/G2dFormatMetadata.hpp"
#include "tests/include/G2dConvertTestSuite.hpp"

#include <iostream>
#include <unordered_map>
#include <string>
#include <g2d.h>

int convert(int argc, char const *argv[]) {
    if(argc < 8) {
        std::cout << "Usage: "
            << argv[0] << " convert <format_src> <format_dest> <src> <dest> <width> <height>" 
            << std::endl;
        return -1;
    }

    std::string formatSrc = argv[2];
    std::string formatDest = argv[3];
    std::string src = argv[4];
    std::string dest = argv[5];
    size_t width = std::stoi(argv[6]);
    size_t height = std::stoi(argv[7]);

    G2dPixelFormatConverter g2dPixelFormatConverter;

    // Step 2: read source image
    std::vector<uint8_t> srcBuffer, destBuffer;
    if(readImageRaw(src, srcBuffer) < 0) {
        std::cerr << "Failed to read source image" << std::endl;
        return -1;
    }

    // TODO: Find 
    ORQA_G2D_FORMAT formatSrcEnum, formatDestEnum;
    if(stringToG2DFormatMap.find(formatSrc) == stringToG2DFormatMap.end()) {
        std::cerr << "Invalid source format" << std::endl;
        return -1;
    } else {
        formatSrcEnum = stringToG2DFormatMap.at(formatSrc);
    }

    if(stringToG2DFormatMap.find(formatDest) == stringToG2DFormatMap.end()) {
        std::cerr << "Invalid destination format" << std::endl;
        return -1;
    } else {
        formatDestEnum = stringToG2DFormatMap.at(formatDest);
    }

    // Step 3: convert the image
    if(g2dPixelFormatConverter.convertImage(
        formatSrcEnum,
        formatDestEnum,
        srcBuffer, 
        destBuffer, 
        width, 
        height
    ) < 0) {
        std::cerr << "Failed to convert the image on the GPU" << std::endl;
        return -1;
    }

    // Step 4: write the image
    if(writeImageRaw(dest, destBuffer) < 0) {
        std::cerr << "Failed to write the destination image" << std::endl;
        return -1;
    }

    return 0;
}

int listAllFormats() {
    for(auto& [key, value] : stringToG2DFormatMap) {
        std::cout << key << std::endl;
    }

    return 0;
}

int test() {
    G2dConvertTestSuite testSuite;
    if(testSuite.runAllTests() < 0) {
        std::cerr << "Some tests failed to complete" << std::endl;
        return -1;
    }

    return 0;
}