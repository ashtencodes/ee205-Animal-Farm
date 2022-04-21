///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205-Animal-Farm - EE 205 - Spr 2022
///
/// @file List.h
/// @version 1.0
///
/// @author @Ashten Akemoto <aakemoto@hawaii.edu>
/// @date   21_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#pragma once
#include "Node.h"

class List {

protected:
    Node* head;
    unsigned int elementCount;

public:
    bool isEmpty() const noexcept;
    unsigned int size() const noexcept;
    bool isIn(Node* aNode) const noexcept;
    bool isSorted() const noexcept;

    Node* getFirst() const noexcept;
    void deleteAllNodes() noexcept;
    virtual Node* popFront() noexcept=0;
    virtual void dump() noexcept=0;
    virtual bool vaildate() const noexcept=0;

    static Node* getNext(const Node* currentNode);
};