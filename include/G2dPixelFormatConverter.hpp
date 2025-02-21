#pragma once

#include <g2d.h>
#include <vector>
#include <string>
#include <unordered_map>
#include <optional>

#include "G2dFormatMetadata.hpp"

// TODO: Put this class in a namespace

class G2dPixelFormatConverter {

    std::optional<G2dFormatMetadata> convertFormatAliasToG2dFormat(const std::string& format);
    
    int setSourceFormatSurface(
        g2d_format format,
        struct g2d_surface& surface,
        g2d_buf* buf,
        size_t width,
        size_t height
    );
    int setDestinationFormatSurface(
        g2d_format format,
        struct g2d_surface& surface,
        g2d_buf* buf,
        size_t width,
        size_t height
    );
    int checkFormatSupport(g2d_format srcFormat, g2d_format destFormat);

    public:        
        int convertImage(
            const std::string& srcFormat,
            const std::string& destFormat,
            const std::vector<uint8_t>& srcBuffer,
            std::vector<uint8_t>& destBuffer,
            size_t width,
            size_t height
        );
};

static const std::unordered_map<std::string, G2dFormatMetadata> formatMap = {
    {"RGB565", {G2D_RGB565, 16}},
    {"RGBA8888", {G2D_RGBA8888, 32}},
    {"RGBX8888", {G2D_RGBX8888, 32}},
    {"ARGB8888", {G2D_ARGB8888, 32}},
    {"XRGB8888", {G2D_XRGB8888, 32}},
    {"RGB888", {G2D_RGB888, 24}},
    {"RGBA5551", {G2D_RGBA5551, 16}},
    {"RGBX5551", {G2D_RGBX5551, 16}},
    // Assume that the resolution is even
    // TODO: Add rounding up support for odd resolutions
    {"NV12", {G2D_NV12, 12}},
    {"I420", {G2D_I420, 12}},
    {"YV12", {G2D_YV12, 12}},
    {"NV21", {G2D_NV21, 12}},
    {"YUYV", {G2D_YUYV, 16}},
    {"YVYU", {G2D_YVYU, 16}},
    {"UYVY", {G2D_UYVY, 16}},
    {"VYUY", {G2D_VYUY, 16}},
    {"NV16", {G2D_NV16, 16}},
    {"NV61", {G2D_NV61, 16}}
};

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

    {G2D_NV16, G2D_RGB565},
    {G2D_NV16, G2D_RGBA8888},
    {G2D_NV16, G2D_RGBX8888},
    {G2D_NV16, G2D_ARGB8888},
    {G2D_NV16, G2D_XRGB8888},
    {G2D_NV16, G2D_RGBA5551},
    {G2D_NV16, G2D_RGBX5551},

    {G2D_NV61, G2D_RGB565},
    {G2D_NV61, G2D_RGBA8888},
    {G2D_NV61, G2D_RGBX8888},
    {G2D_NV61, G2D_ARGB8888},
    {G2D_NV61, G2D_XRGB8888},
    {G2D_NV61, G2D_RGBA5551},
    {G2D_NV61, G2D_RGBX5551},
};