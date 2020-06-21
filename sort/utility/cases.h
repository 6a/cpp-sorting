#pragma once

#include <vector>
#include <random>
#include <functional>
#include "testcase.h"

namespace utility
{
    const static std::vector<testCase<int>> generateCases(size_t count, size_t minSize, size_t maxSize)
    {
        std::vector<testCase<int>> output;

        const auto seed = 1;

        std::default_random_engine generator(seed);

        std::uniform_int_distribution<size_t> nDistribution(minSize, maxSize);
        std::uniform_int_distribution<int> vDistribution(INT16_MIN, INT16_MAX);

        auto nRand = std::bind(nDistribution, generator);
        auto vRand = std::bind(vDistribution, generator);

        for (size_t i = 0; i < count; i++)
        {
            size_t n = nRand();
            std::vector<int> generatedVector;

            for (size_t j = 0; j < n; j++)
            {
                generatedVector.push_back(vRand());
            }

            testCase<int> testCase;
            testCase.source = std::vector<int>(generatedVector);
            
            testCase.expected = std::vector<int>(generatedVector);
            std::sort(testCase.expected.begin(), testCase.expected.end());

            output.push_back(testCase);
        }

        return output;
    }
}