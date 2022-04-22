///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205-Animal-Farm - EE 205 - Spr 2022
///
/// @file Animal.h
/// @version 1.0
///
/// @author @Ashten Akemoto <aakemoto@hawaii.edu>
/// @date   21_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#pragma once
#include <string>
#include "Node.h"
#include "Gender.h"
#include "Weight.h"

class Animal : public Node {

private:
    std::string species;
    std::string classification;
    Gender gender;
    Weight weight;

public:
    static const std::string KINGDOM_NAME;

    Animal( const Weight::t_weight newMaxWeight, const std::string &newClassification, const std::string &newSpecies );
    Animal( const Gender newGender, const Weight::t_weight newWeight, const Weight::t_weight newMaxWeight, const std::string &newClassification, const std::string &newSpecies );

public:
    std::string getKingdom() const noexcept;
    std::string getClassification() const noexcept;
    std::string getSpecies() const noexcept;
    Gender getGender() const noexcept;
    Weight::t_weight getWeight() const noexcept;

    void setWeight( const Weight::t_weight newWeight );
    virtual std::string speak() const noexcept=0;
    void dump() const noexcept override;
    bool validate() const noexcept override;

    static bool validateClassification( const std::string &checkClassification ) noexcept;
    static bool validateSpecies( const std::string &checkSpecies ) noexcept;
    void setGender( const Gender newGender );
};
