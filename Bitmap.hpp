#ifndef BITMAP_H
#define BITMAP_H

#include "Color.hpp"

#include <string>
#include <cstdint>
#include <memory>

class Bitmap{
public:
    Bitmap(uint32_t w, uint32_t h);
    void set_pixel(uint32_t x, uint32_t y, Color);
    bool save(std::string filename);
    void fill(Color);
    void draw_box(uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2, Color);
    void draw_line(uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2, Color);
private:
    uint32_t width = 0;
    uint32_t height = 0;
    std::unique_ptr<uint8_t[]> pixels = nullptr;
};

#endif // BITMAP_H
