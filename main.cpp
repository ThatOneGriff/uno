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
- [!!!] `Card`s as ptrs to a set of unique 108 `Card`s.
- `textcolor(GREEN + BLINK);` - https://www.includehelp.com/c-programs/textcolor-and-textbackground-functions-of-conio-h.aspx
*/


int main()
{
    //std::cout << GREEN << "This is the start of this project.\n" << WHITE;

    std::vector<Card> game_stack = shuffled(INITIAL_STACK);
    output(game_stack);

    return 0;
}