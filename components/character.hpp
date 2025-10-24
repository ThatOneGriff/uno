#pragma once
#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "card.hpp"
#include "hand.hpp"

/// Here be:

class Character;
class Bot;
class Player;


class Character
{
public:
    Character()
    {}

    virtual void parry(Card* to_parry) = 0;

protected:
    Hand hand;
};


class Bot : public Character
{
public:
    Bot(std::vector<Card*>& _draw_pile)
    {
        hand.character_type = BOT_HAND;
    }

    void parry(Card* to_parry)
    {

    }
};


#endif /// CHARACTER_HPP