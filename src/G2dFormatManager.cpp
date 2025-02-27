#include "G2dFormatManager.hpp"
#include <iostream>

std::optional<OrqaG2dFormat> G2dFormatManager::getFormatEnumFromString(const std::string& formatStr) {
    if(OrqaFormatLookup.find(formatStr) == OrqaFormatLookup.end()) {
        return {};
    }
    return OrqaFormatLookup.at(formatStr);
    
}

std::optional<G2dFormatMetadata> G2dFormatManager::getFormatMetadata(OrqaG2dFormat format) {
    if(OrqaToG2DFormatMap.find(format) == OrqaToG2DFormatMap.end()) {
        return {};
        
    }
    return OrqaToG2DFormatMap.at(format);
}

FormatManagerStatus G2dFormatManager::isFormatConversionSupported(g2d_format srcFormat, g2d_format destFormat) {
    if(
        std::find(
            G2dFormatCompatibilityList.begin(), 
            G2dFormatCompatibilityList.end(), 
            std::make_pair(srcFormat, destFormat)
        ) == G2dFormatCompatibilityList.end()
    ) {
        std::cerr << "Unsupported format conversion" << "\n";
        return FormatManagerStatus::CONVERSION_NOT_SUPPORTED_ERROR;
    }
    return FormatManagerStatus::SUCCESS;
    
}

void G2dFormatManager::listAllFormats() {
    for(const auto& [alias, orqaFormat] : OrqaFormatLookup) {
        std::cout << alias << "\n";
    }
}