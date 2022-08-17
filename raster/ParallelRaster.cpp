#include "ParallelRaster.h"
#include "Viewport.h"

ParallelRaster::ParallelRaster(int width, int height, int numThreads)
    :width{width},height{height},numThreads{numThreads},nextRow{height - 1}{
        for (int y = 0; y < height; y++){
            raster.push_back(std::vector<int>());
        }
}

void ParallelRaster::render_row(Raytracer& raytracer){
    const Viewport vp{width, height};
    int y_pixel;
    while (true){
        nextRowLock.lock(); // lock access to acquire next row and copy into y_pixel
        y_pixel = nextRow;  // copy nextRow into y_pixel (avoid reading from nextRow later on in unlocked situation--> causes race condition)
        nextRow--;          // decrement nextRow for another thread to compute while computing this threads row
        
        // finished computing rows
        if (y_pixel < 0){
            nextRowLock.unlock();
            break;
        }
        else{
            nextRowLock.unlock();
        }
        
        // compute row
        for (int x_pixel = 0; x_pixel < width; ++x_pixel) {
            auto[x, y] = vp.convert_pixels(x_pixel, y_pixel);
            int brightness{static_cast<int>(raytracer.trace_primary(x,y) * 255)};
            nextRowLock.lock(); 
            raster[height - 1 - y_pixel].push_back(brightness); // add computed value to vector
            nextRowLock.unlock();
        }
    }
}

void ParallelRaster::render(Raytracer& raytracer){
    for (int i = 0; i < numThreads; i++){
        threads.push_back(std::thread(&ParallelRaster::render_row, this, std::ref(raytracer)));
    }
            
    for (int i = 0; i < numThreads; i++){
        threads[i].join();
    }
}

int ParallelRaster::at(int row, int col){
    return raster[row][col];
}

int ParallelRaster::getWidth(){
    return width;
}

int ParallelRaster::getHeight(){
    return height;
}
