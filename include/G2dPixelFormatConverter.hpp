#pragma once

#include <g2d.h>
#include <optional>

#include "G2dFormatMetadata.hpp"
#include "formats.hpp"

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
        /// @return 0 on success, -1 on failure
        int setSourceFormatSurface(
            g2d_format format,
            struct g2d_surface& surface,
            g2d_buf* buf,
            size_t width,
            size_t height
        );

        /// @brief Configures the destination surface for G2D operations
        /// @param format G2D format enumeration for the destination
        /// @param surface Reference to the G2D surface structure to be configured
        /// @param buf Pointer to the G2D buffer for output
        /// @param width Width of the image in pixels
        /// @param height Height of the image in pixels
        /// @return 0 on success, -1 on failure
        int setDestinationFormatSurface(
            g2d_format format,
            struct g2d_surface& surface,
            g2d_buf* buf,
            size_t width,
            size_t height
        );

    public:        
        /// @brief Converts an image from one pixel format to another using G2D hardware
        /// @param srcFormat String representation of source format (e.g., "RGB565", "NV12")
        /// @param destFormat String representation of destination format
        /// @param srcBuffer Vector containing source image data
        /// @param destBuffer Vector to store converted image data (will be resized as needed)
        /// @param width Width of the image in pixels
        /// @param height Height of the image in pixels
        /// @return 0 on successful conversion, -1 on failure
        int convertImage(
            ORQA_G2D_FORMAT srcFormat,
            ORQA_G2D_FORMAT destFormat,
            const std::vector<uint8_t>& srcBuffer,
            std::vector<uint8_t>& destBuffer,
            size_t width,
            size_t height
        );
};