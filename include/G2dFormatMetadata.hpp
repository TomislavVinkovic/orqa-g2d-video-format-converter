#pragma once

#include <g2d.h>
#include <cstddef>

/// @brief Metadata structure for G2D pixel formats
/// Contains information about a G2D pixel format including the format enum
/// and the number of bits per pixel. This structure is used to associate
/// additional information with G2D format enumerations.
struct G2dFormatMetadata
{
    /// @brief The G2D format enumeration value
    g2d_format format;

    /// @brief Number of bits per pixel for this format
    /// @details Used for buffer size calculations and format conversions
    size_t bpp; // bits per pixel

    /// @brief Constructor for G2dFormatMetadata
    /// @param format The G2D format enumeration value
    /// @param bpp Number of bits per pixel for this format
    G2dFormatMetadata(g2d_format format, size_t bpp)
        : format(format), bpp(bpp) {}
};