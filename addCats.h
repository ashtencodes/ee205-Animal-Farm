///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file addCats.h
/// @version 1.0
///
/// @author @Ashten Akemoto <aakemoto@hawaii.edu>
/// @date   19_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#pragma once
#include "catDatabase.h"

bool addCat( const char newName[],
             const enum Gender addGender,
             const enum Breed addBreed,
             const bool isFixed,
             const Weight weight,
             const enum Color collarColor1,
             const enum Color collarColor2,
             const unsigned long long license );



