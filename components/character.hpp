#pragma once
#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "card.hpp"
#include "hand.hpp"


class Character
{
public:
    /*Character(std::vector<Card>* game_stack)
    {
        hand.reserve(108);
        for (unsigned int i = 0; i < 7; i++)
        {
            hand.push_back(*game_stack[i]);
            game_stack->erase(i); /// IDEA: do it at the end?
        }
    }

    /// TODO: make virtual.
    /// - Bots pull automatically;
    /// - Player pulls until they 
    void pull_until(const Card& reference, std::vector<Card>* game_stack)
    {
        /// WARNING: although a situation where there are no cards to pull is ALMOST impossible,
        /// we should consider it when debugging or rewriting this system.
        for (unsigned int i = 0; i < game_stack->size(); i++)
        {
            const Card curr_card = *game_stack[i];
            hand.push_back(curr_card);
            game_stack->erase(i);
            
            if (can_stack(curr_card, reference))
                break;
        }
    }

protected:
    std::vector<Card> hand;*/
};


#endif /// CHARACTER_HPP