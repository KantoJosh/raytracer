#ifndef PARALLEL_RASTER_H
#define PARALLEL_RASTER_H

#include "Raster.h"
#include "../tracer/Raytracer.h"
#include <mutex>
#include <thread>

//multi threaded raster
class ParallelRaster : public Raster{
    public:
        ParallelRaster(int width, int height, int numThreads);

        void render_row(Raytracer& raytracer);

        virtual void render(Raytracer& raytracer);

        virtual int getWidth();

        virtual int getHeight();

        virtual int at(int row, int col);

        virtual ~ParallelRaster() = default;
    protected:
        std::vector<std::thread> threads;
        int width;
        int height;
        int numThreads;
        int nextRow;
        std::mutex nextRowLock;
};

#endif
