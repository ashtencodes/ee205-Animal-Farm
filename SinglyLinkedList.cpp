///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205-Animal-Farm - EE 205 - Spr 2022
///
/// @file SinglyLinkedList.cpp
/// @version 1.0
///
/// @author @Ashten Akemoto <aakemoto@hawaii.edu>
/// @date   21_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#include "SinglyLinkedList.h"
#include <cassert>

SinglyLinkedList::SinglyLinkedList() {
}

void SinglyLinkedList::pushFront( Node *newNode ) {
    assert( validate() );
    assert( newNode != nullptr );

    if( head != nullptr ){
        newNode->next = head;
        head = newNode;
    } else {
        newNode->next = nullptr;
        head = newNode;
    }

    elementCount++;
}

void SinglyLinkedList::insertAfter( Node *currentNode, Node *newNode ) {
    assert( validate() );
    assert( newNode != nullptr );
    assert( currentNode != nullptr );

    newNode->next = currentNode->next;
    currentNode->next = newNode;
    elementCount++;

}

Node *SinglyLinkedList::popFront() noexcept {
    assert( validate() );

    if(head == nullptr){
        return nullptr;
    }

    Node* poppedNode = head;

    if(head->next == nullptr){
        head = nullptr;
    } else {
        head = head->next;
    }

    poppedNode->next = nullptr;
    elementCount--;

    return poppedNode;
}

void SinglyLinkedList::dump() noexcept {
    for( Node* iteratorNode = head; iteratorNode->next != nullptr; iteratorNode = iteratorNode->next ){
        iteratorNode->dump();
    }
}

bool SinglyLinkedList::validate() const noexcept {
    for( Node* iteratorNode = head; iteratorNode->next != nullptr; iteratorNode = iteratorNode->next ){
        iteratorNode->validate();
    }
}
