#pragma once
#ifndef HELPER_HPP
#define HELPER_HPP

#include <iostream>
#include <vector>

/// Here be:

//template<class T>
//void output(const std::vector<T>& target);
template<class T>
void output(const std::vector<T*>& target);
template<class T>
unsigned int find(const T target, const std::vector<T> values);
template<class T>
bool in(const T target, const std::vector<T> values);



//template<class T>
//void output(const std::vector<T>& target)
//{
//    for (unsigned int i = 0; i < target.size(); i++)
//        std::cout << target[i] << ' ';
//    std::cout << '\n';
//}

template<class T>
void output(const std::vector<T*>& target)
{
    for (unsigned int i = 0; i < target.size(); i++)
        std::cout << target[i] << ' ';
    std::cout << '\n';
}


template<class T>
unsigned int find(const T target, const std::vector<T> values)
{
    for (unsigned int i = 0; i < values.size(); i++)
    {
        if (values[i] == target)
            return i;
    }
    return UINT_MAX;
}


template<class T>
bool in(const T target, const std::vector<T> values)
{
    for (const T curr : values)
    {
        if (curr == target)
            return true;
    }
    return false;
}


#endif /// HELPER_HPP