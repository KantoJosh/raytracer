#include "Viewport.h"

Viewport::Viewport(int x_resolution, int y_resolution) noexcept
    :
    x_factor_{x_resolution == 1 ? 1. : 2. / x_resolution},
    x_shift_{1. - 1. / x_resolution},
    y_factor_{y_resolution == 1 ? 1. : 2. / y_resolution},
    y_shift_{1 - 1. / y_resolution} {
}


std::pair<double, double> Viewport::convert_pixels(int x, int y) const noexcept {
    return {x * x_factor_ - x_shift_, y * y_factor_ - y_shift_};
}