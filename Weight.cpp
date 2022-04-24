///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab12a_fatCat - EE 205 - Spr 2022
///
/// @file weight.cpp
/// @version 1.0
///
/// @author @Ashten Akemoto <aakemoto@hawaii.edu>
/// @date   11_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#include "Weight.h"
#include <cassert>
#include <iostream>

const Weight::t_weight Weight::UNKNOWN_WEIGHT = -1 ;
const Weight::t_weight Weight::KILOS_IN_A_POUND = 0.453592 ;
const Weight::t_weight Weight::SLUGS_IN_A_POUND = 0.031081 ;

const std::string Weight::POUND_LABEL = "Pound";
const std::string Weight::KILO_LABEL = "Kilo";
const std::string Weight::SLUG_LABEL = "Slug";

Weight::Weight() noexcept {
    bIsKnown = false;
    bHasMax = false;
    unitOfWeight = POUND;
    maxWeight = UNKNOWN_WEIGHT;
    weight = UNKNOWN_WEIGHT;
    assert( validate() );
}

Weight::Weight(t_weight newWeight) {
    bIsKnown = true;
    bHasMax = false;
    unitOfWeight = POUND;
    maxWeight = UNKNOWN_WEIGHT;
    weight = newWeight;
    assert( validate() );
}

Weight::Weight(Weight::UnitOfWeight newUnitOfWeight) noexcept {
    bIsKnown = false;
    bHasMax = false;
    unitOfWeight = newUnitOfWeight;
    maxWeight = UNKNOWN_WEIGHT;
    weight = UNKNOWN_WEIGHT;
    assert( validate() );
}

Weight::Weight(t_weight newWeight, Weight::UnitOfWeight newUnitOfWeight) noexcept {
    bIsKnown = true;
    bHasMax = false;
    unitOfWeight = newUnitOfWeight;
    maxWeight = UNKNOWN_WEIGHT;
    weight = newWeight;
    assert( validate() );
}

Weight::Weight(t_weight newWeight, t_weight newMaxWeight) {
    bIsKnown = true;
    bHasMax = true;
    unitOfWeight = POUND;
    maxWeight = newMaxWeight;
    weight = newWeight;
    assert( validate() );
}

Weight::Weight(Weight::UnitOfWeight newUnitOfWeight, t_weight newMaxWeight) {
    bIsKnown = false;
    bHasMax = true;
    unitOfWeight = newUnitOfWeight;
    weight = UNKNOWN_WEIGHT;
    maxWeight = newMaxWeight;
    assert( validate() );
}

Weight::Weight(t_weight newWeight, Weight::UnitOfWeight newUnitOfWeight, t_weight newMaxWeight) {
    bIsKnown = true;
    bHasMax = true;
    unitOfWeight = newUnitOfWeight;
    weight = newWeight;
    maxWeight = newMaxWeight;
    assert( validate() );
}

bool Weight::isWeightKnown() const noexcept {
    return bIsKnown;
}

bool Weight::hasMaxWeight() const noexcept {
    return bHasMax;
}

Weight::t_weight Weight::getWeight() const noexcept {
    assert( isWeightValid( weight ) );
    return weight;
}

Weight::t_weight Weight::getWeight(Weight::UnitOfWeight weightUnits) const noexcept {
    assert( isWeightValid( weight ) );
    t_weight currentWeight = convertWeight(weight, unitOfWeight, weightUnits);
    return currentWeight;
}

Weight::t_weight Weight::getMaxWeight() const noexcept {
    assert( isWeightValid( maxWeight ));
    return maxWeight;
}

Weight::UnitOfWeight Weight::getWeightUnit() const noexcept {
    return unitOfWeight;
}

void Weight::setWeight(t_weight newWeight) {
    assert( isWeightValid( newWeight ) );
    weight = newWeight;
}

void Weight::setWeight(t_weight newWeight, Weight::UnitOfWeight weightUnits) {
    assert( isWeightValid( newWeight ) );
    weight = newWeight;
    unitOfWeight = weightUnits;
}

void Weight::setMaxWeight(t_weight newMaxWeight) {
    assert( isWeightValid( newMaxWeight ));
    maxWeight = newMaxWeight;
}

bool Weight::isWeightValid(t_weight checkWeight) const noexcept {
    assert( (checkWeight > 0) || checkWeight == UNKNOWN_WEIGHT );
    if( bHasMax ){
        assert( checkWeight <= maxWeight );
    }
    return true;
}

bool Weight::validate() const noexcept {
    assert( isWeightValid( weight ) );
    assert( isWeightValid ( maxWeight ) );
    return true;
}

Weight::t_weight Weight::fromKilogramToPound(t_weight kilogram) noexcept {
    t_weight pound = kilogram / KILOS_IN_A_POUND;
    return pound;
}

Weight::t_weight Weight::fromPoundToKilogram(t_weight pound) noexcept {
    t_weight kilogram = pound * KILOS_IN_A_POUND;
    return kilogram;
}

Weight::t_weight Weight::fromSlugToPound(t_weight slug) noexcept {
    t_weight pound = slug / SLUGS_IN_A_POUND;
    return pound;
}

Weight::t_weight Weight::fromPoundToSlug(t_weight pound) noexcept {
    t_weight slug = pound * SLUGS_IN_A_POUND;
    return slug;
}

Weight::t_weight Weight::convertWeight(t_weight fromWeight, Weight::UnitOfWeight fromUnit, Weight::UnitOfWeight toUnit) noexcept {
    switch( fromUnit ){
        case POUND:
            switch( toUnit ){
                case POUND:
                    return fromWeight;
                    case KILO:
                        return fromPoundToKilogram( fromWeight );
                        case SLUG:
                            return fromPoundToSlug( fromWeight );
            }
            case KILO:
                switch( toUnit ){
                    case POUND:
                        return fromKilogramToPound( fromWeight );
                        case KILO:
                            return fromWeight;
                            case SLUG:
                                t_weight pound = fromKilogramToPound( fromWeight );
                                return fromPoundToSlug( pound );
                }
                case SLUG:
                    switch( toUnit ){
                        case SLUG:
                            return fromWeight;
                            case POUND:
                                return fromSlugToPound( fromWeight );
                                case KILO:
                                    t_weight pound = fromSlugToPound( fromWeight );
                                    return fromPoundToKilogram( pound );
                    }
    }
    return 0;
}

bool Weight::operator==(const Weight &rhs_Weight) const {
    t_weight leftWeight = convertWeight( weight, unitOfWeight, POUND );
    t_weight rightWeight = convertWeight( rhs_Weight.weight, rhs_Weight.unitOfWeight, POUND );
    if( leftWeight == rightWeight ){
        return true;
    }
    else {
        return false;
    }
}

bool Weight::operator<(const Weight &rhs_Weight) const {
    t_weight leftWeight = convertWeight( weight, unitOfWeight, POUND );
    t_weight rightWeight = convertWeight( rhs_Weight.weight, rhs_Weight.unitOfWeight, POUND );
    if( leftWeight < rightWeight ){
        return true;
    }
    else {
        return false;
    }
}

Weight &Weight::operator+=(t_weight rhs_addToWeight) {
    weight += rhs_addToWeight;
    return *this;
}

void Weight::dump() const noexcept {
    std::cout << "======================================================" << std::endl;
    std::cout << "bIsKnown: " << bIsKnown << std::endl;
    std::cout << "bHasMax: " << bHasMax << std::endl;
    std::cout << "Unit of Weight: " << unitOfWeight << std::endl;
    std::cout << "Weight: " << weight << std::endl;
    std::cout << "Max Weight: " << maxWeight << std::endl;
}