#include <iostream>
#include <vector>
#include <windows.h>

#include "components/card.hpp"
#include "components/character.hpp"
#include "components/hand.hpp"
#include "components/stack.hpp"

#include "helpers/ui.hpp"
#include "helpers/random.hpp"


/*
= TODOs:
- A block-scheme of how I play Uno (?)

= IDEAs:
- Different `Hand` classes for bot and player?
*/


int main()
{
    //std::cout << GREEN << "This is the start of this project.\n" << WHITE;

    /* Preparing the cards */
    /// IMPORTANT: top of the pile is vector's back.
    std::vector<Card*> draw_pile = shuffled(DECK);
    Hand::draw_pile = &draw_pile;
    output(draw_pile); // TEST
    std::cout << '\n';

    std::vector<Card*> discard_pile = {};
    discard_pile.reserve(108);
    Hand::discard_pile = &discard_pile;

    Bot bot;
    bot.hand.draw(7);

    // TEST
    bot.show_info();
    std::cout << '\n';
    output(draw_pile);

    return 0;
}