#include <iostream>
#include <random>
#include <functional>
#include "algorithms/bubble.h"
#include "utility/io.h"

void outputTestCases()
{
	std::default_random_engine generator;

	std::uniform_int_distribution<size_t> nDistribution(4, 10);
	std::uniform_int_distribution<int> vDistribution(INT8_MIN, INT8_MAX);

	auto nRand = std::bind(nDistribution, generator);
	auto vRand = std::bind(vDistribution, generator);

	std::string prefix = "testCase<int>{\n    std::vector<int>";
	std::string preVec = "    std::vector<int>";
	std::string suffix = ",\n},";

	for (size_t i = 0; i < 20; i++)
	{
		size_t n = nRand();
		std::vector<int> generatedVector;

		for (size_t j = 0; j < n; j++)
		{
			generatedVector.push_back(vRand());
		}

		std::cout << prefix << utility::vectorToString(generatedVector) << "," << std::endl;

		std::vector<int> sortedGeneratedVector(generatedVector);
		std::sort(sortedGeneratedVector.begin(), sortedGeneratedVector.end());

		std::cout << preVec << utility::vectorToString(sortedGeneratedVector) << suffix << std::endl;
	}
}

int main()
{
	bubble::test(0);
}