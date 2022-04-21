///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205-Animal-Farm - EE 205 - Spr 2022
///
/// @file Cat.cpp
/// @version 1.0
///
/// @author @Ashten Akemoto <aakemoto@hawaii.edu>
/// @date   21_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#include "Cat.h"
#include "catDatabase.h"

bool Cat::validate() {
    try {
        isValidName( name ) ;
        isValidWeight( weight ) ;
    } catch (std::exception const& e) {
        std::cout << e.what() << std::endl ;
        return false ;
    }
    return true;
}

std::string Cat::getName() {
    return name;
}

void Cat::setName(const std::string newName ) {
    assert( isValidName( newName ) );
    name = newName;
}

Gender Cat::getGender() {
    return gender;
}

void Cat::setGender(Gender newGender) {
    gender = newGender;
}

Breed Cat::getBreed() {
    return breed;
}

void Cat::setBreed(Breed newBreed) {
    breed = newBreed;
}

bool Cat::checkIsFixed() {
    return isFixed;
}

void Cat::fixCat() {
    assert( isFixed == false );
    isFixed = true;
}

Weight::t_weight Cat::getWeight() {
    return weight.getWeight();
}

void Cat::setWeight(Weight newWeight) {
    assert( isValidWeight( newWeight ) );
    weight = newWeight;
}