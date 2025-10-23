#pragma once
#ifndef HELPER_HPP
#define HELPER_HPP

#include <iostream>
#include <time.h> /// seeding random
#include <vector>

/// Here be:

unsigned int randint(const unsigned int min, const unsigned int max, unsigned int exclusion = UINT_MAX);
unsigned int randint(const unsigned int max, unsigned int exclusion = UINT_MAX);
template<class T>
std::vector<T> shuffled(const std::vector<T>& target);
template<class T>
void output(const std::vector<T>& target);


unsigned int _rand_seed = time(NULL);
/// Random number [min, max].
unsigned int randint(const unsigned int min, const unsigned int max, unsigned int exclusion/* = UINT_MAX*/)
{
    /// Checking the exclusion's validity
    if (exclusion != UINT_MAX)
    {
        if (exclusion < min || exclusion > max) /// Nonsensical exclusion
            exclusion = UINT_MAX;
    }

    /// Checking the limits' validity
    if (max <  min) std::cerr << RED << "Incorrect use of `randint(u, u, [u])`: wrong parameter order (" << min << " and " << max << ")." << WHITE;
    if (max == min)
    {
        if (exclusion == UINT_MAX)
            return min;
        else /// Exclusion blocks execution (i.e. `min` = 1, `max` = 1, `exclusion` = 1)
            std::cerr << RED << "Incorrect use of `randint(u, u, u)`: exclusion blocks execution with arguments " << min << " and " << max << '.' << WHITE;
    }


    srand(++_rand_seed);

    unsigned int result = unsigned(rand()) % (max-min+1) + min;
    if (exclusion != UINT_MAX)
    {
        while (result == exclusion)
            result = unsigned(rand()) % (max-min+1) + min;
    }
    return result;
}

/// Random number [0, max].
unsigned int randint(const unsigned int max, const int exclusion/* = UINT_MAX*/)
{
    return randint(0, max, exclusion);
}


template<class T>
std::vector<T> shuffled(const std::vector<T>& target)
{
    if (target.size() <= 1)
        return target;
    
    std::vector<T> result = target;
    
    for (unsigned int i = 0; i < target.size(); i++)
    {
        int new_pos = randint(0, target.size()-1, i);
        T temp = result[i];
        result[i] = result[new_pos];
        result[new_pos] = temp;
    }

    return result;
}


template<class T>
void output(const std::vector<T>& target)
{
    for (unsigned int i = 0; i < target.size(); i++)
        std::cout << target[i] << ' ';
    std::cout << '\n';
}


#endif /// HELPER_HPP