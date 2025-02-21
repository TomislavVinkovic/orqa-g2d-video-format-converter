#pragma once

#include <g2d.h>
#include <vector>
#include <string>
#include <unordered_map>
#include <optional>

#include "G2dFormatMetadata.hpp"


enum class ORQA_G2D_FORMAT {
    G2D_RGB565 = 0,
    G2D_RGBA8888,
    G2D_RGBX8888,
    G2D_ARGB8888,
    G2D_XRGB8888,
    G2D_RGB888,
    G2D_RGBA5551,
    G2D_RGBX5551,
    G2D_NV12,
    G2D_I420,
    G2D_YV12,
    G2D_NV21,
    G2D_YUYV,
    G2D_YVYU,
    G2D_UYVY,
    G2D_VYUY,
    G2D_NV16,
    G2D_NV61,
};

/// @brief A class that handles pixel format conversion using GPU acceleration
/// This class provides functionality to convert between various pixel formats
/// including RGB and YUV color spaces using the G2D hardware accelerator
class G2dPixelFormatConverter {
private:
    /// @brief Converts a format string to its corresponding G2D format metadata
    /// @param format String representation of the pixel format (e.g., "RGB565", "NV12")
    /// @return Optional containing G2dFormatMetadata if format is valid, empty optional otherwise
    std::optional<G2dFormatMetadata> convertFormatAliasToG2dFormat(ORQA_G2D_FORMAT format);
    
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

    /// @brief Verifies if conversion between two formats is supported
    /// @param srcFormat Source G2D format enumeration
    /// @param destFormat Destination G2D format enumeration
    /// @return 0 if conversion is supported, -1 otherwise
    int checkFormatSupport(g2d_format srcFormat, g2d_format destFormat);

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

    /// @brief Lists all supported pixel formats
    void listAllFormats();
};


/// @brief Mapping of format strings to their corresponding G2D format and bits per pixel
static const std::unordered_map<ORQA_G2D_FORMAT, G2dFormatMetadata> formatMap = {
    {ORQA_G2D_FORMAT::G2D_RGB565, {G2D_RGB565, 16}},
    {ORQA_G2D_FORMAT::G2D_RGBA8888, {G2D_RGBA8888, 32}},
    {ORQA_G2D_FORMAT::G2D_RGBX8888, {G2D_RGBX8888, 32}},
    {ORQA_G2D_FORMAT::G2D_ARGB8888, {G2D_ARGB8888, 32}},
    {ORQA_G2D_FORMAT::G2D_XRGB8888, {G2D_XRGB8888, 32}},
    {ORQA_G2D_FORMAT::G2D_RGB888, {G2D_RGB888, 24}},
    {ORQA_G2D_FORMAT::G2D_RGBA5551, {G2D_RGBA5551, 16}},
    {ORQA_G2D_FORMAT::G2D_RGBX5551, {G2D_RGBX5551, 16}},
    {ORQA_G2D_FORMAT::G2D_NV12, {G2D_NV12, 12}},
    {ORQA_G2D_FORMAT::G2D_I420, {G2D_I420, 12}},
    {ORQA_G2D_FORMAT::G2D_YV12, {G2D_YV12, 12}},
    {ORQA_G2D_FORMAT::G2D_NV21, {G2D_NV21, 12}},
    {ORQA_G2D_FORMAT::G2D_YUYV, {G2D_YUYV, 16}},
    {ORQA_G2D_FORMAT::G2D_YVYU, {G2D_YVYU, 16}},
    {ORQA_G2D_FORMAT::G2D_UYVY, {G2D_UYVY, 16}},
    {ORQA_G2D_FORMAT::G2D_VYUY, {G2D_VYUY, 16}},
    {ORQA_G2D_FORMAT::G2D_NV16, {G2D_NV16, 16}},
    {ORQA_G2D_FORMAT::G2D_NV61, {G2D_NV61, 16}},
};

static const std::unordered_map<std::string, ORQA_G2D_FORMAT> stringToG2DFormatMap = {
    {"RGB565", ORQA_G2D_FORMAT::G2D_RGB565},
    {"RGBA8888", ORQA_G2D_FORMAT::G2D_RGBA8888},
    {"RGBX8888", ORQA_G2D_FORMAT::G2D_RGBX8888},
    {"ARGB8888", ORQA_G2D_FORMAT::G2D_ARGB8888},
    {"XRGB8888", ORQA_G2D_FORMAT::G2D_XRGB8888},
    {"RGB888", ORQA_G2D_FORMAT::G2D_RGB888},
    {"RGBA5551", ORQA_G2D_FORMAT::G2D_RGBA5551},
    {"RGBX5551", ORQA_G2D_FORMAT::G2D_RGBX5551},
    {"NV12", ORQA_G2D_FORMAT::G2D_NV12},
    {"I420", ORQA_G2D_FORMAT::G2D_I420},
    {"YV12", ORQA_G2D_FORMAT::G2D_YV12},
    {"NV21", ORQA_G2D_FORMAT::G2D_NV21},
    {"YUYV", ORQA_G2D_FORMAT::G2D_YUYV},
    {"YVYU", ORQA_G2D_FORMAT::G2D_YVYU},
    {"UYVY", ORQA_G2D_FORMAT::G2D_UYVY},
    {"VYUY", ORQA_G2D_FORMAT::G2D_VYUY},
    {"NV16", ORQA_G2D_FORMAT::G2D_NV16},
    {"NV61", ORQA_G2D_FORMAT::G2D_NV61},
};

