#ifndef RAYTRACER_PGMOUT_H
#define RAYTRACER_PGMOUT_H

#include <vector>
#include "raster/Raster.h"

class PGMOut {
public:
    // void save(const std::vector<std::vector<int>> &raster) const noexcept;
    void save(Raster* raster) const noexcept;
};

#endif
