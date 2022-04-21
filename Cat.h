///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205-Animal-Farm - EE 205 - Spr 2022
///
/// @file Cat.h
/// @version 1.0
///
/// @author @Ashten Akemoto <aakemoto@hawaii.edu>
/// @date   21_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#pragma once
#include "Gender.h"
#include "Breed.h"
#include "Color.h"
#include "Weight.h"

#include <stdbool.h>
#include <cstring>
#include <cassert>
#include <string>

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
    Weight::t_weight getWeight();
    void setWeight( Weight newWeight );

    Cat(){
        isFixed = false;
        weight = Weight::UNKNOWN_WEIGHT;
        gender = Gender::UNKNOWN_GENDER;
        breed = Breed::UNKNOWN_BREED;
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
        weight = Weight::UNKNOWN_WEIGHT;
        gender = Gender::UNKNOWN_GENDER;
        breed = Breed::UNKNOWN_BREED;
    }

    bool print();
    bool validate();
};

extern Cat *catDatabaseHeadPointer;
