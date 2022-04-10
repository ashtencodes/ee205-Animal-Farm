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
        assert(isValidName( currentCatPointer->getName() ));
        assert(isValidWeight( currentCatPointer->getWeight() ));
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
    FORMAT_LINE( "Cat", "name" ) << getName() << endl ;
    FORMAT_LINE( "Cat", "gender" ) << genderList[getGender()] << endl ;
    FORMAT_LINE( "Cat", "breed" ) << breedList[getBreed()] << endl ;
    FORMAT_LINE( "Cat", "isFixed" ) << checkIsFixed() << endl ;
    FORMAT_LINE( "Cat", "weight" ) << getWeight() << endl ;
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

char *Cat::getName() {
    return name;
}

void Cat::setName(const char newName[] ) {
    assert( isValidName( newName ) );
    strcpy( name, newName );
}

Gender Cat::getGender() {
    return gender;
}

void Cat::setGender(Gender newGender) {
    gender = newGender;
}

Breed Cat::getBreed() {
    return breed;
}

void Cat::setBreed(Breed newBreed) {
    breed = newBreed;
}

bool Cat::checkIsFixed() {
    return isFixed;
}

void Cat::fixCat() {
    assert( isFixed == false );
    isFixed = true;
}

Weight Cat::getWeight() {
    return weight;
}

void Cat::setWeight(Weight newWeight) {
    assert( isValidWeight( newWeight ) );
    weight = newWeight;
}
