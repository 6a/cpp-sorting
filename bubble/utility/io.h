#pragma once

#include <vector>
#include <chrono>
#include <iterator>
#include <sstream>
#include <iomanip>

namespace utility
{
    const size_t TEST_NAME_MIN_SIZE = 20;
    const int PASSING_TEST_OUTPUT = -1;

    // Prints the formatted result of the test named "test" to the std output stream.
    void outputResult(std::string test, int result, std::chrono::milliseconds duration)
    {
        std::stringstream resultStringStream;
        std::stringstream nameStringStream;

        nameStringStream << "\"" << test << "\":";

        std::cout << "Test " << std::setw(TEST_NAME_MIN_SIZE) << std::left << nameStringStream.str() << "[ ";

        if (result == PASSING_TEST_OUTPUT)
        {
            resultStringStream << "passed ]";
        }
        else
        {
            resultStringStream << "failed on test " << result << " ]";
        }

        std::cout << resultStringStream.str() << " | Duration: " << duration.count() << "ms\n" << std::endl;
    }

    // Returns a string representation of a vector of type T
    template<class T>
    std::string vectorToString(std::vector<T> input)
    {
        std::ostringstream oss;
        oss << "{";

        if (!input.empty())
        {
            std::copy(input.begin(), input.end() - 1, std::ostream_iterator<T>(oss, ", "));

            oss << input.back() << "}";
        }

        return oss.str();
    }

    // Reports a failure
    template<class T>
    void reportFailure(const std::vector<T> source, const std::vector<T> actual, const std::vector<T> expected)
    {
        std::string sourceString = vectorToString(source);
        std::string actualString = vectorToString(actual);
        std::string expectedString = vectorToString(expected);

        std::cout << "Test failed.\nSource:   " << sourceString << "\nActual:   " << actualString << "\nExpected: " << expectedString << "\n" << std::endl;
    }
}
