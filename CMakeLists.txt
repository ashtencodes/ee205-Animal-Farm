cmake_minimum_required(VERSION 3.22)
project(ee205-Animal-Farm)

set(CMAKE_CXX_STANDARD 14)

add_executable(ee205-Animal-Farm catDatabase.cpp catDatabase.h addCats.cpp addCats.h config.h deleteCats.cpp deleteCats.h reportCats.cpp reportCats.h main.cpp Weight.cpp Weight.h Gender.h Breed.h Color.h Node.cpp Node.h Cat.cpp Cat.h List.cpp List.h Animal.cpp Animal.h SinglyLinkedList.cpp SinglyLinkedList.h Mammal.cpp Mammal.h)
