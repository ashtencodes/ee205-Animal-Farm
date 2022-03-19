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

#include "reportCats.h"
#include "config.h"
#include <stdio.h>
#include <string.h>

const char* genderList[] = { "UNKNOWN_GENDER", "MALE", "FEMALE" };
const char* breedList[] = { "UNKNOWN_BREED", "MAINE_COON", "MANX", "SHORTHAIR", "PERSIAN", "SPHINX" };
const char* colorList[] = { "BLACK", "WHITE", "RED", "BLUE", "GREEN", "PINK" };

bool printCat(int indexNum){
    if( !isValidIndex(indexNum) ){
        fprintf( stderr, "%s: Bad Cat [%d]\n", PROGRAM_NAME, indexNum);
        return false;
    }
    printf("cat index = [%d] name=[%s] gender=[%s] breed=[%s] isFixed=[%d] weight=[%f], collar1=[%s], collar2=[%s], license=[%llu]\n", indexNum, catArray[indexNum].name, genderList[catArray[indexNum].gender], breedList[catArray[indexNum].breed], catArray[indexNum].isFixed, catArray[indexNum].weight, colorList[catArray[indexNum].collarColor1], colorList[catArray[indexNum].collarColor2], catArray[indexNum].license);
    return true;
}

void printAllCats(){
    for( int indexNum = 0; indexNum < MAX_NUM_CATS; indexNum++ ){
        printf("cat index = [%d] name=[%s] gender=[%s] breed=[%s] isFixed=[%d] weight=[%f], collar1=[%s], collar2=[%s], license=[%llu]\n", indexNum, catArray[indexNum].name, genderList[catArray[indexNum].gender], breedList[catArray[indexNum].breed], catArray[indexNum].isFixed, catArray[indexNum].weight, colorList[catArray[indexNum].collarColor1], colorList[catArray[indexNum].collarColor2], catArray[indexNum].license);
    }
}

int findCat(char name[]){
    int targetIndex = -1;
    for( int indexNum = 0; indexNum < MAX_NUM_CATS; indexNum++ ){
        if( strcmp(catArray[indexNum].name, name) == 0 ){
            targetIndex = indexNum;
        }
    }
    fprintf( stderr, "%s: cat index: [%d]\n", PROGRAM_NAME, targetIndex);
    return targetIndex;
}

