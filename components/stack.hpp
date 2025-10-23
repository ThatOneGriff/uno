#pragma once
#ifndef HEADER_HPP
#define HEADER_HPP

#include <vector>

#include "../helpers/helper.hpp"
#include "card.hpp"

/// Here be:

std::vector<Card> _init_stack();

const unsigned int TOTAL_CARDS = 108;
const std::vector<Card> INITIAL_STACK = _init_stack();


/// Used for initializing `ORIGINAL_STACK`, unshuffled. Should not be used otherwise.
std::vector<Card> _init_stack()
{
    std::vector<Card> result;
    result.reserve(TOTAL_CARDS);
    
    /// There are, surprisingly, 4 '0's instead of 8.
    for (int i = 0; i < 4; i++)
        result.push_back(Card('0', COLORS_RAINBOW_SORTED[i]));
    
    return result;
}


#endif /// HEADER_HPP