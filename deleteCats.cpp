///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file deleteCats.cpp
/// @version 1.0
///
/// @author @Ashten Akemoto <aakemoto@hawaii.edu>
/// @date   19_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#include <string.h>

#include "deleteCats.h"
#include "catDatabase.h"
#include "config.h"

void deleteAllCats(){
    assert( validateDatabase() );
    catDatabaseHeadPointer = nullptr;
}

bool deleteCat(int index){
    assert( validateDatabase() );
}
