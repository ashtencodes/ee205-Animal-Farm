///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205-Animal-Farm - EE 205 - Spr 2022
///
/// @file Node.h
/// @version 1.0
///
/// @author @Ashten Akemoto <aakemoto@hawaii.edu>
/// @date   21_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include "Cat.h"

class Node {
    friend class List;
    friend class SinglyLinkedList;

protected:
    Node* next = nullptr;
    static bool compareByAddress( const Node* Node1, const Node* Node2 );

public:
    virtual void dump() const;
    virtual bool validate() const noexcept;

    virtual bool operator>(const Node& rhSide);
};

