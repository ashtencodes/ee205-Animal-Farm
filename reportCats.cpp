///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file reportCats.cpp
/// @version 1.0
///
/// @author @Ashten Akemoto <aakemoto@hawaii.edu>
/// @date   19_Mar_2022
///////////////////////////////////////////////////////////////////////////////

using namespace std;

#define FORMAT_LINE( className, member ) cout << setw(8) << (className) << setw(20) << (member) << setw(52)

#include "reportCats.h"
#include "config.h"
#include <iomanip>

inline std::ostream& operator<<( std::ostream& lhs_stream, const Gender& rhs_Gender ){
    switch( rhs_Gender ) {
        case Gender::UNKNOWN_GENDER:
            lhs_stream << "Unknown gender";
            break;
            case Gender::MALE:
                lhs_stream << "Male";
                break;
                case Gender::FEMALE:
                    lhs_stream << "Female";
                    break;
                    default:
                        /// @throw out_of_range If the enum is not mapped to a string.
                        throw std::out_of_range( PROGRAM_NAME ": Gender not mapped to a string" );
    }
    return lhs_stream;
}

std::ostream& operator<<( std::ostream& lhs_stream
        ,const Weight::UnitOfWeight rhs_UnitOfWeight ) {
    switch( rhs_UnitOfWeight ) {
        case Weight::POUND: return lhs_stream << Weight::POUND_LABEL ;
        case Weight::KILO: return lhs_stream << Weight::KILO_LABEL ;
        case Weight::SLUG: return lhs_stream << Weight::SLUG_LABEL ;
    }
    return lhs_stream << Weight::POUND_LABEL ;
}

bool Cat::print() {
    assert( validate() ) ;
    cout << setw(80) << setfill( '=' ) << "" << endl ;
    cout << setfill( ' ' ) ;
    cout << left ;
    cout << boolalpha ;
    FORMAT_LINE( "Cat", "name" ) << getName() << endl ;
    FORMAT_LINE( "Cat", "gender" ) << getGender() << endl ;
    FORMAT_LINE( "Cat", "breed" ) << getBreed() << endl ;
    FORMAT_LINE( "Cat", "isFixed" ) << checkIsFixed() << endl ;
    FORMAT_LINE( "Cat", "weight" ) << getWeight() << endl ;
    return true ;
}

void printAllCats(){
    assert( validateDatabase() );

    Cat* currentCatPointer = catDatabaseHeadPointer;
    while(currentCatPointer != nullptr){
        currentCatPointer->print();
        currentCatPointer = currentCatPointer->next;
    }
}

Cat* findCat(const std::string name){
    assert( isValidName( name ) );

    for( Cat* currentCatPointer = catDatabaseHeadPointer; currentCatPointer != nullptr; currentCatPointer = currentCatPointer->next ){
        if( (name.compare(currentCatPointer->getName())) == 0 ){
            return currentCatPointer;
        }
    }
}