#include "include/runtime.hpp"
#include "include/FileReaderWriter.hpp"
#include "include/G2dPixelFormatConverter.hpp"
#include "include/G2dFormatManager.hpp"
#include "include/G2dFormatMetadata.hpp"
#include "tests/include/G2dConvertTestSuite.hpp"

#include <iostream>
#include <unordered_map>
#include <string>
#include <g2d.h>

RuntimeStatus convert(int argc, char const *argv[]) {
    if(argc < 8) {
        std::cout << "Usage: "
            << argv[0] << " convert <format_src> <format_dest> <src> <dest> <width> <height>" 
            << std::endl;
        return RuntimeStatus::FAILURE;
    }

    std::string formatSrc = argv[2];
    std::string formatDest = argv[3];
    std::string src = argv[4];
    std::string dest = argv[5];
    size_t width = std::stoi(argv[6]);
    size_t height = std::stoi(argv[7]);

    G2dPixelFormatConverter g2dPixelFormatConverter;

    // Step 1: check if the specified formats exist
    std::optional<ORQA_G2D_FORMAT> formatSrcEnum, formatDestEnum;
    formatSrcEnum = G2dFormatManager::getFormatEnumFromString(formatSrc);
    formatDestEnum = G2dFormatManager::getFormatEnumFromString(formatDest);

    if(!formatSrcEnum.has_value() || !formatDestEnum.has_value()) {
        std::cerr << "Invalid source or destination format" << std::endl;
        return RuntimeStatus::FAILURE;
    }

    FileReaderWriter fileReaderWriter;
    // Step 2: read source image
    std::vector<uint8_t> srcBuffer, destBuffer;
    if(fileReaderWriter.readFileRaw(src, srcBuffer) != FileReaderWriterStatus::SUCCESS) {
        std::cerr << "Failed to read source image" << std::endl;
        return RuntimeStatus::FAILURE;
    }

    // Step 3: convert the image
    if(g2dPixelFormatConverter.convertImage(
        *formatSrcEnum, // we know for certain that it contains a value because of the check above
        *formatDestEnum,
        srcBuffer, 
        destBuffer, 
        width, 
        height
    ) != G2dPixelFormatConverterStatus::SUCCESS) {
        std::cerr << "Failed to convert the image on the GPU" << std::endl;
        return RuntimeStatus::FAILURE;
    }

    // Step 4: write the image
    if(fileReaderWriter.writeFileRaw(dest, destBuffer) != FileReaderWriterStatus::SUCCESS) {
        std::cerr << "Failed to write the destination image" << std::endl;
        return RuntimeStatus::FAILURE;
    }

    return RuntimeStatus::SUCCESS;
}

RuntimeStatus listAllFormats() {
    for(auto& [key, value] : ORQA_FORMAT_LOOKUP) {
        std::cout << key << std::endl;
    }

    return RuntimeStatus::SUCCESS;
}

RuntimeStatus test() {
    G2dConvertTestSuite testSuite;
    if(testSuite.runAllTests() != G2dConvertTestSuiteStatus::SUCCESS) {
        std::cerr << "Some tests failed to complete" << std::endl;
        return RuntimeStatus::FAILURE;
    }

    return RuntimeStatus::SUCCESS;
}