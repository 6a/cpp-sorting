#pragma once

#include <vector>
#include "testcase.h"

namespace utility
{
	const static std::vector<testCase<int>> cases
	{
		testCase<int>{
			std::vector<int>{1, 4, 5, 2, 3},
			std::vector<int>{1, 2, 3, 4, 5},
		},
		testCase<int>{
			std::vector<int>{-36, 118, 110, -7, -84},
			std::vector<int>{-84, -36, -7, 110, 118},
		},
		testCase<int>{
			std::vector<int>{95, -123, 97, 58},
			std::vector<int>{-123, 58, 95, 97},
		},
		testCase<int>{
			std::vector<int>{-85, -29, -91, 68, -102},
			std::vector<int>{-102, -91, -85, -29, 68},
		},
		testCase<int>{
			std::vector<int>{-33, -112, 103, 100, -39},
			std::vector<int>{-112, -39, -33, 100, 103},
		},
		testCase<int>{
			std::vector<int>{122, 33, -111, 51, -73, 42},
			std::vector<int>{-111, -73, 33, 42, 51, 122},
		},
		testCase<int>{
			std::vector<int>{-46, -104, -39, -36, -69, 92, 13, -79, -6, 46},
			std::vector<int>{-104, -79, -69, -46, -39, -36, -6, 13, 46, 92},
		},
		testCase<int>{
			std::vector<int>{-121, -23, 45, 43, 8, -52},
			std::vector<int>{-121, -52, -23, 8, 43, 45},
		},
		testCase<int>{
			std::vector<int>{58, 15, 0, 69, -52, -19, -90, -37, -58},
			std::vector<int>{-90, -58, -52, -37, -19, 0, 15, 58, 69},
		},
		testCase<int>{
			std::vector<int>{66, 77, 124, 110},
			std::vector<int>{66, 77, 110, 124},
		},
		testCase<int>{
			std::vector<int>{-18, -78, -76, 11, -110, 62, 39, -39},
			std::vector<int>{-110, -78, -76, -39, -18, 11, 39, 62},
		},
		testCase<int>{
			std::vector<int>{2, -80, 48, 66, -28, -28, 73, 89, 73, 26},
			std::vector<int>{-80, -28, -28, 2, 26, 48, 66, 73, 73, 89},
		},
		testCase<int>{
			std::vector<int>{97, -57, -13, 110, 1, -56, -44},
			std::vector<int>{-57, -56, -44, -13, 1, 97, 110},
		},
		testCase<int>{
			std::vector<int>{-88, 102, -125, 43, -116, 18, -119, 14},
			std::vector<int>{-125, -119, -116, -88, 14, 18, 43, 102},
		},
		testCase<int>{
			std::vector<int>{63, -120, 121, -117},
			std::vector<int>{-120, -117, 63, 121},
		},
		testCase<int>{
			std::vector<int>{124, 106, -77, 127, 24, 118, -57, -24, -16, -39},
			std::vector<int>{-77, -57, -39, -24, -16, 24, 106, 118, 124, 127},
		},
		testCase<int>{
			std::vector<int>{-111, 42, -13, 54},
			std::vector<int>{-111, -13, 42, 54},
		},
		testCase<int>{
			std::vector<int>{-20, -89, -112, 69, -77, -48, 86, 33, 120, 84},
			std::vector<int>{-112, -89, -77, -48, -20, 33, 69, 84, 86, 120},
		},
		testCase<int>{
			std::vector<int>{8, -24, 67, -46, -4, 62, -29},
			std::vector<int>{-46, -29, -24, -4, 8, 62, 67},
		},
		testCase<int>{
			std::vector<int>{69, -93, 35, -119, -89},
			std::vector<int>{-119, -93, -89, 35, 69},
		},
		testCase<int>{
			std::vector<int>{-63, -42, 15, -31, 42, -76, -68, -82, -101},
			std::vector<int>{-101, -82, -76, -68, -63, -42, -31, 15, 42},
		},
	};
}