#pragma once

#include <g2d.h>
#include <unordered_map>
#include <string>
#include <optional>
#include "formats.hpp"

#include "G2dFormatMetadata.hpp"

enum class FormatManagerStatus {
    SUCCESS = 0,
    CONVERSION_NOT_SUPPORTED_ERROR = -1
};

class G2dFormatManager {
    public:
        G2dFormatManager() = delete;

        /// @brief Gets the OrqaG2dFormat enum from a format string
        /// @param formatStr The string representation of the format (e.g., "RGB565", "NV12")
        /// @return Optional containing OrqaG2dFormat if found, empty optional otherwise
        static std::optional<OrqaG2dFormat> getFormatEnumFromString(const std::string& formatStr);

        /// @brief Gets the G2D format and bits-per-pixel from an OrqaG2dFormat enum
        /// @param format OrqaG2dFormat enum value
        /// @return Optional containing G2dFormatMetadata if found, empty optional otherwise
        static std::optional<G2dFormatMetadata> getFormatMetadata(OrqaG2dFormat format);

        /// @brief Checks if conversion between two formats is supported
        /// @param srcFormat Source G2D format
        /// @param destFormat Destination G2D format
        /// @return FormatManagerStatus::SUCCESS if conversion is supported, FormatManagerStatus::CONVERSION_NOT_SUPPORTED_ERROR otherwise
        static FormatManagerStatus isFormatConversionSupported(g2d_format srcFormat, g2d_format destFormat);

        /// @brief Lists all supported pixel formats
        static void listAllFormats();
};