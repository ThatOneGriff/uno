#include <iostream>
#include <vector>
#include <windows.h>

#include "components/card.hpp"
#include "components/character.hpp"
#include "components/stack.hpp"

#include "helpers/ui.hpp"

/*
= TODOs:


= IDEAs:
- `textcolor(GREEN + BLINK);` - https://www.includehelp.com/c-programs/textcolor-and-textbackground-functions-of-conio-h.aspx
*/

int main()
{
    std::cout << GREEN << "This is the start of this project.\n" << WHITE;
    std::vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    output(a);

    // Shuffle test
    for (int i = 0; i < 5; i++)
    {
        shuffle(a);
        output(a);
    }

    return 0;
}