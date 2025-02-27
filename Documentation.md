
## Overview
The **G2D Pixel Format Converter** is a command-line tool and API for converting images between different pixel formats using GPU acceleration via the **G2D API**. The command line tool supports listing available formats, performing image format conversions, and running tests to verify functionality.
## Compilation
This software is developed using the C++ 20 standard. In order to compile it, you need to enable C++ 20 by using the following flag in your compiler
```c++
-std=c++20
```
You will also need to enable the following flag to enable G2D support
```c++
-lg2d
```
You can compile the entire application, along with the runtime and test suite, by using the provided Makefile.
## API documentation
### Class: G2dPixelFormatConverter
Handles image format conversions using G2d.
#### Constructors
The class only uses the default constructor. It can be instantiated as
```c++
G2dPixelFormatConverter converter;
```
#### Methods
##### `convertImage`
Converts the image from the source 

```c++
G2dPixelFormatConverterStatus convertImage (
	OrqaG2dFormat srcFormat,
	OrqaG2dFormat destFormat,
	const std::vector<uint8_t>& srcBuffer,
	std::vector<uint8_t>& destBuffer,
	size_t width,
	size_t height
)
```
**Parameters**:
- `srcFormat` - format of the source buffer
- `destFormat` - format of the destination buffer
- `srcBuffer` - A reference to a the buffer in which the raw source image data is located
- `destBuffer` - A reference to a the buffer to write the raw converted image data to
- `width` - image width
- `height` - image height
**Returns**: A `G2dPixelFormatConverterStatus` enum value, that describes the exact error that occured during runtime.

**Usage example**
```c++
G2dPixelFormatConverter converter;
G2dPixelFormatConverterStatus result = converter.convertImage(
	OrqaG2dFormat::FMT_YVYU,
	OrqaG2dFormat::FMT_RGBA8888,
	yvyuBuffer,
	rgbaBuffer,
	640,
	480
);
```

### Class: G2dFormatManager
Handles mapping our custom `OrqaG2dFormat` enum values to `G2D_FORMAT` enum values used by G2d, and mapping image format strings from the command line to our custom `OrqaG2dFormat` enum values.
#### Constructors
The class has all its constructors deleted. That is because all of its methods are static.
#### Methods
##### `getFormatEnumFromString`
Maps the image format string from the terminal to our custom `OrqaG2dFormat` values.

```c++
static std::optional<OrqaG2dFormat> getFormatEnumFromString(const std::string& formatStr);
```
**Parameters**
- `formatStr` - Format string key
**Returns**: An optional value that can be either an `OrqaG2dFormat` value or a `std::optional` empty value, which implies that the format string provided is not found.

**Usage example**
```c++
std::optional<OrqaG2dFormat> formatSrcEnum;
formatSrcEnum = G2dFormatManager::getFormatEnumFromString(formatSrc);
```
##### `getFormatMetadata`
Maps our custom `OrqaG2dFormat` values to `G2dFormatMetadata` values, used for image processing in G2d.
```c++
static std::optional<G2dFormatMetadata> getFormatMetadata(OrqaG2dFormat format);
```
**Parameters**
- `format` - `OrqaG2dFormat` enum value
**Returns**
An optional value that can be either an `G2dFormatMetadata` value or a `std::optional` empty value.

##### `isFormatConversionSupported`
Checks if the format conversion between two supported formats is supported. This is necessary because not all formats can be converted all other formats. Also, not all formats can be both source and destination formats.
```c++
static FormatManagerStatus isFormatConversionSupported (
	g2d_format srcFormat, 
	g2d_format destFormat
);program
```
**Parameters**
- `srcFormat` - Format of the source image
- `destFormat` - Format of the destination image
**Returns**
`FormatManagerStatus::SUCCESS` if the conversion is supported, `FormatManagerStatus::CONVERSION_NOT_SUPPORTED_ERROR` otherwise.

##### `listAllFormats`
Prints all formats supported by the converter to the screen.
```c++
static void listAllFormats();
```

