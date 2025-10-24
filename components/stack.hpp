#pragma once
#ifndef HEADER_HPP
#define HEADER_HPP

#include <vector>

#include "card.hpp"
#include "../helpers/helpers.hpp"
#include "../helpers/random.hpp"

/// Here be:

std::vector<Card*> _init_deck();
const std::vector<Card*> DECK = _init_deck();


/// Used for ordered initialization of `DECK`. Should not be used otherwise.
std::vector<Card*> _init_deck()
{
    if (! DECK.empty())
        std::cerr << RED << ">> `_init_deck(v)` should not be used manually." << WHITE;
    
    std::vector<Card*> deck;
    deck.reserve(TOTAL_CARDS);
    
    /// "0" (x4). I was surprised.
    for (unsigned int j = 0; j < 4; j++)
    {
        Card* card = new Card('0', COLORS_RAINBOW_SORTED[j]);
        deck.push_back(card);
    }
    
    /// Regular numbers (x8)
    for (char type = '1'; type <= '9'; type++)
    {
        for (unsigned int j = 0; j < 8; j++)
        {
            Card* card = new Card(type, COLORS_RAINBOW_SORTED[j/2]); /// `j/2` so that the colors line up
            deck.push_back(card);
        }
    }

    /// Special cards (x8)
    const char special_cards_x8[4] = {'A', 'B', 'R', PLUS_2};
    for (int i = 0; i < 4; i++)
    {
        const char type = special_cards_x8[i];
        for (unsigned int j = 0; j < 8; j++)
        {
            Card* card = new Card(type, COLORS_RAINBOW_SORTED[j/2]); /// `j/2` so that the colors line up
            deck.push_back(card);
        }
    }

    /// "+4" (x4)
    for (unsigned int j = 0; j < 4; j++)
    {
        Card* card = new Card(PLUS_4, COLORS_RAINBOW_SORTED[j]);
        deck.push_back(card);
    }
    
    return deck;
}


#endif /// HEADER_HPP