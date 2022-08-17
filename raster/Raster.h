#ifndef RASTER_H
#define RASTER_H

#include "../tracer/Raytracer.h"

class Raster{
    public:
        virtual void render(Raytracer& raytracer) = 0;
        virtual int at(int row, int col) = 0;
        virtual int getWidth() = 0;
        virtual int getHeight() = 0;
        virtual ~Raster(){}

        std::vector<std::vector<int>> raster;
};

#endif