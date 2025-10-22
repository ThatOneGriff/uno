#pragma once
#ifndef UI_HPP
#define UI_HPP

#include <iostream>
#include <string>    /// `tc()` returning `std::string`
#include <windows.h> /// (True) coloring

/// Here be:

enum class Color;
std::string tc(Color text_color);


/// Color insertion into `cout`.
/// - Example: `cout << GREEN << "Hi!";
#define RED     tc(Color::Red)
#define YELLOW  tc(Color::Yellow)
#define GREEN   tc(Color::Green)
#define BLUE    tc(Color::Blue)
#define WHITE   tc(Color::White)


enum class Color
{
    Red    = 12,
    Yellow = 14,
    Green  = 10,
    Blue   = 11,
    White  = 7,  /// UI-only
    Any    = 16  /// = white. Useless in UI, cards-only.
};


std::string tc(Color text_color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (int)text_color);
    return std::string(); /// for insertion into `cout`
}


#endif /// UI_HPP