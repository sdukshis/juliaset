// OTUS C++ Basic course

#include <iostream>
#include <fstream>
#include <complex>

#include "netpbm.h"

const unsigned int width = 2000;
const unsigned int height = 2000;
const double xmin = -2.0;
const double xmax = 2.0;
const double ymin = -2.0;
const double ymax = 2.0;
const std::complex<double> c(-0.4, 0.6);

double julia(std::complex<double> z, std::complex<double> c, unsigned int max_iter = 300) {
    for (unsigned int i = 0; i < max_iter; ++i) {
        z = z*z + c;
        if (std::abs(z) > 3) {
            return static_cast<double>(i) / max_iter;
        }
    }
    return 1.0;
}

int main() {
    std::ofstream output("julia.pbm");
    if (!output.is_open()) {
        std::cerr << "Failed to open file julia.pbm" << std::endl;
        return 1;
    }
    write_header(output, width, height);

    const double x_step = (xmax - xmin) / width;
    const double y_step = (ymax - ymin) / height;

    double y = ymin;
    for(unsigned int i = 0; i < width; ++i) {
        double x = xmin;
        for(unsigned int j = 0; j < height; ++j) {
            double intensitive = julia(std::complex<double>(x, y), c);
            unsigned char red = 255 * intensitive;
            unsigned char green = 255 * intensitive;
            unsigned char blue = 0 * intensitive;

            write_pixel(output, red, green, blue);
            x += x_step;
        }
        y += y_step;
    }

}
