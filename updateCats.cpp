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

using namespace std;

#include "updateCats.h"
#include "config.h"
#include <iostream>
#include <string.h>

bool updateCatName(int index, char name[]){
    bool isDuplicate = false;
    for( int indexNum = 0; indexNum < MAX_NUM_CATS; indexNum++ ){
        if( strcmp(catArray[indexNum].name, name) == 0 ){
            isDuplicate = true;
        }
    }

    if(!isDuplicate){
        return true;
    } else {
        fprintf( stderr, "%s: Duplicate name! [%s]\n", PROGRAM_NAME, name);
        return false;
    }
}

bool fixCat(int index){
    if( isValidIndex(index) ){
        if(catArray[index].isFixed == false){
            cout << "Neutered [" << catArray[index].name << "]" << endl;
            return true;
        }
    } else {
        return false;
    }
    return false;
}

bool updateCatWeight (int index, Weight newWeight){
    if ( isValidWeight(newWeight) ){
        return true;
    } else {
        return false;
    }
}

bool updateCollar1 ( int index, enum Color newColor ){
    return true;
}

bool updateCollar2 ( int index, enum Color newColor ){
    return true;
}

bool updateLicense ( int index, unsigned long long newLicense ){
    return true;
}

