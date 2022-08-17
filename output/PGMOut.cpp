#include "PGMOut.h"
#include <iostream>

using namespace std;

void PGMOut::save(Raster* raster) const noexcept {
    cout << "P2\n";
    cout << raster->getWidth() << ' ' << raster->getHeight() << '\n'; // cols, rows
    cout << "255\n";
    for (auto &row : raster->raster) {
        for (int value : row) {
            cout << value << ' ';
        }
        cout << '\n';
    }
}
