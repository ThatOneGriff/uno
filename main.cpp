#include <iostream>
#include <vector>
#include <windows.h>

#include "components/card.hpp"
#include "components/character.hpp"
#include "components/stack.hpp"

#include "helpers/ui.hpp"
#include "helpers/random.hpp"


/*
= TODOs:


= IDEAs:
- `textcolor(GREEN + BLINK);` - https://www.includehelp.com/c-programs/textcolor-and-textbackground-functions-of-conio-h.aspx
*/


int main()
{
    //std::cout << GREEN << "This is the start of this project.\n" << WHITE;

    /* Preparing the cards */
    std::vector<Card*> draw_pile = shuffled(DECK);
    std::vector<Card*> discard_pile = {};
    discard_pile.reserve(108);

    //output(DECK);
    //std::cout << '\n';
    //output(draw_pile);

    return 0;
}