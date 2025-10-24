#pragma once
#ifndef HAND_HPP
#define HAND_HPP

#include <algorithm>
#include <vector>

#include "card.hpp"

#define PLAYER_HAND true
#define BOT_HAND false


struct Hand
{
public:
    bool character_type; /// NOTE: non-const because hand swap exists.
    inline static std::vector<Card*>* draw_pile; /// Draw pile pointer for any-time access.
    //static int* a;

    Hand()
    {
        cards.reserve(TOTAL_CARDS);
    }

    void draw(unsigned int draw_amount = 1) // sort when adding
    {
        if (draw_amount == 0)
            return;
        else if (draw_amount > draw_pile->size())
            draw_amount = draw_pile->size();

        for (unsigned int i = 0; i < draw_amount; i++)
            cards.push_back((*draw_pile)[i]);

        draw_pile->erase(draw_pile->begin(), draw_pile->begin() + draw_amount); /// UNTESTED
    }
    
    /// WARNING: will probably break if there's nothing to draw.
    void draw_until(Card* to_parry) // sort when adding
    {
        unsigned int i = 0;
        for ( ; i < draw_pile->size(); i++)
        {
            Card* drawn = (*draw_pile)[i];
            cards.push_back(drawn);
            if (can_stack(to_parry, drawn))
                break;
        }

        draw_pile->erase(draw_pile->begin(), draw_pile->begin() + i); /// UNTESTED
    }

    //std::vector<Card*> parry(Card* to_parry)
    //{
    //    if (! has_ca)
    //}

private:
    std::vector<Card*> cards = {};

    bool has_cards_to_parry(Card* to_parry)
    {
        for (Card* curr_card : cards)
        {
            if (can_stack(to_parry, curr_card))
                return true;
        }
        return false;
    }
};


#endif /// HAND_HPP