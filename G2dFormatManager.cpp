#include "include/G2dFormatManager.hpp"
#include <iostream>

std::optional<ORQA_G2D_FORMAT> G2dFormatManager::getFormatEnumFromString(const std::string& formatStr) {
    if(ORQA_FORMAT_LOOKUP.find(formatStr) != ORQA_FORMAT_LOOKUP.end()) {
        return ORQA_FORMAT_LOOKUP.at(formatStr);
    } else {
        return {};
    }
}

std::optional<G2dFormatMetadata> G2dFormatManager::getFormatMetadata(ORQA_G2D_FORMAT format) {
    if(ORQA_TO_G2D_FORMAT_MAP.find(format) != ORQA_TO_G2D_FORMAT_MAP.end()) {
        return ORQA_TO_G2D_FORMAT_MAP.at(format);
    } else {
        return {};
    }
}

bool G2dFormatManager::isFormatConversionSupported(g2d_format srcFormat, g2d_format destFormat) {
    return 
        std::find(
            G2D_FORMAT_COMPATIBILITY_LIST.begin(), 
            G2D_FORMAT_COMPATIBILITY_LIST.end(), 
            std::make_pair(srcFormat, destFormat)
        ) != G2D_FORMAT_COMPATIBILITY_LIST.end();
}

void G2dFormatManager::listAllFormats() {
    for(const auto& [alias, orqaFormat] : ORQA_FORMAT_LOOKUP) {
        std::cout << alias << std::endl;
    }
}