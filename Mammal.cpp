///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205-Animal-Farm - EE 205 - Spr 2022
///
/// @file Mammals.cpp
/// @version 1.0
///
/// @author @Ashten Akemoto <aakemoto@hawaii.edu>
/// @date   22_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#include "Mammal.h"

const std::string Mammal::MAMMAL_NAME = "Mammilian";

Color Mammal::getColor() const noexcept {
    return color;
}

void Mammal::setColor( const Color newColor ) noexcept{
    color = newColor;
}

void Mammal::dump() const noexcept {
    Animal::dump();
    FORMAT_LINE_FOR_DUMP( "Mammal", "color" ) << color << std::endl;
}
