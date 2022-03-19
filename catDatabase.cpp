///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file catDatabase.cpp
/// @version 1.0
///
/// @author @Ashten Akemoto <aakemoto@hawaii.edu>
/// @date   19_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#include <string.h>
#include "catDatabase.h"
#include "config.h"
#include <stdio.h>

int currentCatNum = 0;

struct Cat catArray[MAX_NUM_CATS];

bool isValidIndex( const int index ){
    if( index >= 0 && index < MAX_NUM_CATS){
        fprintf( stderr, "valid index\n", PROGRAM_NAME);
        return true;
    } else {
        fprintf( stderr, "invalid index\n", PROGRAM_NAME);
        return false;
    }
}

bool isValidName( const char checkName[] ){
    if(strlen(checkName) <= 0){
        fprintf( stderr, "%s: Name must be at least 1 character\n", PROGRAM_NAME);
        return false;
    };

    if(strlen(checkName) >= NAME_LEN_MAX){
        fprintf( stderr, "%s: Name length cannot be larger than [%d]\n", PROGRAM_NAME, NAME_LEN_MAX);
        return false;
    };

    for( int indexNum = 0; indexNum < MAX_NUM_CATS; indexNum++ ){
        if( strcmp(catArray[indexNum].name, checkName) == 0 ){
            fprintf( stderr, "%s: Duplicate name found!\n", PROGRAM_NAME);
            return false;
        }
    }

    return true;
}

bool isValidWeight( const float checkWeight ){
    if(checkWeight > 0){
        return true;
    } else {
        fprintf( stderr, "%s: Weight cannot be less than 0\n", PROGRAM_NAME);
        return false;
    }
}