### Class: FileReaderWriter
Handles reading and writing raw (binary) files. In this practicular project, it is used to read and write raw image files.
#### Constructors
The class only uses the default constructor. It can be instantiated as
```c++
FileReaderWriter io;
```
#### Methods
##### `writeFileRaw`
Writes a buffer of raw, binary data to a file.
```c++
FileReaderWriterStatus writeFileRaw(
	const std::string& filename,
	const std::span<uint8_t> buffer
);
```
- `filename` - a relative or absolute path of the file the method writes to
- `buffer` - a non-owning refference to a storage buffer of unsigned 8 bit integers. It can be a memory mapped file, `std::vector` or any other valid data source, as long as the reference to it is a valid `std::span` (or the reference to it can be implicitly converted to `std::span`.
**Returns**: `FileReaderWriterStatus::SUCCESS` on successful operation, `FILE_OPEN_FAILURE` if the file could not be opened.
**Example usage**
```c++
std::vector<uint8_t> bytes(10000, 0);
FileReaderWriter io;

io.writeFileRaw("zeroes.bin", bytes);
```

```c++
uint8_t bytes[10000];
memset(bytes, 0, 10000);
FileReaderWriter io;

bytesRef = std::span<uint8_t>(bytes);

io.writeFileRaw("zeroes.bin", bytes);
```

##### `readFileRaw`
Reads a file filled with raw, binary data and copies its contents to a buffer
```c++
FileReaderWriterStatus readFileRaw(
	const std::string& filename,
	std::vector<uint8_t>& buffer
);
```
- `filename` - a relative or absolute path of the file the method writes to
- `buffer` - a reference to a std::vector that the contents of the file will be written to. The vector is resized inside the method, so all of its contents will be rewritten!
**Returns**: `FileReaderWriterStatus::SUCCESS` on successful operation, `FILE_OPEN_FAILURE` if the file could not be opened.
## Test suite
If you compile the program with the provided Makefile, it will also come included with its test suite built in. The purpose of tests is to compare the output of the converter method for a given input, with the expected output that is either embedded in the code or, more usually, saved in a binary file. 

Example of a test method
```c++
TestStatus YUYVToRGBAConversionTest() {
	G2dPixelFormatConverter converter;
	FileReaderWriter fileReaderWriter;

	std::vector<uint8_t> yuyvBuffer;
	std::vector<uint8_t> rgbaBuffer;
	std::vector<uint8_t> rgbaExcpectedBuffer;
	
	fileReaderWriter.readFileRaw("tests/inputs/input.yuyv", yuyvBuffer);
	fileReaderWriter.readFileRaw("tests/expected/yuyv.rgba", rgbaExcpectedBuffer);

	G2dPixelFormatConverterStatus result = converter.convertImage(
		OrqaG2dFormat::FMT_YUYV,
		OrqaG2dFormat::FMT_RGBA8888,
		yuyvBuffer,
		rgbaBuffer,
		640,
		480
	);
	
	if (result != G2dPixelFormatConverterStatus::SUCCESS) {
		return TestStatus::GENERAL_TEST_FAILURE;
	}

	if (
		std::equal(
			rgbaBuffer.begin(), 
			rgbaBuffer.end(), 
			rgbaExcpectedBuffer.begin()
		)
	) {
		return TestStatus::PASS;
	}
	
	else {
		return TestStatus::INCORRECT_RESULT_FAILURE;
	}

}
```

### Adding a new test method
Every test method must return a `TestStatus` instance, that can either be `TestStatus::Pass` or `TestStatus::FAILURE`. The app consumer can add add more tests easily using the following method:
1. Implement the test function inside the `tests/main.cpp` file. If the test has input dependencies, they should be placed in the `tests/inputs` directory. If the test has output dependencies, they should be placed in the `tests/expected` directory
2. Add the method to the `tests` array in the `main` function, which is also found in the `tests/main.cpp` file
3. Recompile the application using the provided Makefile

Now, your custom test should be run whenever you run the test suite inside the command line.
## Supported file formats and string aliases
The converter supports the following G2D file formats
- `G2D_RGB565 (RGB565)` - 16 bit RGB, 5 pixels for Red, 6 pixels for green and 5 pixels for blue. 
- `G2D_RGBA8888 (RGBA8888)`   - 32 bit RGBA
- `G2D_RGBX8888 (RGBX8888)` - 32 bit RGB, with the last byte of each pixel treated as junk
- `G2D_ARGB8888 (ARGB8888)` - 32 bit RGBA with the alpha channel as the first byte of each pixel
- `G2D_XRGB8888 (XRGB8888)` - 32 bit RGB, with the first byte of each pixel treated as junk
- `G2D_RGB888 (RGB888)` - 24 bit RGB
- `G2D_RGBA5551 (RGBA5551)` - 16 bit RGBA
- `G2D_RGBX5551 (RGBX5551)`  - 16 bit RGB, with the last bit of each pixel treated as junk
- `G2D_NV12 (NV12)` - NV12 YUV 4:2:0 format
- `G2D_I420 (I420)` - I420 YUV 4:2:0 format
- `G2D_YV12 (YV12)` - YV12 YUV 4:2:0 format
- `G2D_NV21 (NV21)` -  NV21 YUV 4:2:0 format
- `G2D_YUYV (YUYV)` - YUV 4:2:2 format
- `G2D_YVYU (YVYU)`- YUV 4:2:2 format
- `G2D_UYVY (UYVY)`- YUV 4:2:2 format
- `G2D_VYUY (VYUY)`- YUV 4:2:2 format

### Supported format conversions

**G2D_RGBA8888**
- G2D_YUYV

**G2D_ARGB8888**  
  - `G2D_YUYV`
  
**G2D_XRGB8888**  
  - `G2D_YUYV`
  
**G2D_RGBA5551**  
  - `G2D_YUYV`
  
**G2D_RGBX5551**  
  - `G2D_YUYV`
  
**G2D_RGBA8888**  
  - `G2D_YUYV`
  
**G2D_RGBX8888**  
  - `G2D_YUYV`
  
**G2D_ARGB8888**  
  - `G2D_YUYV`
  
**G2D_XRGB8888**  
  - `G2D_YUYV`
  
**G2D_RGBA5551**  
  - `G2D_YUYV`
  
**G2D_RGBX5551**  
  - `G2D_YUYV`

**G2D_NV12**  
  - `G2D_RGB565`  
  - `G2D_RGBA8888`  
  - `G2D_RGBX8888`  
  - `G2D_ARGB8888`  
  
**G2D_YUYV**
- `G2D_RGB565`
- `G2D_RGBA8888`
- `G2D_RGBX8888`
-  `G2D_ARGB8888`
- `G2D_XRGB8888`
- `G2D_RGBA5551`
- `G2D_RGBX5551`
- `G2D_RGB888`

**G2D_I420**  
  - `G2D_ARGB8888`  
  - `G2D_XRGB8888`  ￼￼C++￼
​￼FileReaderWriterStatus readFileRaw(
	const std::string& filename,
	std::vector<ui
  - `G2D_RGBA5551`  
  - `G2D_RGBX5551`  

**G2D_YV12**  
  - `G2D_RGB565`  
  - `G2D_RGBA8888`  
  - `G2D_RGBX8888`  
  - `G2D_ARGB8888`  
  - `G2D_XRGB8888`  
  - `G2D_RGBA5551`  
  - `G2D_RGBX5551`  

**G2D_NV21**  
  - `G2D_RGB565`  
  - `G2D_RGBA8888`  
  - `G2D_RGBX8888`  
  - `G2D_ARGB8888`  
  - `G2D_XRGB8888`  
  - `G2D_RGBA5551`  
  - `G2D_RGBX5551`  

**G2D_YVYU**  
  - `G2D_RGB565`  
  - `G2D_RGBA8888`  
  - `G2D_RGBX8888`  
  - `G2D_ARGB8888`  
  - `G2D_XRGB8888`  
  - `G2D_RGBA5551`  
  - `G2D_RGBX5551`  

**G2D_UYVY**  
  - `G2D_RGB565`  
  - `G2D_RGBA8888`  
  - `G2D_RGBX8888`  
  - `G2D_ARGB8888`  
  - `G2D_XRGB8888`  
  - `G2D_RGBA5551`  
  - `G2D_RGBX5551`  

**G2D_VYUY**  
  - `G2D_RGB565`  
  - `G2D_RGBA8888`  
  - `G2D_RGBX8888`  
  - `G2D_ARGB8888`  
  - `G2D_XRGB8888`  
  - `G2D_RGBA5551`  
  - `G2D_RGBX5551`  



