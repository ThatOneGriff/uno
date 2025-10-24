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
    /// Pile pointers for any-time access. Ignore warnings.
    inline static std::vector<Card*>* draw_pile;
    inline static std::vector<Card*>* discard_pile;

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

        for (unsigned int i = 1; i <= draw_amount; i++) /// `i` is merely an iterator here; we `pop_back()` instead of accessing a position through `i`.
        {
            cards.push_back((*draw_pile)[draw_pile->size()-1]);
            draw_pile->pop_back();
        }

        //std::sort(cards.begin(), cards.end(), Card::operator<);
    }
    
    /// WARNING: will probably break if there's nothing to draw.
    void draw_until(Card* to_parry) // sort when adding
    {
        for (unsigned int i = 1; i <= draw_pile->size(); i++) /// `i` is merely an iterator here; we `pop_back()` instead of accessing a position through `i`.
        {
            Card* drawn = (*draw_pile)[draw_pile->size()-1];
            cards.push_back(drawn);
            if (can_stack(to_parry, drawn))
                break;
            draw_pile->pop_back(); // UNTESTED
        }

        std::sort(cards.begin(), cards.end(), Card::operator<);
    }

    void show_info()
    {
        std::cout << (cards[1] < cards[2]);
        output(cards);
    }

    void parry(Card* to_parry)
    {
        std::vector<Card*> cards = find_cards_to_parry(to_parry);
        if (cards.empty())
            draw_until(to_parry);
        
        cards = find_cards_to_parry(to_parry);
        discard_pile->insert(discard_pile->end(), cards.begin(), cards.end());
    }

private:
    std::vector<Card*> cards = {};

    std::vector<Card*> find_cards_to_parry(Card* to_parry)
    {
        std::vector<Card*> result = {};

        Card* to_stack_on = to_parry; /// So the bot can throw multiple cards.
        /// IDEA: could be binary search (if we sort hand automatically).
        for (unsigned int i = 0; i < cards.size(); i++)
        {
            Card* curr_card = cards[i];
            if (! can_stack(to_stack_on, curr_card))
                continue;
            
            result.push_back(curr_card);
            cards.erase(cards.begin() + i);
            to_stack_on = curr_card;
        }

        return result;
    }
};


#endif /// HAND_HPP