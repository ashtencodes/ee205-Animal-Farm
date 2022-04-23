using namespace std;

#include <iostream>
#include "config.h"
#include "SinglyLinkedList.h"
#include "Color.h"
#include "Cat.h"

int main() {
    cout << "Starting " << PROGRAM_TITLE << endl ;
    SinglyLinkedList catDB ;
    catDB.pushFront( new Cat( "Loki", Color::CREAM, true, Gender::MALE, 1.0 ) ) ;
    catDB.pushFront( new Cat( "Milo", Color::BLACK, true, Gender::MALE, 1.1 ) ) ;
    catDB.pushFront( new Cat( "Bella", Color::BROWN, true, Gender::FEMALE, 1.2 ) ) ;
    catDB.pushFront( new Cat( "Kali", Color::CALICO, true, Gender::FEMALE, 1.3 ) ) ;
    catDB.pushFront( new Cat( "Trin", Color::WHITE, true, Gender::FEMALE, 1.4 ) ) ;
    catDB.insertAfter(catDB.getFirst(), new Cat( "Chili", Color::GINGER, true,
                                                   Gender::MALE, 1.5 ) );
    for( Animal* pAnimal = (Animal*)catDB.getFirst() ; pAnimal != nullptr ; pAnimal =
            (Animal*)List::getNext( (Node*)pAnimal ) ) {
        cout << pAnimal->speak() << endl;
    }
    //catDB.validate() ;
    catDB.dump() ;
    catDB.deleteAllNodes() ;
    catDB.dump() ;
    cout << "Done with " << PROGRAM_TITLE ;
    return( EXIT_SUCCESS ) ;
}