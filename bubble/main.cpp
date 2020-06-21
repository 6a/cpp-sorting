#include <iostream>
#include <random>

#include "utility/testcase.h"
#include "utility/testrunner.h"
#include "utility/cases.h"
#include "utility/io.h"

#include "algorithms/bubble.h"
#include "algorithms/quick.h"

template<class T>
void test(std::string name, void (*sortingFunction)(std::vector<T>&))
{
	std::vector<utility::testCase<T>> cases(utility::generateCases(1000, 0, 2000));
	utility::testRunner<T> tr(name, cases, sortingFunction);

	std::chrono::high_resolution_clock timer;
	std::chrono::steady_clock::time_point start = timer.now();

	int result = tr.run();

	std::chrono::steady_clock::time_point end = timer.now();
	std::chrono::milliseconds duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

	utility::outputResult(tr.name, result, duration);
}

int main()
{
	test("Bubble", bubble::sort<int>);

	test("Quick", quick::sort<int>);
}