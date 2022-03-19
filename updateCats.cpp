///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file updateCats.cpp
/// @version 1.0
///
/// @author @Ashten Akemoto <aakemoto@hawaii.edu>
/// @date   19_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#include "updateCats.h"
#include "config.h"
#include <stdio.h>
#include <string.h>

bool updateCatName(int index, char name[]){
    bool isDuplicate = false;
    for( int indexNum = 0; indexNum < MAX_NUM_CATS; indexNum++ ){
        if( strcmp(catArray[indexNum].name, name) == 0 ){
            isDuplicate = true;
        }
    }

    if(!isDuplicate){
        strcpy(catArray[index].name, name);
        return true;
    } else {
        fprintf( stderr, "%s: Duplicate name! [%s]\n", PROGRAM_NAME, name);
        return false;
    }
}

bool fixCat(int index){
    if( isValidIndex(index) ){
        if(catArray[index].isFixed == false){
            printf("Neutered [%s]!\n", catArray[index].name);
            catArray[index].isFixed = true;
            return true;
        }
    } else {
        return false;
    }
    return false;
}

bool updateCatWeight (int index, float newWeight){
    if ( isValidWeight(newWeight) ){
        catArray[index].weight = newWeight;
        return true;
    } else {
        return false;
    }
}

bool updateCollar1 ( int index, enum Color newColor ){
    catArray[index].collarColor1 = newColor;
    return true;
}

bool updateCollar2 ( int index, enum Color newColor ){
    catArray[index].collarColor2 = newColor;
    return true;
}

bool updateLicense ( int index, unsigned long long newLicense ){
    catArray[index].license = newLicense;
    return true;
}

