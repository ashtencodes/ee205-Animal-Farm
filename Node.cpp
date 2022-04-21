///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205-Animal-Farm - EE 205 - Spr 2022
///
/// @file Node.cpp
/// @version 1.0
///
/// @author @Ashten Akemoto <aakemoto@hawaii.edu>
/// @date   21_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#include "Node.h"
#include "config.h"

void Node::dump() const {
    FORMAT_LINE_FOR_DUMP( "Node", "this" ) << this << std::endl;
    FORMAT_LINE_FOR_DUMP( "Node", "next" ) << next << std::endl;
}

bool Node::validate() const noexcept {
    if(next == nullptr){
        return true;
    }
    if(next == next->next){
        return false;
    }
    return true;
}

bool Node::operator>(const Node &rhSide) {
    return(compareByAddress(this, &(Node&)rhSide));
}

bool Node::compareByAddress(const Node* Node1, const Node* Node2) {
    if (Node1 > Node2){
        return true;
    } else {
        return false;
    }
}
