#include "FileReaderWriter.hpp"
#include <span>

FileReaderWriterStatus FileReaderWriter::writeFileRaw (
    const std::string& filename, 
    std::span<const uint8_t> buffer
) {
    std::ofstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << "\n";
        return FileReaderWriterStatus::FILE_OPEN_FAILURE;
    }

    file.write(
        reinterpret_cast<const char*>(buffer.data()), 
        static_cast<std::streamsize>(buffer.size())
    );
    file.flush();
    file.close();

    return FileReaderWriterStatus::SUCCESS;
}

FileReaderWriterStatus FileReaderWriter::readFileRaw (
    const std::string& filename, 
    std::vector<uint8_t>& buffer
) {
    std::ifstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << "\n";
        return FileReaderWriterStatus::FILE_OPEN_FAILURE;
    }

    file.seekg(0, std::ios::end);
    const std::streampos size = file.tellg();
    file.seekg(0, std::ios::beg);

    buffer.clear();
    buffer.resize(size);

    file.read(
        reinterpret_cast<char*>(buffer.data()), 
        static_cast<std::streamsize>(size)
    );
    file.close();

    return FileReaderWriterStatus::SUCCESS;
}