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
using namespace std;

#define FORMAT_LINE( className, member ) cout << setw(8) << (className) << setw(20) << (member) << setw(52)

#include <string.h>
#include "catDatabase.h"
#include "config.h"
#include <iostream>

NumCat currentCatNum = 0;

Cat *catDatabaseHeadPointer = nullptr;

bool validateDatabase(){
    return true;
}

bool isValidName( const char checkName[] ){
    if(strlen(checkName) <= 0){
        fprintf( stderr, "%s: Name must be at least 1 character\n", PROGRAM_NAME);
        return false;
    }

    if(strlen(checkName) >= NAME_LEN_MAX){
        fprintf( stderr, "%s: Name length cannot be larger than [%d]\n", PROGRAM_NAME, NAME_LEN_MAX);
        return false;
    }
    return true;
}

bool isValidWeight( const Weight checkWeight ){
    if(checkWeight > 0){
        return true;
    } else {
        fprintf( stderr, "%s: Weight cannot be less than 0\n", PROGRAM_NAME);
        return false;
    }
}

bool Cat::print() {
    return false;
}

bool Cat::validate() {
    try {
        isValidName( name ) ;
        isValidWeight( weight ) ;
    } catch (exception const& e) {
        cout << e.what() << endl ;
        return false ;
    }
    return true;
}
