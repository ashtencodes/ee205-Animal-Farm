///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205-Animal-Farm - EE 205 - Spr 2022
///
/// @file Animal.cpp
/// @version 1.0
///
/// @author @Ashten Akemoto <aakemoto@hawaii.edu>
/// @date   21_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#include "Animal.h"
#include <cassert>

const std::string Animal::KINGDOM_NAME = "Animalia";

Animal::Animal(const Weight::t_weight newMaxWeight, const std::string &newClassification,
               const std::string &newSpecies) {
    assert( validateClassification( newClassification ) );
    assert( validateSpecies( newSpecies ) );
    weight.setMaxWeight( newMaxWeight );
    classification = newClassification;
    species = newSpecies;
}

Animal::Animal(const Gender newGender, const Weight::t_weight newWeight, const Weight::t_weight newMaxWeight,
               const std::string &newClassification, const std::string &newSpecies) {
    assert( validateClassification( newClassification ) );
    assert( validateSpecies( newSpecies ) );
    gender = newGender;
    weight.setWeight( newWeight );
    weight.setMaxWeight( newMaxWeight );
    classification = newClassification;
    species = newSpecies;
}

std::string Animal::getKingdom() const noexcept {
    return KINGDOM_NAME;
}

std::string Animal::getClassification() const noexcept {
    return classification;
}

std::string Animal::getSpecies() const noexcept {
    return species;
}

Gender Animal::getGender() const noexcept {
    return gender;
}

Weight::t_weight Animal::getWeight() const noexcept {
    return weight.getWeight();
}

void Animal::setWeight(const Weight::t_weight newWeight) {
    weight.setWeight( newWeight );
}

void Animal::setGender(const Gender newGender) {
    if(gender != Gender::UNKNOWN_GENDER){
        throw std::logic_error("Can't change gender twice");
    }

    assert(gender == Gender::UNKNOWN_GENDER);
    gender = newGender;
    assert( validate() );
}

void Animal::dump() const noexcept {
    FORMAT_LINE_FOR_DUMP( "Animal", "this" ) << this << std::endl;
    FORMAT_LINE_FOR_DUMP( "Animal", "kingdom" ) << getKingdom() << std::endl;
    FORMAT_LINE_FOR_DUMP( "Animal", "classification" ) << getClassification() << std::endl;
    FORMAT_LINE_FOR_DUMP( "Animal", "species" ) << getSpecies() << std::endl;
    FORMAT_LINE_FOR_DUMP( "Animal", "gender" ) << getGender() << std::endl;
    FORMAT_LINE_FOR_DUMP( "Animal", "weight" ) << getWeight() << std::endl;
}

bool Animal::validateClassification(const std::string &checkClassification) noexcept {
    if( checkClassification.empty() ){
        std::cout << PROGRAM_NAME << ": classification cannot be empty!" << std::endl;
        return false;
    }
    return true;
}

bool Animal::validateSpecies(const std::string &checkSpecies) noexcept {
    if( checkSpecies.empty() ){
        std::cout << PROGRAM_NAME << ": species cannot be empty!" << std::endl;
        return false;
    }
    return true;
}

bool Animal::validate() const noexcept {
    assert( !getKingdom().empty );
    assert( validateClassification( getClassification() ) );
    assert( validateSpecies( getSpecies() ) );

    assert( weight.vaidate() );
    return true;
}

Weight::t_weight Animal::getMaxWeight() const noexcept {
    return weight.getMaxWeight();
}
