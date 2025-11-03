#pragma once
#ifndef UI_HPP
#define UI_HPP

#include <iostream>
#include <string>
#include <windows.h>
#include <vector>

/// Here be:

enum class Color;
std::string textcolor(Color text_color);


/// Color insertion into `cout`.
/// - Example: `cout << GREEN << "Hi!";
#define RED     textcolor(Color::Red)
#define YELLOW  textcolor(Color::Yellow)
#define GREEN   textcolor(Color::Green)
#define BLUE    textcolor(Color::Blue)
#define WHITE   textcolor(Color::White)


enum class Color
{
    Red    = 12,
    Yellow = 14,
    Green  = 10,
    Blue   = 11,
    White  = 7,  /// UI-only
    Any    = 7   /// Cards-only
};
const std::vector<Color> COLORS_RAINBOW_SORTED = {Color::Red, Color::Yellow, Color::Green, Color::Blue};


std::string textcolor(Color text_color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (int)text_color);
    return std::string(); /// for insertion into `cout`
}


#endif /// UI_HPP