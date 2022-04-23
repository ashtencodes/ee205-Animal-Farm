cmake_minimum_required(VERSION 3.22)
project(ee205-Animal-Farm)

set(CMAKE_CXX_STANDARD 14)

add_executable(ee205-Animal-Farm config.h main.cpp Weight.cpp Weight.h Gender.h Breed.h Color.h Node.cpp Node.h List.cpp List.h Animal.cpp Animal.h SinglyLinkedList.cpp SinglyLinkedList.h Mammal.cpp Mammal.h Cat.cpp Cat.h)
