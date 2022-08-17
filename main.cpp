#include "output/PGMOut.h"
#include "tracer/Raytracer.h"
#include "raster/ArrayRaster.h"
#include "raster/ParallelRaster.h"
#include <cstdlib>
#include <memory>

using namespace std;

int main(int, char *argv[]) {
    Scene scene{argv[1]};
    int resolution = static_cast<int>(strtol(argv[2], nullptr, 10));
    Raytracer raytracer{move(scene)};
    ParallelRaster* pr = new ParallelRaster(resolution,resolution,4);
    pr->render(raytracer);
    PGMOut().save(move(pr));
    delete pr;
    return 0;
}