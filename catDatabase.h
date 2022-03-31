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

#define MAX_NUM_CATS 30
#define NAME_LEN_MAX 50
#define UNKNOWN_WEIGHT -1

typedef float Weight;
typedef int NumCat;

extern NumCat currentCatNum;

enum Gender { UNKNOWN_GENDER, MALE, FEMALE };
enum Breed { UNKNOWN_BREED, MAINE_COON, MANX, SHORTHAIR, PERSIAN, SPHINX };
enum Color { BLACK, WHITE, RED, BLUE, GREEN, PINK };

class Cat{
public:
    char name[NAME_LEN_MAX];
    enum Gender gender;
    enum Breed breed;
    enum Color collarColor1;
    enum Color collarColor2;
    bool isFixed;
    Weight weight;
    unsigned long long license;
    Cat* next;

    Cat(){
        isFixed = false;
        weight = UNKNOWN_WEIGHT;
        gender = UNKNOWN_GENDER;
        breed = UNKNOWN_BREED;
    }

    Cat (const char* newName, const Gender newGender, const Breed newBreed, const Weight newWeight){
        isFixed = false;
    }

    ~Cat(){
        memset(name, 0, sizeof(name));
        isFixed = false;
        weight = UNKNOWN_WEIGHT;
        gender = UNKNOWN_GENDER;
        breed = UNKNOWN_BREED;
    }

    bool print();

    bool validate();
};

extern Cat *catDatabaseHeadPointer;

extern bool validateDatabase();

extern bool isValidName( const char checkName[] );
extern bool isValidWeight( const Weight checkWeight ) ;

