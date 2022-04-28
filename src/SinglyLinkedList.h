///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205-Animal-Farm - EE 205 - Spr 2022
///
/// @file SinglyLinkedList.h
/// @version 1.0
///
/// @author @Ashten Akemoto <aakemoto@hawaii.edu>
/// @date   21_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#pragma once
#include "Node.h"
#include "List.h"

class SinglyLinkedList : public List {
public:
    SinglyLinkedList();
    void pushFront( Node* newNode );
    void insertAfter( Node* currentNode, Node* newNode );
    Node* popFront() noexcept override;
    void dump() noexcept override;
    bool validate() const noexcept override;
};