#pragma once
#ifndef HELPER_HPP
#define HELPER_HPP

#include <iostream>
#include <vector>

/// Here be:

template<class T>
void output(const std::vector<T>& target);
template<class T>
bool in(const T target, const std::vector<T> values);



template<class T>
void output(const std::vector<T>& target)
{
    for (unsigned int i = 0; i < target.size(); i++)
        std::cout << target[i] << ' ';
    std::cout << '\n';
}


template<class T>
bool in(const T target, const std::vector<T> values)
{
    for (const T item : values)
    {
        if (item == target)
            return true;
    }
    return false;
}


#endif /// HELPER_HPP