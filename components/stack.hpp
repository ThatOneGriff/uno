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
    
    /// '0' (x4). I was surprised.
    for (unsigned int j = 0; j < 4; j++)
        result.push_back(Card('0', COLORS_RAINBOW_SORTED[j]));
    
    /// Regular numbers (x8)
    for (char type = '1'; type <= '9'; type++)
    {
        for (unsigned int j = 0; j < 8; j++)
            result.push_back(Card(type, COLORS_RAINBOW_SORTED[j/2])); /// So that colors line up
    }

    /// Special cards (x8)
    const char special_cards_x8[4] = {'A', 'B', 'R', PLUS_2};
    for (int i = 0; i < 4; i++)
    {
        const char type = special_cards_x8[i];
        for (unsigned int j = 0; j < 8; j++)
            result.push_back(Card(type, COLORS_RAINBOW_SORTED[j/2])); /// So that colors line up
    }

    /// +4 (x4)
    for (unsigned int j = 0; j < 4; j++)
        result.push_back(Card(PLUS_4, COLORS_RAINBOW_SORTED[j]));
    
    return result;
}


#endif /// HEADER_HPP