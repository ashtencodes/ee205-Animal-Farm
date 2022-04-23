///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205-Animal-Farm - EE 205 - Spr 2022
///
/// @file Mammals.h
/// @version 1.0
///
/// @author @Ashten Akemoto <aakemoto@hawaii.edu>
/// @date   22_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#pragma once
#include "Animal.h"
#include "Color.h"

class Mammal : public Animal {
public:
    static const std::string MAMMAL_NAME;

protected:
    Color color;

public:
    Mammal( const Weight::t_weight newMaxWeight, const std::string &newSpecies ) : Animal( newMaxWeight, MAMMAL_NAME, newSpecies ) {};
    Mammal( const Color newColor, const Gender newGender, const Weight::t_weight newWeight, const Weight::t_weight newMaxWeight, const std::string &newSpecies ) :
    Animal( newGender, newWeight, newMaxWeight, MAMMAL_NAME, newSpecies ) {};

public:
    Color getColor() const noexcept;
    void setColor( const Color newColor ) noexcept;
    void dump() const noexcept override;
};
