///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205-Animal-Farm - EE 205 - Spr 2022
///
/// @file catDatabase.h
/// @version 1.0
///
/// @author @Ashten Akemoto <aakemoto@hawaii.edu>
/// @date   31-Mar-2022
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include "Gender.h"
#include "Breed.h"
#include "Color.h"
#include "Weight.h"

#include <stdbool.h>
#include <cstring>
#include <cassert>
#include <string>

#define NAME_LEN_MAX 50

typedef int NumCat;

extern bool validateDatabase();
extern bool isValidName( const std::string checkName );
extern bool isValidWeight( const Weight checkWeight ) ;

extern NumCat currentCatNum;

