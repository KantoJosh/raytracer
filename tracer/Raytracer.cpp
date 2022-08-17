#include "Raytracer.h"
#include "../raster/Viewport.h"
#include "LightModel.h"
#include <cmath>
#include <utility>

using namespace std;

std::vector<std::vector<int>> Raytracer::to_raster(int resolution) const noexcept {
    const Viewport vp{resolution, resolution};

    std::vector<std::vector<int>> raster;

    for (int y_pixel = resolution - 1; y_pixel >= 0; --y_pixel) {
        raster.emplace_back(); // inserts row

        for (int x_pixel = 0; x_pixel < resolution; ++x_pixel) {
            auto[x, y] = vp.convert_pixels(x_pixel, y_pixel);
            int brightness{static_cast<int>(trace_primary(x,y) * 255)};
            raster.back().push_back(brightness);
        }
    }

    return raster;
}

double Raytracer::trace(Ray ray) const noexcept {
    const LightModel lm{this, &scene};
    auto intersection{scene.find_intersection(ray)};
    double brightness{intersection.has_value() ? lm.brightness(ray, intersection.value()) : 0.};
    brightness = brightness > 1. ? 1 : brightness;
    return brightness;  // returns 1 or any value < 1 as a double
}

double Raytracer::trace_primary(double x, double y) const noexcept {
    Ray ray{scene.camera.get_ray(x, y)};
    return trace(ray);
}