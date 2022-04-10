#include <cstdlib>  // For EXIT_SUCCESS / EXIT_FAILURE
#include <cassert>  // For assert()
#include <cstring>  // For strcmp()
#include <exception>  // For try/catch blocks
#include <iostream>

#include "config.h"
#include "addCats.h"
#include "reportCats.h"
#include "deleteCats.h"

using namespace std ;

/// @internal Used to test the largest possible name
#define MAX_NAME1    "1234567890123456789012345678901234567890123456789"

/// @internal Used to test an illegal name (because it's too large by
///           one character)
#define ILLEGAL_NAME "12345678901234567890123456789012345678901234567890"

#define DEBUG

/// The entry point for Animal Farm
int main() {
    cout << "Starting " << PROGRAM_NAME << endl ;

   #ifdef DEBUG
    {
        // Verify that a cat's default values are set
        Cat testCat = Cat();
        assert(testCat.getName() != nullptr );
        assert(strcmp(testCat.getName(), "") == 0);
        assert(testCat.getGender() == UNKNOWN_GENDER);
        assert(testCat.getBreed() == UNKNOWN_BREED);
        assert(testCat.checkIsFixed() == false);
        assert(testCat.getWeight() == UNKNOWN_WEIGHT);
        assert(!testCat.checkIsFixed());
        assert(!testCat.validate());  // The default cat is invalid

        // Test for NULL name
        try {
            testCat.setName(nullptr);
            assert(false); // We should never get here
        } catch (exception const &e) {}

        // Test for empty name
        try {
            testCat.setName("");
            assert(false); // We should never get here
        } catch (exception const &e) {}

        // Test valid names
        testCat.setName("A");       // A 1 character name is valid
        testCat.setName(MAX_NAME1); // A MAX_NAME1 name is valid

        // Test for name too large
        try {
            testCat.setName(ILLEGAL_NAME);
            assert(false); // We should never get here
        } catch (exception const &e) {}

        testCat.setGender(FEMALE);

        try {
            testCat.setGender(MALE);
            assert(false); // We should never get here
        } catch (exception const &e) {}

        testCat.setBreed(MAINE_COON);

        try {
            testCat.setBreed(MANX);
            assert(false); // We should never get here
        } catch (exception const &e) {}

        testCat.fixCat();
        assert(testCat.checkIsFixed());

        // Test for Weight <= 0
        try {
            testCat.setWeight(0);
            assert(false); // We should never get here
        } catch (exception const &e) {}

        testCat.setWeight(1.0 / 1024);
        assert(testCat.getWeight() == 1.0 / 1024);

        assert(testCat.validate());  // The cat should now be valid
        testCat.print() ;
    }
   #endif

   bool result ;
    result = addCat( new Cat( "Loki", MALE, PERSIAN, 1.0 )) ;
    assert( result ) ;
    if( !result ) throw logic_error (PROGRAM_NAME ": addCat() failed" ) ;
    result = addCat( new Cat( "Milo", MALE, MANX , 1.1 )) ;
    assert( result ) ;
    result = addCat( new Cat( "Bella", FEMALE, MAINE_COON, 1.2 )) ;
    assert( result ) ;
    result = addCat( new Cat( "Kali", FEMALE, SHORTHAIR, 1.3 )) ;
    assert( result ) ;
    result = addCat( new Cat( "Trin", FEMALE, MANX, 1.4 )) ;
    assert( result ) ;
    result = addCat( new Cat( "Chili", MALE, SHORTHAIR, 1.5 )) ;
    assert( result ) ;

   #ifdef DEBUG
    {
        // Test finding a cat...
        Cat *bella = findCat("Bella");
        assert(bella != nullptr);
        // Test not finding a cat
        assert(findCat("Bella's not here") == nullptr);

        // Test deleting a cat...
        assert(deleteCat(bella) == true);
        try {
            deleteCat(bella); // Verify that Bella's not there
        } catch (exception const &e) {}

        bella = nullptr;
    }
   #endif

   printAllCats() ;

    deleteAllCats() ;

    printAllCats() ;

    cout << "Done with " << PROGRAM_NAME ;

    return( EXIT_SUCCESS ) ;
}