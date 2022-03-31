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
    Cat* Loki = new Cat("Loki", MALE, PERSIAN, 1.0);
    addCat(Loki);
    Cat* Milo = new Cat("Milo", MALE, MANX, 1.1);
    addCat(Milo);
    Cat* Bella = new Cat("Bella", FEMALE, MAINE_COON, 1.2);
    addCat(Bella);
    Cat* Kali = new Cat("Kali", FEMALE, SHORTHAIR, 1.3);
    addCat(Kali);
    Cat* Trin = new Cat("Trin", FEMALE, MANX, 1.4);
    addCat(Trin);
    Cat* Chili = new Cat("Chili", MALE, SHORTHAIR, 1.5);
    addCat(Chili);
    printAllCats();
    deleteCat(Chili);
    cout << endl;
    printAllCats();
    cout << endl;
    deleteAllCats();
    cout << endl;
    printAllCats();
    cout << "Done with " << PROGRAM_NAME << endl;
    return( 1 ) ;
}
