#pragma once
#ifndef CARD_HPP
#define CARD_HPP

#include <string>

#include "../helpers/ui.hpp"
#include "../helpers/helper.hpp"

/// Here be:

struct Card;
bool can_stack(const Card& card1, const Card& card2);


struct Card
{
    const std::string type = "";
    const Color color;

    Card(const std::string& _type, const Color _color)
    : type(_type), color(_color)
    {}

    std::string out()
    {
        tc(color);
        return type;
    }

    operator==(const Card& to_compare)
    {
        return type  == to_compare.type
            && color == to_compare.color;
    }
};


bool can_stack(const Card& card1, const Card& card2)
{
    return card1.type  == card2.type
        || card1.color == card2.color;
}


#endif /// CARD_HPP