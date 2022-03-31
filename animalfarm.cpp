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

int main(){
    cout << "Starting " << PROGRAM_NAME << endl;
    Cat("Loki", MALE, PERSIAN, 1.0);
    Cat("Milo", MALE, MANX, 1.1);
    Cat("Bella", FEMALE, MAINE_COON, 1.2);
    Cat("Kali", FEMALE, SHORTHAIR, 1.3);
    Cat("Trin", FEMALE, MANX, 1.4);
    Cat("Chili", MALE, SHORTHAIR, 1.5);
    cout << "Done with " << PROGRAM_NAME << endl;
    return( 1 ) ;
}
