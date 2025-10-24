#pragma once
#ifndef HAND_HPP
#define HAND_HPP

#include <algorithm>
#include <vector>

#include "card.hpp"


struct Hand
{
public:
    Hand(std::vector<Card*>& draw_pile, const unsigned int draw_amount = 7)
    {
        cards.reserve(TOTAL_CARDS);
        for (unsigned int i = 0; i < draw_amount; i++)
            cards.push_back(draw_pile[i]);

        draw_pile.erase(draw_pile.begin(), draw_pile.begin() + 7); /// UNTESTED
    }

    void add(); // sort when adding

private:
    std::vector<Card*> cards = {};
};


#endif /// HAND_HPP