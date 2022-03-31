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
const char* genderList[] = { "UNKNOWN_GENDER", "MALE", "FEMALE" };
const char* breedList[] = { "UNKNOWN_BREED", "MAINE_COON", "MANX", "SHORTHAIR", "PERSIAN", "SPHINX" };

#include <string.h>
#include "catDatabase.h"
#include "config.h"
#include <iostream>
#include <iomanip>

NumCat currentCatNum = 0;

Cat *catDatabaseHeadPointer = nullptr;

bool validateDatabase(){
    Cat* currentCatPointer = catDatabaseHeadPointer;

    while(currentCatPointer != nullptr){
        assert(isValidName( currentCatPointer->name ));
        assert(isValidWeight( currentCatPointer->weight ));
        currentCatPointer = currentCatPointer->next;
    }

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
    assert( validate() ) ;
    cout << setw(80) << setfill( '=' ) << "" << endl ;
    cout << setfill( ' ' ) ;
    cout << left ;
    cout << boolalpha ;
    FORMAT_LINE( "Cat", "name" ) << name << endl ;
    FORMAT_LINE( "Cat", "gender" ) << genderList[gender] << endl ;
    FORMAT_LINE( "Cat", "breed" ) << breedList[breed] << endl ;
    FORMAT_LINE( "Cat", "isFixed" ) << isFixed << endl ;
    FORMAT_LINE( "Cat", "weight" ) << weight << endl ;
    return true ;
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
