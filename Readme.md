# G2D Pixel Format Converter

## Overview
The **G2D Pixel Format Converter** is a command-line tool for converting images between different pixel formats using GPU acceleration via the **G2D API**. The program supports listing available formats, performing image format conversions, and running tests to verify functionality.

## Installation
Ensure you have the necessary dependencies installed, including **G2D library**, C++20 support, and any required image processing utilities. Compile the program using:

```sh
make
```

The compiled binary will be available in the `build/` directory.

## Usage
The program supports three main commands:

### Listing Supported Formats
To list all available pixel formats:
```sh
./g2dconvert formats
```

### Converting an Image
To convert an image from one format to another:
```sh
./g2dconvert convert <format_src> <format_dest> <src> <dest> <width> <height>
```

#### Parameters:
- `<format_src>`  - Source image format (e.g., `YUYV`, `NV12`, `I420`)
- `<format_dest>` - Destination image format (e.g., `RGBA8888`, `RGB565`)
- `<src>`         - Path to the input image file
- `<dest>`        - Path to the output image file
- `<width>`       - Image width in pixels
- `<height>`      - Image height in pixels

#### Example:
```sh
./g2dconvert convert YUYV RGBA8888 input.yuyv output.rgba 640 480
```

### Running Tests
To execute all conversion tests:
```sh
./g2dconvert test
```
This runs predefined test cases to validate the conversion functions.

## Implementation Details
- Uses **G2D API** for hardware-accelerated pixel format conversion.
- Supports multiple input formats such as **YUYV, NV12, I420, and YV12**.
- Reads and writes raw image buffers for conversion.
- Includes a **test suite** for verifying conversions.

## Notes
- Some conversions may not be fully supported or may produce unexpected results.
- Error handling is in place for missing files or unsupported formats.
- The test suite ensures correctness by comparing converted outputs with expected results.

