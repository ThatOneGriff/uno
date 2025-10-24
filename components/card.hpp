#pragma once
#ifndef CARD_HPP
#define CARD_HPP

#include <string>
#include <unordered_map>

#include "../helpers/ui.hpp"
#include "../helpers/helpers.hpp"

const unsigned int TOTAL_CARDS = 108;
const char PLUS_2 = '+'+2, PLUS_4 = '+'+4; /// Only adequate way of assigning "+4"/"+2" to a char.
const std::unordered_map<char, std::string> CARD_TYPE_FULL_NAMES =
{
    {'0', "0"}, {'1', "1"}, {'2', "2"}, {'3', "3"}, {'4', "4"},
    {'5', "5"}, {'6', "6"}, {'7', "7"}, {'8', "8"}, {'9', "9"},
    {'A', "Any"}, {'B', "Block"}, {'R', "Reverse"},
    {PLUS_2, "+2"}, {PLUS_4, "+4"}
};

/// Here be:

struct Card;
bool can_stack(const Card& card1, const Card& card2);


struct Card
{
    char type;
    Color color;

    /// For compiler.
    Card()
    {}

    /// Copy ctor.
    Card(const Card& to_copy)
    : type(to_copy.type), color(to_copy.color)
    {}

    Card(const char _type, const Color _color)
    : type(_type), color(_color)
    {
        if (CARD_TYPE_FULL_NAMES.find(_type) == CARD_TYPE_FULL_NAMES.end())
            std::cerr << RED << ">> Unknown short card type: " << type << "." << WHITE;
    }

    friend std::ostream& operator<<(std::ostream& outstream, const Card& card)
    {
        tc(card.color);
        outstream << CARD_TYPE_FULL_NAMES.at(card.type) << WHITE;
        return outstream;
    }

    std::string out()
    {
        tc(color);
        return CARD_TYPE_FULL_NAMES.at(type);
    }

    bool operator==(const Card& to_compare)
    {
        return type  == to_compare.type
            && color == to_compare.color;
    }
    
    Card& operator=(const Card& to_set_as)
    {
        type  = to_set_as.type;
        color = to_set_as.color;
        return *this;
    }
};


/// UNTESTED
bool can_stack(const Card& card1, const Card& card2)
{
    if (card1.type == 'A' && card2.type == 'A') return true; /// "Any" stacks on "Any"
    if (in(card1.type, {PLUS_2, PLUS_4}) && in(card1.type, {PLUS_2, PLUS_4})) return true; /// "+" cards stack on "+" cards
    return card1.type  == card2.type
        || card1.color == card2.color;
}


#endif /// CARD_HPP