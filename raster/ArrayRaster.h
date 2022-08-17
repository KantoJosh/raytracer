#ifndef ARRAY_RASTER_H
#define ARRAY_RASTER_H

#include "Raster.h"
// single threaded raster
class ArrayRaster : public Raster {
    public:
        ArrayRaster(int width, int height);
        
        virtual ~ArrayRaster() = default;

        virtual void render(Raytracer& raytracer);

        virtual int at(int row, int col);

        virtual int getWidth();

        virtual int getHeight();

        protected:
            int width;
            int height;
        std::vector<std::vector<int>> raster;
};

#endif