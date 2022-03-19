///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file addCats.cpp
/// @version 1.0
///
/// @author @Ashten Akemoto <aakemoto@hawaii.edu>
/// @date   19_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#include <string.h>

#include "config.h"
#include "addCats.h"

bool addCat( const char newName[], const enum Gender addGender, const enum Breed addBreed, const bool isFixed, const float weight, const enum Color collarColor1, const enum Color collarColor2, const unsigned long long license ){
    if(isValidName(newName) && isValidWeight(weight)){

        strcpy(catArray[currentCatNum].name, newName);
        catArray[currentCatNum].breed = addBreed;
        catArray[currentCatNum].isFixed = isFixed;
        catArray[currentCatNum].weight = weight;
        catArray[currentCatNum].gender = addGender;
        catArray[currentCatNum].collarColor1 = collarColor1;
        catArray[currentCatNum].collarColor2 = collarColor2;
        catArray[currentCatNum].license = license;

        currentCatNum += 1;
        return true;
    } else {
        return false;
    }
};
