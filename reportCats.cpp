///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file reportCats.cpp
/// @version 1.0
///
/// @author @Ashten Akemoto <aakemoto@hawaii.edu>
/// @date   19_Mar_2022
///////////////////////////////////////////////////////////////////////////////

using namespace std;

#include "reportCats.h"
#include "config.h"
#include <iostream>
#include <string.h>

const char* genderList[] = { "UNKNOWN_GENDER", "MALE", "FEMALE" };
const char* breedList[] = { "UNKNOWN_BREED", "MAINE_COON", "MANX", "SHORTHAIR", "PERSIAN", "SPHINX" };

void printAllCats(){
    assert( validateDatabase() );
}

int findCat(char name[]){
    int targetIndex = -1;
    return targetIndex;
}


