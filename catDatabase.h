///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file catDatabase.h
/// @version 1.0
///
/// @author @Ashten Akemoto <aakemoto@hawaii.edu>
/// @date   19_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#pragma once
#include <stdbool.h>

#define MAX_NUM_CATS 30
#define NAME_LEN_MAX 50

typedef float Weight;
typedef int NumCat;

extern NumCat currentCatNum;

enum Gender { UNKNOWN_GENDER, MALE, FEMALE };
enum Breed { UNKNOWN_BREED, MAINE_COON, MANX, SHORTHAIR, PERSIAN, SPHINX };
enum Color { BLACK, WHITE, RED, BLUE, GREEN, PINK };

struct Cat {
    enum Gender gender;
    enum Breed breed;
    enum Color collarColor1;
    enum Color collarColor2;
    bool isFixed;
    Weight weight;
    unsigned long long license;
    char name[NAME_LEN_MAX];
};

extern struct Cat catArray[];

extern bool isValidIndex( const int index );
extern bool isValidName( const char checkName[] );
extern bool isValidWeight( const Weight checkWeight ) ;

