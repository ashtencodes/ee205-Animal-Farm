///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205-Animal-Farm - EE 205 - Spr 2022
///
/// @file Cat.cpp
/// @version 1.0
///
/// @author @Ashten Akemoto <aakemoto@hawaii.edu>
/// @date   22_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#include "Cat.h"
#include <cassert>

const std::string Cat::SPECIES_NAME = "Felis Catus";
const Weight::t_weight Cat::MAX_WEIGHT = 40;

bool Cat::validateName(const std::string &newName) {
    if( newName.empty() ){
        return false;
    }
    return true;
}

bool Cat::validate() const noexcept {
    assert( validateName( name ) );
    assert( Animal::validate() );

    return true;
}

std::string Cat::getName() const noexcept {
    assert( validate() );
    return name;
}

void Cat::setName(const std::string &newName) {
    assert( validateName( newName ) );
    name = newName;
}

bool Cat::isFixed() const noexcept {
    return isCatFixed;
}

void Cat::fixCat() noexcept {
    assert( isCatFixed == false );
    isCatFixed = true;
}

std::string Cat::speak() const noexcept {
    return "meow";
}

void Cat::dump() const noexcept {
    Mammal::dump();
    FORMAT_LINE_FOR_DUMP( "Cat", "Name") << name << std::endl;
    FORMAT_LINE_FOR_DUMP( "Cat", "Is Fixed") << isCatFixed << std::endl;
}
