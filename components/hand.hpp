#pragma once
#ifndef HAND_HPP
#define HAND_HPP

#include <algorithm>
#include <vector>

#include "card.hpp"


struct Hand
{
public:
    /// Init = drawing 7 cards. IDEA: consider it may be changeable by game rules.
    Hand(std::vector<Card*>& game_stack)
    {
        cards.reserve(TOTAL_CARDS);
        for (unsigned int i = 0; i < 7; i++)
            cards.push_back(game_stack[i]);

        game_stack.erase(game_stack.begin(), game_stack.begin() + 7); /// UNTESTED
    }

    void add(); // + sort

private:
    std::vector<Card*> cards = {};
};


#endif /// HAND_HPP