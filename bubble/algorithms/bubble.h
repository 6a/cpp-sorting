#pragma once

#include <vector>
#include "../utility/testrunner.h"
#include "../utility/io.h"

namespace bubble
{
	template<class T>
	void sort(std::vector<T>& toSort)
	{
		size_t range = toSort.size();

		while (range > 1)
		{
			size_t newRange = 0;
			for (size_t i = 1; i < range; ++i)
			{
				if (toSort[i - 1] > toSort[i])
				{
					std::swap(toSort[i - 1], toSort[i]);
					newRange = i;
				}
			}

			range = newRange;
		}
	}

	// Runs all the test cases. Returns -1 if all tests pass, else returns the index of the failed test.
	void test(int testID)
	{
		std::vector<utility::testCase<int>> cases
		{
			utility::testCase<int>{
				std::vector<int>{1, 4, 5, 2, 3},
				std::vector<int>{1, 2, 3, 4, 5},
			},
		};

		utility::testRunner<int> tr("Bubble", cases, sort);

		utility::outputResult(tr.name, tr.run());
	}
}