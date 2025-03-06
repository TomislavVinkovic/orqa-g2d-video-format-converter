#pragma once

#include <g2d.h>
#include <optional>

#include "G2dFormatMetadata.hpp"
#include "formats.hpp"

enum class G2dPixelFormatConverterStatus {
    SUCCESS = 0,
    GENERAL_CONVERSION_ERROR = -1,
    FINISH_OPERATION_ERROR = -2,
    SURFACE_ERROR = -3,
    DEVICE_ERROR = -4,
    UNSUPPORTED_FORMAT_ERROR = -5,
    UNSUPPORTED_SOURCE_FORMAT_ERROR = -6,
    UNSUPPORTED_DESTINATION_FORMAT_ERROR = -7,
    MEMORY_DEALLOCATION_ERROR = -8,
    INVALID_FORMAT_ERROR = -9,
    UNSUPPORTED_CONVERSION_ERROR = -10,
};

/// @brief A class that handles pixel format conversion using GPU acceleration
/// This class provides functionality to convert between various pixel formats
/// including RGB and YUV color spaces using the G2D hardware accelerator
class G2dPixelFormatConverter {
    private:
        /// @brief Configures the source surface for G2D operations
        /// @param format G2D format enumeration for the source
        /// @param surface Reference to the G2D surface structure to be configured
        /// @param buf Pointer to the G2D buffer containing source data
        /// @param width Width of the image in pixels
        /// @param height Height of the image in pixels
        /// @return G2dPixelFormatConverterStatus::SUCCESS on success, G2dPixelFormatConverterStatus::UNSUPPORTED_SOURCE_FORMAT_ERROR on failure
        G2dPixelFormatConverterStatus setSourceFormatSurface(
            g2d_format format,
            struct g2d_surface& surface,
            g2d_buf* buf,
            int width,
            int height
        );

        /// @brief Configures the destination surface for G2D operations
        /// @param format G2D format enumeration for the destination
        /// @param surface Reference to the G2D surface structure to be configured
        /// @param buf Pointer to the G2D buffer for output
        /// @param width Width of the image in pixels
        /// @param height Height of the image in pixels
        /// @return G2dPixelFormatConverterStatus::SUCCESS on success, G2dPixelFormatConverterStatus::UNSUPPORTED_DESTINATION_FORMAT_ERROR on failure
        G2dPixelFormatConverterStatus setDestinationFormatSurface(
            g2d_format format,
            struct g2d_surface& surface,
            g2d_buf* buf,
            int width,
            int height
        );

    public:        
        /// @brief Converts an image from one pixel format to another using G2D hardware
        /// @param srcFormat String representation of source format (e.g., "RGB565", "NV12")
        /// @param destFormat String representation of destination format
        /// @param srcBuffer Vector containing source image data
        /// @param destBuffer Vector to store converted image data (will be resized as needed)
        /// @param srcWidth Width of the source image in pixels
        /// @param srcHeight Height of the source image in pixels
        /// @param destWidth Width of the destination image in pixels
        /// @param destHeight Height of the destination image in pixels
        /// @return SUCCESS on successful conversion, one of the errors defined
        /// in G2dPixelFormatConverterStatus on failure
        G2dPixelFormatConverterStatus convertImage(
            OrqaG2dFormat srcFormat,
            OrqaG2dFormat destFormat,
            const std::vector<uint8_t>& srcBuffer,
            std::vector<uint8_t>& destBuffer,
            size_t srcWidth,
            size_t srcHeight,
            size_t destWidth,
            size_t destHeight
        );
};