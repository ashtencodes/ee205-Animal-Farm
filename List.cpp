///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205-Animal-Farm - EE 205 - Spr 2022
///
/// @file List.cpp
/// @version 1.0
///
/// @author @Ashten Akemoto <aakemoto@hawaii.edu>
/// @date   21_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#include <stdexcept>
#include "List.h"

bool List::isEmpty() const noexcept {
    return (head == nullptr);
}

unsigned int List::size() const noexcept {
    return elementCount;
}

bool List::isIn(Node *aNode) const noexcept {
    if(aNode == nullptr){
        throw std::invalid_argument("Cant search for nullptr");
    }

    Node* currentNode = head;

    while(currentNode != nullptr){
        if(currentNode = aNode){
            return true;
        }
        currentNode = currentNode->next;
    }

    return false;
}

bool List::isSorted() const noexcept {
    if ( elementCount < 1 ){
        return true;
    }
    for( Node* node = head; node->next != nullptr; node = node->next ){
        if( *node > *node->next ){
            return false;
        }
        return true;
    }
    return false;
}

Node *List::getFirst() const noexcept {
    return head;
}

Node *List::getNext(const Node *currentNode) {
    if(currentNode == nullptr){
        throw std::invalid_argument("Can't find next node after nullptr!");
    }
    return currentNode->next;
}

void List::deleteAllNodes() noexcept {
    while( head != nullptr ){
        popFront();
    }
}


