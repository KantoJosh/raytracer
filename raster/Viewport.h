#ifndef VIEWPORT_H
#define VIEWPORT_H

#include <utility>

class Viewport {
    double x_factor_;
    double x_shift_;
    double y_factor_;
    double y_shift_;

    public:
        Viewport(int x_resolution, int y_resolution) noexcept;

        [[nodiscard]] std::pair<double, double> convert_pixels(int x, int y) const noexcept;
};


#endif