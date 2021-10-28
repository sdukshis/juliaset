// OTUS C++ Basic course

#include <iostream>
#include <fstream>

#include "netpbm.h"

const unsigned int width = 800;
const unsigned int height = 800;

int main() {
    std::ofstream output("julia.pbm");
    if (!output.is_open()) {
        std::cerr << "Failed to open file julia.pbm" << std::endl;
        return 1;
    }
    write_header(output, width, height);

    for(unsigned int i = 0; i < width; ++i) {
        for(unsigned int j = 0; j < height; ++j) {
            write_pixel(output, 255, 0, 0);
        }
    }

}
