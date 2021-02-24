#ifndef BITMAPFILEHEADER_H
#define BITMAPFILEHEADER_H

#include <cstdint>

struct __attribute__((packed)) BitmapFileHeader{
    char header[2]{'B', 'M'};
    int32_t fileSize;
    int32_t reserved = 0;
    int32_t dataOffset;
};

#endif // BITMAPFILEHEADER_H