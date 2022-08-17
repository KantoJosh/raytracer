#include "ArrayRaster.h"
#include "Viewport.h"

ArrayRaster::ArrayRaster(int width, int height)
    :width{width},height{height}
{}

void ArrayRaster::render(Raytracer& raytracer){
    const Viewport vp{width, height};

    for (int y_pixel = height - 1; y_pixel >= 0; --y_pixel) {
        raster.emplace_back();  // inserts row

        for (int x_pixel = 0; x_pixel < width; ++x_pixel) {
            auto[x, y] = vp.convert_pixels(x_pixel, y_pixel);
            int brightness{static_cast<int>(raytracer.trace_primary(x,y) * 255)};
            raster.back().push_back(brightness);
        }
    }
}

int ArrayRaster::at(int row, int col){
    return raster[row][col];
}

int ArrayRaster::getWidth(){
    return width;
}

int ArrayRaster::getHeight(){
    return height;
}

