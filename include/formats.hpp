#pragma once

#include <vector>
#include <string>
#include <unordered_map>

#include "G2dFormatMetadata.hpp"

enum class OrqaG2dFormat {
    FMT_RGB565 = 0,
    FMT_RGBA8888,
    FMT_RGBX8888,
    FMT_ARGB8888,
    FMT_XRGB8888,
    FMT_RGB888,
    FMT_RGBA5551,
    FMT_RGBX5551,
    FMT_NV12,
    FMT_I420,
    FMT_YV12,
    FMT_NV21,
    FMT_YUYV,
    FMT_YVYU,
    FMT_UYVY,
    FMT_VYUY,
    FMT_NV16,
    FMT_NV61,
};

static const std::unordered_map<std::string, OrqaG2dFormat> OrqaFormatLookup = {
    {"RGB565", OrqaG2dFormat::FMT_RGB565},
    {"RGBA8888", OrqaG2dFormat::FMT_RGBA8888},
    {"RGBX8888", OrqaG2dFormat::FMT_RGBX8888},
    {"ARGB8888", OrqaG2dFormat::FMT_ARGB8888},
    {"XRGB8888", OrqaG2dFormat::FMT_XRGB8888},
    {"RGB888", OrqaG2dFormat::FMT_RGB888},
    {"RGBA5551", OrqaG2dFormat::FMT_RGBA5551},
    {"RGBX5551", OrqaG2dFormat::FMT_RGBX5551},
    {"NV12", OrqaG2dFormat::FMT_NV12},
    {"I420", OrqaG2dFormat::FMT_I420},
    {"YV12", OrqaG2dFormat::FMT_YV12},
    {"NV21", OrqaG2dFormat::FMT_NV21},
    {"YUYV", OrqaG2dFormat::FMT_YUYV},
    {"YVYU", OrqaG2dFormat::FMT_YVYU},
    {"UYVY", OrqaG2dFormat::FMT_UYVY},
    {"VYUY", OrqaG2dFormat::FMT_VYUY},
    {"NV16", OrqaG2dFormat::FMT_NV16},
    {"NV61", OrqaG2dFormat::FMT_NV61},
};

/// @brief Mapping of format strings to their corresponding G2D format and bits per pixel
static const std::unordered_map<OrqaG2dFormat, G2dFormatMetadata> OrqaToG2DFormatMap = {
    {OrqaG2dFormat::FMT_RGB565, {G2D_RGB565, 16}},
    {OrqaG2dFormat::FMT_RGBA8888, {G2D_RGBA8888, 32}},
    {OrqaG2dFormat::FMT_RGBX8888, {G2D_RGBX8888, 32}},
    {OrqaG2dFormat::FMT_ARGB8888, {G2D_ARGB8888, 32}},
    {OrqaG2dFormat::FMT_XRGB8888, {G2D_XRGB8888, 32}},
    {OrqaG2dFormat::FMT_RGB888, {G2D_RGB888, 24}},
    {OrqaG2dFormat::FMT_RGBA5551, {G2D_RGBA5551, 16}},
    {OrqaG2dFormat::FMT_RGBX5551, {G2D_RGBX5551, 16}},
    {OrqaG2dFormat::FMT_NV12, {G2D_NV12, 12}},
    {OrqaG2dFormat::FMT_I420, {G2D_I420, 12}},
    {OrqaG2dFormat::FMT_YV12, {G2D_YV12, 12}},
    {OrqaG2dFormat::FMT_NV21, {G2D_NV21, 12}},
    {OrqaG2dFormat::FMT_YUYV, {G2D_YUYV, 16}},
    {OrqaG2dFormat::FMT_YVYU, {G2D_YVYU, 16}},
    {OrqaG2dFormat::FMT_UYVY, {G2D_UYVY, 16}},
    {OrqaG2dFormat::FMT_VYUY, {G2D_VYUY, 16}},
    {OrqaG2dFormat::FMT_NV16, {G2D_NV16, 16}},
    {OrqaG2dFormat::FMT_NV61, {G2D_NV61, 16}},
};

/// @brief List of supported format conversion pairs. 
/// Each pair represents a valid source->destination format conversion
/// that is supported by the G2D hardware
const static std::vector<std::pair<g2d_format, g2d_format>> G2dFormatCompatibilityList = {
    // YUV -> YUV format conversions
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