/// @brief List of supported format conversion pairs. 
/// Each pair represents a valid source->destination format conversion
/// that is supported by the G2D hardware
const static std::vector<std::pair<g2d_format, g2d_format>> formatCompatibilityMap = {
    // YUYV -> YUYV format conversions
    {G2D_NV12, G2D_YUYV},
    {G2D_I420, G2D_YUYV},
    {G2D_YV12, G2D_YUYV},
    {G2D_NV21, G2D_YUYV},
    {G2D_YUYV, G2D_NV12},
    {G2D_YUYV, G2D_NV21},
    {G2D_YUYV, G2D_NV16},
    {G2D_YUYV, G2D_NV61},
    {G2D_YVYU, G2D_YUYV},
    {G2D_UYVY, G2D_YUYV},
    {G2D_VYUY, G2D_YUYV},
    {G2D_NV16, G2D_YUYV},
    {G2D_NV61, G2D_YUYV},


    // RGBs format conversions
    {G2D_RGBA8888, G2D_YUYV},
    {G2D_RGBX8888, G2D_YUYV},
    {G2D_ARGB8888, G2D_YUYV},
    {G2D_XRGB8888, G2D_YUYV},
    {G2D_RGBA5551, G2D_YUYV},
    {G2D_RGBX5551, G2D_YUYV},

    {G2D_NV12, G2D_RGB565},
    {G2D_NV12, G2D_RGBA8888},
    {G2D_NV12, G2D_RGBX8888},
    {G2D_NV12, G2D_ARGB8888},
    {G2D_NV12, G2D_XRGB8888},
    {G2D_NV12, G2D_RGBA5551},
    {G2D_NV12, G2D_RGBX5551},

    {G2D_I420, G2D_RGB565},
    {G2D_I420, G2D_RGBA8888},
    {G2D_I420, G2D_RGBX8888},


    // RGBs format conversions
    {G2D_RGBA8888, G2D_YUYV},
    {G2D_RGBX8888, G2D_YUYV},
    {G2D_ARGB8888, G2D_YUYV},
    {G2D_XRGB8888, G2D_YUYV},
    {G2D_RGBA5551, G2D_YUYV},
    {G2D_RGBX5551, G2D_YUYV},

    {G2D_NV12, G2D_RGB565},
    {G2D_NV12, G2D_RGBA8888},
    {G2D_NV12, G2D_RGBX8888},
    {G2D_NV12, G2D_ARGB8888},
    {G2D_I420, G2D_ARGB8888},
    {G2D_I420, G2D_XRGB8888},
    {G2D_I420, G2D_RGBA5551},
    {G2D_I420, G2D_RGBX5551},

    {G2D_YV12, G2D_RGB565},
    {G2D_YV12, G2D_RGBA8888},
    {G2D_YV12, G2D_RGBX8888},
    {G2D_YV12, G2D_ARGB8888},
    {G2D_YV12, G2D_XRGB8888},
    {G2D_YV12, G2D_RGBA5551},
    {G2D_YV12, G2D_RGBX5551},

    {G2D_NV21, G2D_RGB565},
    {G2D_NV21, G2D_RGBA8888},
    {G2D_NV21, G2D_RGBX8888},
    {G2D_NV21, G2D_ARGB8888},
    {G2D_NV21, G2D_XRGB8888},
    {G2D_NV21, G2D_RGBA5551},
    {G2D_NV21, G2D_RGBX5551},

    {G2D_YUYV, G2D_RGB565},
    {G2D_YUYV, G2D_RGBA8888},
    {G2D_YUYV, G2D_RGBX8888},
    {G2D_YUYV, G2D_ARGB8888},
    {G2D_YUYV, G2D_XRGB8888},
    {G2D_YUYV, G2D_RGBA5551},
    {G2D_YUYV, G2D_RGBX5551},
    {G2D_YUYV, G2D_RGB888},

    {G2D_YVYU, G2D_RGB565},
    {G2D_YVYU, G2D_RGBA8888},
    {G2D_YVYU, G2D_RGBX8888},
    {G2D_YVYU, G2D_ARGB8888},
    {G2D_YVYU, G2D_XRGB8888},
    {G2D_YVYU, G2D_RGBA5551},
    {G2D_YVYU, G2D_RGBX5551},

    {G2D_UYVY, G2D_RGB565},
    {G2D_UYVY, G2D_RGBA8888},
    {G2D_UYVY, G2D_RGBX8888},
    {G2D_UYVY, G2D_ARGB8888},
    {G2D_UYVY, G2D_XRGB8888},
    {G2D_UYVY, G2D_RGBA5551},
    {G2D_UYVY, G2D_RGBX5551},

    {G2D_VYUY, G2D_RGB565},
    {G2D_VYUY, G2D_RGBA8888},
    {G2D_VYUY, G2D_RGBX8888},
    {G2D_VYUY, G2D_ARGB8888},
    {G2D_VYUY, G2D_XRGB8888},
    {G2D_VYUY, G2D_RGBA5551},
    {G2D_VYUY, G2D_RGBX5551},
};