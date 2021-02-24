#ifndef COLOR_H
#define COLOR_H

#include <cstdint>

struct __attribute__((packed)) Color{
	Color(uint8_t r, uint8_t g, uint8_t b);
	uint8_t red;
	uint8_t green;
	uint8_t blue;
};

#endif //COLOR_H