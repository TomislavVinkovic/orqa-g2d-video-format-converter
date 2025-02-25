#include "include/G2dPixelFormatConverter.hpp"
#include "include/G2dFormatManager.hpp"

#include <cstring>
#include <iostream>
#include <algorithm>

G2dPixelFormatConverterStatus G2dPixelFormatConverter::convertImage(
    ORQA_G2D_FORMAT srcFormat,
    ORQA_G2D_FORMAT destFormat,
    const std::vector<uint8_t>& srcBuffer,
    std::vector<uint8_t>& destBuffer,
    size_t width,
    size_t height
)
{
    std::optional<G2dFormatMetadata> srcG2dFormat = G2dFormatManager::getFormatMetadata(srcFormat);
    std::optional<G2dFormatMetadata> destG2dFormat = G2dFormatManager::getFormatMetadata(destFormat);
    if(!srcG2dFormat.has_value() || !destG2dFormat.has_value()) {
        std::cerr << "Invalid source or destination format" << std::endl;
        return G2dPixelFormatConverterStatus::INVALID_FORMAT_ERROR;
    }

    if(
        G2dFormatManager::isFormatConversionSupported(srcG2dFormat->format, destG2dFormat->format) 
            != FormatManagerStatus::SUCCESS
    ) {
        std::cerr << "Image conversion failed due to unsupported format pair." << std::endl;
        return G2dPixelFormatConverterStatus::UNSUPPORTED_CONVERSION_ERROR;
    }

    void* handle;
    struct g2d_surface srcSurface, destSurface;

    // set up the src buffer on the GPU
    g2d_buf* srcG2dBuf = g2d_alloc(srcBuffer.size(), 0);
    std::memcpy(srcG2dBuf->buf_vaddr, srcBuffer.data(), srcBuffer.size());

    // reserve space for the destination buffer
    destBuffer.resize(
        width * height * static_cast<size_t>(destG2dFormat->bpp / 8), 
        0
    );

    // set up the dest buffer on the GPU
    g2d_buf* destG2dBuf = g2d_alloc(destBuffer.size(), 0);

    if(g2d_open(&handle) < 0) {
        std::cerr << "Failed to open the video accelerator" << std::endl;
        return G2dPixelFormatConverterStatus::DEVICE_ERROR;
    }

    if(setSourceFormatSurface(srcG2dFormat->format, srcSurface, srcG2dBuf, width, height) != G2dPixelFormatConverterStatus::SUCCESS) {
        std::cerr << "Failed to set source surface" << std::endl;
        return G2dPixelFormatConverterStatus::SURFACE_ERROR;
    }
    if(setDestinationFormatSurface(destG2dFormat->format, destSurface, destG2dBuf, width, height) != G2dPixelFormatConverterStatus::SUCCESS) {
        std::cerr << "Failed to set destination surface" << std::endl;
        return G2dPixelFormatConverterStatus::SURFACE_ERROR;
    }

    if(g2d_blit(handle, &srcSurface, &destSurface) < 0) {
        std::cerr << "This type of conversion is currently not supported" << std::endl;
        return G2dPixelFormatConverterStatus::GENERAL_CONVERSION_ERROR;
    }
    if(g2d_finish(handle) < 0) {
        std::cerr << "Failed to finish the g2d operation" << std::endl;
        return G2dPixelFormatConverterStatus::FINISH_OPERATION_ERROR;
    }
    g2d_flush(handle);

    // copy the rgb buffer on the GPU to main memory
    std::memcpy(destBuffer.data(), destG2dBuf->buf_vaddr, destBuffer.size());
 
    // clean up
    if(g2d_free(srcG2dBuf) < 0 || g2d_free(destG2dBuf) < 0) {
        std::cerr << "Failed to free buffers" << std::endl;
        return G2dPixelFormatConverterStatus::MEMORY_DEALLOCATION_ERROR;
    }

    if(g2d_close(handle) < 0) { 
        std::cerr << "Failed to close the video accelerator" << std::endl;
        return G2dPixelFormatConverterStatus::DEVICE_ERROR;
    }

    return G2dPixelFormatConverterStatus::SUCCESS;
}

