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
#include "config.h"
#include <cassert>

SinglyLinkedList::SinglyLinkedList() {}

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
    std::cout << "SinglyLinkedList: head=[" << head << "]" << std::endl;
    if( head != nullptr ){
        Node* iteratorNode = head;
        for( int i = 0; i < size(); i++ ){
            PRINT_HEADING_FOR_DUMP;
            iteratorNode->dumpNode();
            iteratorNode->dump();
            iteratorNode = iteratorNode->next;
        }
        PRINT_HEADING_FOR_DUMP;
    }
}

bool SinglyLinkedList::validate() const noexcept {
    if( head != nullptr ){
        Node* iteratorNode = head;
        for( int i = 0; i < size(); i++ ){
            iteratorNode->validate();
            iteratorNode = iteratorNode->next;
        }
    }
    return true;
}
