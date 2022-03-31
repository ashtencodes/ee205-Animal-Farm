///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file animalfarm.cpp
/// @version 1.0
///
/// @author @Ashten Akemoto <aakemoto@hawaii.edu>
/// @date   19_Mar_2022
///////////////////////////////////////////////////////////////////////////////
using namespace std;

#include <iostream>
#include <assert.h>

#include "config.h"
#include "addCats.h"
#include "reportCats.h"
#include "updateCats.h"
#include "deleteCats.h"

#define MAX_NAME1 "1234567890123456789012345678901234567890123456789"
#define MAX_NAME2 "DIFFERENT 123456789012345678901234567890123456789"
#define ILLEGAL_NAME "12345678901234567890123456789012345678901234567890"
//#define DEBUG

int main(){
    cout << "Starting " << PROGRAM_NAME << endl;
    addCat( "Loki", MALE, PERSIAN, true, 8.5, BLACK, WHITE, 101 ) ;
    addCat( "Milo", MALE, MANX, true, 7.0, BLACK, RED, 102 ) ;
    addCat( "Bella", FEMALE, MAINE_COON, true, 18.2, BLACK, BLUE, 103 ) ;
    addCat( "Kali", FEMALE, SHORTHAIR, false, 9.2, BLACK, GREEN, 104 ) ;
    addCat( "Trin", FEMALE, MANX, true, 12.2, BLACK, PINK, 105 ) ;
    addCat( "Chili", UNKNOWN_GENDER, SHORTHAIR, false, 19.0, WHITE, BLACK, 106 ) ;
#ifdef DEBUG
    // Test for empty name
    assert( addCat( "", UNKNOWN_GENDER, SHORTHAIR, false, 19.0, BLACK, WHITE, 101 ) == false ) ;
    // Test for max name
    assert( addCat( MAX_NAME1, UNKNOWN_GENDER, SHORTHAIR, false, 19.0, WHITE, RED, 107 ) == true ) ;
    // Test for name too long
    assert( addCat( ILLEGAL_NAME, UNKNOWN_GENDER, SHORTHAIR, false, 19.0, WHITE, BLUE, 108 ) == false ) ;
    // Test for duplicate cat name
    assert( addCat( "Chili", UNKNOWN_GENDER, SHORTHAIR, false, 0, WHITE, GREEN, 109 ) == false ) ;
    // Test for weight <= 0
    assert( addCat( "Neo", UNKNOWN_GENDER, SHORTHAIR, false, 0, WHITE, PINK, 110 ) == false ) ;
    // Test for printCat( -1 ) ;
    assert( printCat( -1 ) == false );
    // Test for out of bounds
    assert ( printCat( 2000 ) == false );
    // Test finding a cat...
    assert( findCat( "Bella" ) == 2 ) ;
    // Test not finding a cat
    assert( findCat( "Bella's not here" ) == -1 ) ;
#endif
    printAllCats() ;
    int kali = findCat( "Kali" ) ;
    assert( updateCatName( kali, "Chili" ) == false ) ; // duplicate cat name should fail
    printCat( kali ) ;
    assert( updateCatName( kali, "Capulet" ) == true ) ;
    assert( updateCatWeight( kali, 9.9 ) == true ) ;
    assert( fixCat( kali ) == true ) ;
    assert( updateCollar1( kali, GREEN ) == true ) ;
    assert( updateCollar2( kali, GREEN ) == true ) ;
    assert( updateLicense( kali, 201 ) == true ) ;
    printCat( kali ) ;
    printAllCats() ;
    deleteAllCats() ;
    printAllCats() ;
    cout << "Done with " << PROGRAM_NAME << endl;
    return( 1 ) ;
}
