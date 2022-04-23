///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205-Animal-Farm - EE 205 - Spr 2022
///
/// @file Color.h
/// @version 1.0
///
/// @author @Ashten Akemoto <aakemoto@hawaii.edu>
/// @date   18_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#pragma once
#include <iostream>
#include "config.h"

enum class Color {
    UNKNOWN_COLOR=0,
    BLACK,
    WHITE,
    RED,
    BLUE,
    GREEN,
    PINK,
};

inline std::ostream& operator<<( std::ostream& lhs_stream, const Color& rhs_Color ){
    switch( rhs_Color ) {
        case Color::UNKNOWN_COLOR:
            lhs_stream << "Unknown Color";
            break;
        case Color::BLACK:
            lhs_stream << "Black";
            break;
        case Color::BLUE:
            lhs_stream << "Blue";
            break;
        case Color::GREEN:
            lhs_stream << "Green";
            break;
        case Color::PINK:
            lhs_stream << "Pink";
            break;
        case Color::RED:
            lhs_stream << "Red";
            break;
        case Color::WHITE:
            lhs_stream << "White";
            break;
            default:
                        /// @throw out_of_range If the enum is not mapped to a string.
                        throw std::out_of_range( PROGRAM_NAME ": Gender not mapped to a string" );
    }
    return lhs_stream;
}
