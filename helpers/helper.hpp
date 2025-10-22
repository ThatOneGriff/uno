#pragma once
#ifndef HELPER_HPP
#define HELPER_HPP

#include <iostream>
#include <time.h> /// seeding random


unsigned int _rand_seed = time(NULL);
/// Random number [min, max].
unsigned int randint(const unsigned int min, const unsigned int max)
{
    /// Edge cases
    if (max <  min) std::cerr << RED << "Incorrect use of `randint(u, u) with parameters` " << min << " and " << max << '.' << WHITE;
    if (max == min) return max;

    srand(++_rand_seed);
    return unsigned(rand()) % (max-min+1) + min; 
}


#endif /// HELPER_HPP