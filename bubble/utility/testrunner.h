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
			for (int index = 0; index < tests.size(); ++index)
			{
				sortingFunction(tests[index].source);

				if (!equal(tests[index].source, tests[index].expected))
				{
					utility::reportFailure(tests[index].source, tests[index].expected);

					return index;
				}
			}

			return -1;
		}

	private:
		std::vector<testCase<T>> tests;
		void (*sortingFunction)(std::vector<T>&);
	};
}