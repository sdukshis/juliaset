// OTUS C++ basic course 
// Netpbm format printer

#pragma once

#include <ostream>

void write_header(std::ostream &, unsigned int width, unsigned height);

void write_pixel(std::ostream &, unsigned char red, unsigned char green, unsigned char blue);
