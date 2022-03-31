cmake_minimum_required(VERSION 3.22)
project(ee205-Animal-Farm)

set(CMAKE_CXX_STANDARD 14)

add_executable(ee205-Animal-Farm animalfarm.cpp addCats.cpp addCats.h config.h catDatabase.cpp catDatabase.h deleteCats.cpp deleteCats.h reportCats.cpp reportCats.h updateCats.cpp updateCats.h)
