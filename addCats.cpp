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
#include <cassert>

bool addCat( Cat* newCat ){
    assert( newCat != nullptr );
    newCat->validate();

    assert( validateDatabase() );

    newCat->next = catDatabaseHeadPointer;
    currentCatNum++;

    assert( validateDatabase() );

    return true;
};
