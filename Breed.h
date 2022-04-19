///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205-Animal-Farm - EE 205 - Spr 2022
///
/// @file Breed.h
/// @version 1.0
///
/// @author @Ashten Akemoto <aakemoto@hawaii.edu>
/// @date   18_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#pragma once
#include <iostream>

enum class Breed {
    UNKNOWN_BREED = 0,
    MAINE_COON,
    MANX,
    SHORTHAIR,
    PERSIAN,
    SPHINX
};

inline std::ostream& operator<<( std::ostream& lhs_stream, const Breed& rhs_Breed ){
    switch( rhs_Breed ) {
        case Breed::UNKNOWN_BREED:
            lhs_stream << "Unknown breed";
            break;
            case Breed::MAINE_COON:
                lhs_stream << "Maine Coon";
                break;
                case Breed::MANX:
                    lhs_stream << "Manx";
                    break;
                    case Breed::SHORTHAIR:
                        lhs_stream << "Shorthair";
                        break;
                        case Breed::PERSIAN:
                            lhs_stream << "Persian";
                            break;
                            case Breed::SPHINX:
                                lhs_stream << "Sphinx";
                                break;
                                default:
                                    /// @throw out_of_range If the enum is not mapped to a string.
                                    throw std::out_of_range( PROGRAM_NAME ": Gender not mapped to a string" );
    }
    return lhs_stream;
}
