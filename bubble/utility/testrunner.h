#pragma once

#include <vector>
#include "testcase.h"
#include "io.h"

namespace utility
{
	template<class T>
	class testRunner
	{
	public:
		std::string name;

		testRunner(std::string name, std::vector<testCase<T>> tests, void (*sortingFunction)(std::vector<T>&))
			: name(name), tests(tests), sortingFunction(sortingFunction) {}

		~testRunner()
		{
			// Nothing to destroy
		}

		int run()
		{
			for (size_t index = 0; index < tests.size(); ++index)
			{
				std::vector<T> toSort(tests[index].source);

				sortingFunction(toSort);

				if (!equal(toSort, tests[index].expected))
				{
					utility::reportFailure(toSort, tests[index].expected);

					return index;
				}

				++index;
			}

			return -1;
		}

	private:
		std::vector<testCase<T>> tests;
		void (*sortingFunction)(std::vector<T>&);
	};
}