G2dPixelFormatConverterStatus G2dPixelFormatConverter::setSourceFormatSurface(
    g2d_format format,
    struct g2d_surface& surface,
    g2d_buf* buf,
    size_t width,
    size_t height
)
{
    surface.left = 0;
    surface.top = 0;
    surface.right = width;
    surface.width = width;
    surface.height = height;
    surface.rot = G2D_ROTATION_0;
    surface.format = format;

    // YUV FORMATS
    if(
        format == G2D_YUYV ||
        format == G2D_YVYU ||
        format == G2D_UYVY ||
        format == G2D_VYUY // This is the only one not tested
    ) {
        surface.planes[0] = buf->buf_paddr;
        surface.bottom = height / 2;
        surface.stride = width * 2;
    }
    else if(
        format == G2D_NV12 ||
        format == G2D_NV21
    ) {
        surface.planes[0] = buf->buf_paddr;
        surface.planes[1] = buf->buf_paddr + (width * height);
        surface.bottom = height;
        surface.stride = width;
    }
    else if(
        format == G2D_I420 ||
        format == G2D_YV12
    ) {
        surface.planes[0] = buf->buf_paddr;
        surface.planes[1] = buf->buf_paddr + (width * height);
        surface.planes[2] = buf->buf_paddr + (width * height) + ((width * height) / 4);
        surface.bottom = height;
        surface.stride = width;
    }

    // RGB FORMATS
    else if(
        format == G2D_RGBA8888 || 
        format == G2D_XRGB8888 || 
        format == G2D_RGBX8888 ||
        format == G2D_ARGB8888 ||
        format == G2D_RGBA5551 
    ) {
        surface.planes[0] = buf->buf_paddr;
        surface.bottom = height;
        surface.stride = width;
    }
    else {
        std::cerr << "Unsupported format" << std::endl;
        return G2dPixelFormatConverterStatus::UNSUPPORTED_SOURCE_FORMAT_ERROR;
    }

    return G2dPixelFormatConverterStatus::SUCCESS;
}

G2dPixelFormatConverterStatus G2dPixelFormatConverter::setDestinationFormatSurface(
    g2d_format format,
    struct g2d_surface& surface,
    g2d_buf* buf,
    size_t width,
    size_t height
)
{
    surface.left = 0;
    surface.top = 0;
    surface.right = width;
    surface.width = width;
    surface.height = height;
    surface.rot = G2D_ROTATION_0;
    surface.format = format;

    // YUV FORMATS
    if(format == G2D_YUYV) {
        surface.planes[0] = buf->buf_paddr;
        surface.bottom = height / 2;
        surface.stride = width * 2;
    }


    else if(
        format == G2D_NV12 ||
        format == G2D_NV21
    ) {
        surface.planes[0] = buf->buf_paddr;
        surface.planes[1] = buf->buf_paddr + (width * height);
        surface.bottom = height;
        surface.stride = width;
    }


    else if(
        format == G2D_I420 ||
        format == G2D_YV12
    ) {
        surface.planes[0] = buf->buf_paddr;
        surface.planes[1] = buf->buf_paddr + (width * height);
        surface.planes[2] = buf->buf_paddr + (width * height) + ((width * height) / 4);
        surface.bottom = height;
        surface.stride = width;
    }

    // RGB FORMATS
    else if(
        format == G2D_RGB888 || 
        format == G2D_RGBA8888 || 
        format == G2D_XRGB8888 || 
        format == G2D_RGBA5551 || 
        format == G2D_RGBX5551 || 
        format == G2D_RGB565 ||
        format == G2D_RGBX8888 ||
        format == G2D_ARGB8888
    ) {
        surface.planes[0] = buf->buf_paddr;
        surface.bottom = height;
        surface.stride = width;
    }
    else {
        std::cerr << "Unsupported format" << std::endl;
        return G2dPixelFormatConverterStatus::UNSUPPORTED_DESTINATION_FORMAT_ERROR;
    }

    return G2dPixelFormatConverterStatus::SUCCESS;
}