#include "include/G2dPixelFormatConverter.hpp"
#include "include/runtime.hpp"
#include <iostream>
#include <functional>

int main(int argc, char const *argv[])
{
    // TODO: Better help text
    if(argc < 2) {
        std::cout << "Usage: "
            << argv[0] << " <command>" 
            << std::endl;
        return -1;
    }
    std::string command = argv[1];

    if(command == "formats") {
        return listAllFormats();
    } else if(command == "convert") {
        return convert(argc, argv);
    } else {
        std::cout << "Invalid command" << std::endl;
        return -1;
    }
}
