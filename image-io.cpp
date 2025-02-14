#include "include/image-io.hpp"
#include <span>

int writeImageRaw (
    const std::string& filename, 
    const std::span<uint8_t> buffer
) {
    std::ofstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return -1;
    }

    file.write(
        reinterpret_cast<const char*>(buffer.data()), 
        buffer.size()
    );
    file.flush();
    file.close();

    return 0;
}

int readImageRaw (
    const std::string& filename, 
    std::vector<uint8_t>& buffer
) {
    std::ifstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return -1;
    }

    file.seekg(0, std::ios::end);
    int size = file.tellg();
    file.seekg(0, std::ios::beg);

    buffer.clear();
    buffer.resize(size);

    file.read(
        reinterpret_cast<char*>(buffer.data()), 
        size
    );
    file.close();

    return 0;
}