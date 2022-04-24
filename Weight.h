///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab12a_fatCat - EE 205 - Spr 2022
///
/// @file weight.h
/// @version 1.0
///
/// @author @Ashten Akemoto <aakemoto@hawaii.edu>
/// @date   11_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#pragma once
#include <string>

class Weight {
public: ////////////// Enumerations and Const /////////////
    typedef float t_weight;
    enum UnitOfWeight { POUND, KILO, SLUG };

    static const t_weight UNKNOWN_WEIGHT;
    static const t_weight KILOS_IN_A_POUND;
    static const t_weight SLUGS_IN_A_POUND;

    static const std::string POUND_LABEL;
    static const std::string KILO_LABEL;
    static const std::string SLUG_LABEL;

private:
    bool bIsKnown;
    bool bHasMax;

    enum UnitOfWeight unitOfWeight;

    t_weight weight;
    t_weight maxWeight;

public: ////////////// Constructors //////////////
    Weight() noexcept;
    Weight( t_weight newWeight );
    Weight( UnitOfWeight newUnitOfWeight ) noexcept;
    Weight( t_weight newWeight, UnitOfWeight newUnitOfWeight ) noexcept;
    Weight( t_weight newWeight, t_weight newMaxWeight );
    Weight( UnitOfWeight newUnitOfWeight, t_weight newMaxWeight );
    Weight( t_weight newWeight, UnitOfWeight newUnitOfWeight, t_weight newMaxWeight );

public: ////////////// Getters and Setters //////////////
    bool isWeightKnown() const noexcept;
    bool hasMaxWeight() const noexcept;
    t_weight getWeight() const noexcept;
    t_weight getWeight(UnitOfWeight weightUnits) const noexcept;
    t_weight getMaxWeight() const noexcept;
    UnitOfWeight getWeightUnit() const noexcept;
    void setWeight(t_weight newWeight);
    void setWeight(t_weight newWeight, UnitOfWeight weightUnits);
    void setMaxWeight(t_weight newMaxWeight);

    bool isWeightValid(t_weight checkWeight) const noexcept;
    bool validate() const noexcept;
    void dump() const noexcept;

public:
    bool operator==(const Weight &rhs_Weight) const;
    bool operator<(const Weight &rhs_Weight) const;
    Weight & operator+=(t_weight rhs_addToWeight);
    static t_weight fromKilogramToPound(t_weight kilogram) noexcept;
    static t_weight fromPoundToKilogram(t_weight pound) noexcept;
    static t_weight fromSlugToPound(t_weight slug) noexcept;
    static t_weight fromPoundToSlug(t_weight pound) noexcept;
    static t_weight convertWeight(t_weight fromWeight, UnitOfWeight fromUnit, UnitOfWeight toUnit) noexcept;
};

inline std::ostream& operator<<( std::ostream& lhs_stream
        ,const Weight::UnitOfWeight rhs_UnitOfWeight ) {
    switch( rhs_UnitOfWeight ) {
        case Weight::POUND: return lhs_stream << Weight::POUND_LABEL ;
        case Weight::KILO: return lhs_stream << Weight::KILO_LABEL ;
        case Weight::SLUG: return lhs_stream << Weight::SLUG_LABEL ;
    }
    return lhs_stream << Weight::POUND_LABEL ;
}