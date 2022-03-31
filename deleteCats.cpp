///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file deleteCats.cpp
/// @version 1.0
///
/// @author @Ashten Akemoto <aakemoto@hawaii.edu>
/// @date   19_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#include <string.h>
#include "deleteCats.h"
#include "catDatabase.h"
#include "config.h"

bool deleteCat(Cat* targetCatPointer){
    assert( targetCat != nullptr );
    assert( validateDatabase() );
    Cat* currentCatPointer = catDatabaseHeadPointer;

    if(currentCatPointer == targetCatPointer){
        catDatabaseHeadPointer = catDatabaseHeadPointer->next;
        delete targetCatPointer;
        currentCatNum --;

        assert( validateDatabase() );
        return true;
    }

    while(currentCatPointer != targetCatPointer){
        if(currentCatPointer == targetCatPointer){
            currentCatPointer->next = targetCatPointer->next;
            delete targetCatPointer;
            currentCatNum--;

            assert( validateDatabase() );
            return true;
        } else {
            currentCatPointer = currentCatPointer->next;
        }
    }
}

bool deleteAllCats(){
    assert( validateDatabase() );
    while(catDatabaseHeadPointer != nullptr){
        deleteCat(catDatabaseHeadPointer);
    }

    return true;
}
