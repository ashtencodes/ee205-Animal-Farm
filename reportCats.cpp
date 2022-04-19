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

#include "reportCats.h"
#include "config.h"

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


