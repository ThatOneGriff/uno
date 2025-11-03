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
    Hand hand;

    Character()
    {
        hand.draw(7);
    }

    virtual void parry(Card* to_parry) = 0;
    virtual void show_info() = 0;
};


class Bot : public Character
{
public:
    Bot()
    {}

    void parry(Card* to_parry)
    {
        hand.parry(to_parry);
    }

    void show_info()
    {
        hand.show_info();
    }
};


class Player : public Character
{
public:
    Player()
    {}

    void parry(Card* to_parry)
    {
        hand.parry(to_parry);
    }

    void show_info()
    {
        hand.show_info();
    }
};


#endif /// CHARACTER_HPP