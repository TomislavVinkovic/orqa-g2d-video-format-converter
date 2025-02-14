#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <span>
#include <fstream>

/// @brief Read a raw yuyv image file
/// @param filename yuyv image dest
/// @param yuyv buffer to fill with the image data
/// @return 0 on success, -1 on failure
int readImageRaw(
    const std::string& filename, 
    std::vector<uint8_t>& buffer
);


/// @brief Write a raw yuyv image file
/// @param filename yuyv image dest
/// @param rgb image data buffer
/// @return 0 on success, -1 on failure
int writeImageRaw(
    const std::string& filename, 
    const std::span<uint8_t> buffer
);