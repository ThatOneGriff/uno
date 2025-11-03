#include <iostream>
#include <vector>
#include <windows.h>

#include "components/card.hpp"
#include "components/character.hpp"
#include "components/deck_init.hpp"
#include "components/hand.hpp"

#include "helpers/ui.hpp"
#include "helpers/random.hpp"


/*
= TODOs:
- A block-scheme of how I play Uno (?)

= IDEAs:
- Different `Hand` classes for bot and player?
- Peeping mechanic (fine if noticed: +2 cards)
*/


int main()
{
    /* Preparing the cards */
    std::vector<Card*> draw_pile = shuffled(DECK);
    std::vector<Card*> discard_pile = {};
    discard_pile.reserve(108);

    Hand::draw_pile = &draw_pile;
    Hand::discard_pile = &discard_pile;

    Bot bot;
    Player player;

    std::cout << "- Bot: ";
    bot.show_info();
    std::cout << "- You: ";
    player.show_info();

    std::string code;
    while (true)
    {
        std::cout << "\n> ";
        std::cin >> code;
        Card* card = code_to_card(code);
        std::cout << card;
    }

    return 0;
}