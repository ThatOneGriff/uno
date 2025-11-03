#pragma once
#ifndef HAND_HPP
#define HAND_HPP

#include <algorithm>
#include <vector>

#include "card.hpp"


struct Hand
{
public:
    /// Pile pointers for any-time access. Ignore warnings.
    inline static std::vector<Card*>* draw_pile;
    inline static std::vector<Card*>* discard_pile;

    Hand()
    {
        cards.reserve(TOTAL_CARDS);
    }

    /// WARNING: no way to logically handle an empty pile. It won't result in a crash; just nothing will happen in that case.
    void draw(unsigned int draw_amount) // sort when adding
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
    
    /// WARNING: no way to logically handle an empty pile
    void draw_until(Card* to_parry) // sort when adding
    {
        for (unsigned int i = 1; i <= draw_pile->size(); i++) /// `i` is merely an iterator here; we `pop_back()` instead of access by index.
        {
            Card* drawn = (*draw_pile)[draw_pile->size()-1];
            cards.push_back(drawn);
            if (can_stack(to_parry, drawn))
                break;
            draw_pile->pop_back();
        }

        //std::sort(cards.begin(), cards.end(), Card::operator<);
    }

    void show_info()
    {
        output(cards);
    }

    void throw_card(const std::string& code)
    {
        Card* pick = pick_out_card(code_to_card(code));
        if (pick == nullptr)
            return;
        
        discard_pile->push_back(pick);
    }

    void parry(Card* to_parry)
    {
        std::vector<Card*> options = pick_out_cards_to_parry(to_parry);
        if (options.empty())
            draw_until(to_parry);
        
        options = pick_out_cards_to_parry(to_parry);
        discard_pile->insert(discard_pile->end(), options.begin(), options.end());
    }

private:
    std::vector<Card*> cards = {};

    Card* pick_out_card(const Card& to_find)
    {
        if (to_find == NULL_CARD)
            return nullptr;
        
        /// IDEA: could be binary search (if we sort hand automatically).
        for (unsigned int i = 0; i < cards.size(); i++)
        {
            Card* curr_card = cards[i];
            if (curr_card != to_find)
                continue;
            
            cards.erase(cards.begin() + i);
            return curr_card;
        }

        return nullptr;
    }

    std::vector<Card*> pick_out_cards_to_parry(Card* to_parry)
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