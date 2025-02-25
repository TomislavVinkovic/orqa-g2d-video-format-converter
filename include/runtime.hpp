// runtime.hpp
#pragma once

enum class RuntimeStatus {
    SUCCESS,
    FAILURE
};

/// @brief Converts an image from one pixel format to another
/// Command line interface for image format conversion. Expects arguments in the following order:
/// convert <source_format> <dest_format> <source_file> <dest_file> <width> <height>
/// @param argc Number of command line arguments
/// @param argv Array of command line arguments
/// @return 0 on success, -1 on failure
RuntimeStatus convert(int argc, char const *argv[]);

/// @brief Lists all supported pixel formats
/// @details Prints all available pixel format names that can be used for conversion to the terminal
/// @return 0 on success, -1 on failure
RuntimeStatus listAllFormats();

/// @brief Runs the test suite
/// @return 0 on all tests passed, -1 on test failure
RuntimeStatus test();