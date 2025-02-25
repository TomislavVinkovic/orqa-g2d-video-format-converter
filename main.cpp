#include "include/G2dPixelFormatConverter.hpp"
#include "include/runtime.hpp"
#include <iostream>
#include <functional>

int main(int argc, char const *argv[])
{
    // Main issue: on every conversion except YUYV to RGB888, the program will 
    // write all zeroes to the buffer
    // TODO: Better help text
    if(argc < 2) {
        std::cout << "Usage: "
            << argv[0] << " <command>" 
            << std::endl;
        return -1;
    }
    std::string command = argv[1];

    RuntimeStatus status;

    if(command == "formats") {
        status = listAllFormats();
    } else if(command == "convert") {
        status = convert(argc, argv);
    } else if(command == "test") {
        status = test();
    }else {
        std::cout << "Invalid command" << std::endl;
        return EXIT_FAILURE;
    }

    if(status != RuntimeStatus::SUCCESS) {
        std::cout << "Command failed" << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
