#pragma once
#ifndef UI_HPP
#define UI_HPP

#include <iostream>
#include <string>    /// `tc()` returning `std::string`
#include <windows.h> /// (True) coloring


/// Here be:

enum class Color;
std::string tc(const int text_color);


/// Color insertion into `cout`.
/// - Example: `cout << GREEN << "Hi!";
#define RED     tc(int(Color::Red))
#define YELLOW  tc(int(Color::Yellow))
#define GREEN   tc(int(Color::Green))
#define BLUE    tc(int(Color::Blue))
#define WHITE   tc(int(Color::White))


enum class Color
{
    Red    = 12,
    Yellow = 14,
    Green  = 10,
    Blue   = 11,
    White  = 7,  /// UI-only
    Any    = 16  /// = white. Useless in UI, cards-only.
};


std::string tc(const int text_color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text_color);
    return std::string(); /// for insertion into `cout`
}


#endif /// UI_HPP