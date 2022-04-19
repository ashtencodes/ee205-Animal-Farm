///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205-Animal-Farm - EE 205 - Spr 2022
///
/// @file catDatabase.h
/// @version 1.0
///
/// @author @Ashten Akemoto <aakemoto@hawaii.edu>
/// @date   31-Mar-2022
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include <stdbool.h>
#include <cstring>
#include <cassert>
#include <string>

#define NAME_LEN_MAX 50
#define UNKNOWN_WEIGHT -1

typedef float Weight;
typedef int NumCat;

extern NumCat currentCatNum;

enum Gender { UNKNOWN_GENDER, MALE, FEMALE };
enum Breed { UNKNOWN_BREED, MAINE_COON, MANX, SHORTHAIR, PERSIAN, SPHINX };

extern bool validateDatabase();
extern bool isValidName( const std::string checkName );
extern bool isValidWeight( const Weight checkWeight ) ;

class Cat{
protected:
    std::string name;
    enum Gender gender;
    enum Breed breed;
    bool isFixed;
    Weight weight;

public:
    Cat* next;

    std::string getName();
    void setName( const std::string newName );
    Gender getGender();
    void setGender( Gender newGender );
    Breed getBreed();
    void setBreed( Breed newBreed );
    bool checkIsFixed();
    void fixCat();
    Weight getWeight();
    void setWeight( Weight newWeight );

    Cat(){
        isFixed = false;
        weight = UNKNOWN_WEIGHT;
        gender = UNKNOWN_GENDER;
        breed = UNKNOWN_BREED;
    }

    Cat (const std::string newName, const Gender newGender, const Breed newBreed, const Weight newWeight){
        assert( isValidName( newName ) );
        assert( isValidWeight( newWeight ) );
        name = newName;
        isFixed = false;
        gender = newGender;
        breed = newBreed;
        weight = newWeight;
    }

    ~Cat(){
        name = '0';
        isFixed = false;
        weight = UNKNOWN_WEIGHT;
        gender = UNKNOWN_GENDER;
        breed = UNKNOWN_BREED;
    }

    bool print();
    bool validate();
};

extern Cat *catDatabaseHeadPointer;

