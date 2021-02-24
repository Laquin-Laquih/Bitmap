#include "Bitmap.hpp"
#include "BitmapInfoHeader.hpp"
#include "bitmapFileHeader.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <cassert>

#define PADDING (width%4)
#define DATASIZE width*height*3 + PADDING*height

#define DIFF(a,b) abs((a)-(b))

using namespace std;

Bitmap::Bitmap(uint32_t w, uint32_t h): width(w), height(h), pixels(new uint8_t[DATASIZE]{}){
	
}

bool Bitmap::save(string filename){
    BitmapFileHeader fileHeader;
    BitmapInfoHeader infoHeader;

    fileHeader.dataOffset = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader);
    fileHeader.fileSize = fileHeader.dataOffset + DATASIZE;

    infoHeader.width = width;
    infoHeader.height = height;
    infoHeader.dataSize = DATASIZE;

    ofstream file;
    file.open(filename, ios::out | ios::binary);

    if(!file){
        return false;
    }

    file.write((char*)&fileHeader, sizeof(fileHeader));
    file.write((char*)&infoHeader, sizeof(infoHeader));
    file.write((char*)pixels.get(), DATASIZE);

    file.close();

    return true;
}

void Bitmap::set_pixel(uint32_t x, uint32_t y, Color color){
	assert(x < width && y < height);

    uint8_t *pPixel = pixels.get();

    pPixel += ((y*width + x)*3 + y*PADDING);

    pPixel[0] = color.blue;
    pPixel[1] = color.green;
    pPixel[2] = color.red;
}

void Bitmap::fill(Color color){
    for(uint32_t y = 0; y < height; ++y)
        for(uint32_t x = 0; x < width; ++x)
            set_pixel(x, y, color);
}

void Bitmap::draw_box(uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2, Color color){
	assert(x1 < width && x2 < width && y1 < height && y2 < height);

    for(uint32_t y = y1; y <= y2; ++y)
        for(uint32_t x = x1; x <= x2; ++x)
            set_pixel(x, y, color);
}

void Bitmap::draw_line(uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2, Color color){
	assert(x1 < width && x2 < width && y1 < height && y2 < height);

	int32_t diffX = DIFF((int32_t)x1, (int32_t)x2);
	int32_t diffY = DIFF((int32_t)y1, (int32_t)y2);

    float stepX, stepY;
    bool finished = false;

    if (diffX > diffY){
        stepX = 1;
        stepY = (float)diffY/diffX;
    } else {
    	cout << "hola";
        stepY = 1;
        stepX = (float)diffX/diffY;
    }

    if(x1 > x2) stepX *= -1;
    if(y1 > y2) stepY *= -1;

    for(float y = y1, x = x1; (x != x2 && y != y2); x += stepX, y += stepY){
        set_pixel((uint32_t)x, (uint32_t)y, color);
    }
}