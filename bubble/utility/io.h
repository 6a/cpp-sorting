#pragma once

#include <vector>
#include <chrono>
#include <iterator>
#include <sstream>
#include <iomanip>

namespace utility
{
    // Prints the formatted result of the test named "test" to the std output stream.
    void outputResult(std::string test, int result, std::chrono::milliseconds duration)
    {
        std::stringstream resultStringStream;
        std::stringstream nameStringStream;

        nameStringStream << "\"" << test << "\":";

        std::cout << "Test " << std::setw(15) << std::left << nameStringStream.str() << "[ ";

        if (result == -1)
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
    void reportFailure(const std::vector<T> actual, const std::vector<T> expected)
    {
        std::string expectedString = vectorToString(expected);
        std::string actualString = vectorToString(actual);

        std::cout << "Test failed.\nExpected: " << expectedString << "\nActual:   " << actualString << "\n" << std::endl;
    }
}
