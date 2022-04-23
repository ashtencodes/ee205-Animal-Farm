///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205-Animal-Farm - EE 205 - Spr 2022
///
/// @file Cat.h
/// @version 1.0
///
/// @author @Ashten Akemoto <aakemoto@hawaii.edu>
/// @date   22_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once
#include "Mammal.h"

class Cat : public Mammal {

protected:
    std::string name;
    bool isCatFixed;

public:
    static const std::string SPECIES_NAME;
    static const Weight::t_weight MAX_WEIGHT;

public:
    Cat( const std::string &newName ) : Mammal( MAX_WEIGHT, SPECIES_NAME ) {
        name = newName;
        isCatFixed = false;
    };

    Cat( const std::string &newName, const Color newColor, const bool newIsFixed, const Gender newGender, const Weight::t_weight newWeight ) : Mammal( newColor, newGender, newWeight, MAX_WEIGHT, SPECIES_NAME ) {
        name = newName;
        isCatFixed = newIsFixed;
    };

public:
    std::string getName() const noexcept;
    void setName( const std::string &newName );
    bool isFixed() const noexcept;
    void fixCat() noexcept;
    std::string speak() const noexcept override;
    void dump() const noexcept override;
    bool validate() const noexcept override;
    static bool validateName( const std::string &newName );
};