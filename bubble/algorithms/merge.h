#pragma once

#include <vector>

namespace merge
{
	template<class T>
	void topDownMerge_impl(std::vector<T>& workVector, size_t runBegin, size_t runMiddle, size_t runEnd, std::vector<T>& toSort)
	{
		// Determine the starting index (used as a run head) for each run.
		size_t leftRunHead = runBegin;
		size_t rightRunHead = runMiddle;

		// While there are elements in the left or right runs...
		for (size_t mergeHead = runBegin; mergeHead < runEnd; ++mergeHead)
		{
			// If the left run head is a valid index and is less than or equal to the right run head (which also exists)...
			if (leftRunHead < runMiddle && (rightRunHead >= runEnd || workVector[leftRunHead] <= workVector[rightRunHead]))
			{
				std::swap(toSort[mergeHead], workVector[leftRunHead]);
				++leftRunHead;
			}
			else
			{
				std::swap(toSort[mergeHead], workVector[rightRunHead]);
				++rightRunHead;
			}
		}
	}

	template<class T>
	void topDownSplitMerge_impl(std::vector<T>& workVector, size_t runBegin, size_t runEnd, std::vector<T>& toSort)
	{
		// Early exit if the run size is 1, as the run is now trivially sorted.
		if (runEnd - runBegin < 2)
		{
			return;
		}

		// Split the run into two halves.
		size_t runMiddle = (runEnd + runBegin) / 2;

		// Recursively sort both runs from toSort into workVector. Left and right run respectively.
		topDownSplitMerge_impl(toSort, runBegin, runMiddle, workVector);
		topDownSplitMerge_impl(toSort, runMiddle, runEnd, workVector);

		// Merge the resulting runs from workVector into toSort
		topDownMerge_impl(workVector, runBegin, runMiddle, runEnd, toSort);
	}

	template<class T>
	void topDownSort_impl(std::vector<T>& toSort)
	{
		// Create a copy of the array to sort.
		std::vector<T> workVector(toSort);

		// Sort data from workvector into toSort.
		topDownSplitMerge_impl(workVector, 0, toSort.size(), toSort);
	}

	template<class T>
	void topDownSort(std::vector<T>& toSort)
	{
		// Noop for empty vectors or vectors with only a single element.
		if (toSort.size() <= 1) return;
		
		topDownSort_impl(toSort);
	}

	template<class T>
	void bottomUpSort(std::vector<T>& toSort)
	{
		// Noop for empty vectors or vectors with only a single element.
		if (toSort.size() <= 1) return;


	}
}