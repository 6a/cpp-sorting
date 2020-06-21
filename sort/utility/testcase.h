#pragma once

#include <algorithm>
#include <vector>

namespace utility
{
    template<class T>
    struct testCase
    {
        std::vector<T> source;
        std::vector<T> expected;
    };

    template<class T>
    static bool equal(std::vector<T> actual, std::vector<T> expected)
    {
        return std::equal(actual.begin(), actual.end(), expected.begin());
    }
}