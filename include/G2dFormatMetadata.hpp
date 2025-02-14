#pragma once

#include <g2d.h>
#include <cstddef>

struct G2dFormatMetadata
{
    g2d_format format;
    size_t bpp; // bits per pixel

    G2dFormatMetadata(g2d_format format, size_t bpp)
        : format(format), bpp(bpp) {}
};