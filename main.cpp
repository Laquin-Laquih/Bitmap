#include "Bitmap.hpp"
#include "Color.hpp"
#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char** argv){
	int a, b;
    Bitmap bmp(256, 256);
    bmp.fill(Color(255, 0, 0));

    for(int i = 0; i < 256; ++i)
    	for(int j = 0; j < 256; ++j)
    		bmp.set_pixel(i, j, Color(j, sqrt(j*i), i));

    bmp.save("test.bmp");
    return 0;
}
