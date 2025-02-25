#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <span>
#include <fstream>

enum class FileReaderWriterStatus {
    SUCCESS,
    FILE_OPEN_FAILURE
};

class FileReaderWriter {
public:
    /// @brief Write a raw yuyv image file
    /// @param filename yuyv image dest
    /// @param rgb image data buffer
    /// @return 0 on success, -1 on failure
    FileReaderWriterStatus writeFileRaw(
        const std::string& filename, 
        const std::span<uint8_t> buffer
    );

    /// @brief Read a raw yuyv image file
    /// @param filename yuyv image dest
    /// @param yuyv buffer to fill with the image data
    /// @return 0 on success, -1 on failure
    FileReaderWriterStatus readFileRaw(
        const std::string& filename, 
        std::vector<uint8_t>& buffer
    );
};