#pragma once

#include <vector>

namespace merge
{
	namespace topdown
	{
		template<class T>
		void merge_impl(std::vector<T>& workVector, size_t runBegin, size_t runMiddle, size_t runEnd, std::vector<T>& toSort)
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
		void splitMerge_impl(std::vector<T>& workVector, size_t runBegin, size_t runEnd, std::vector<T>& toSort)
		{
			// Early exit if the run size is 1, as the run is now trivially sorted.
			if (runEnd - runBegin < 2)
			{
				return;
			}

			// Split the run into two halves.
			size_t runMiddle = (runEnd + runBegin) / 2;

			// Recursively sort both runs from toSort into workVector. Left and right run respectively.
			splitMerge_impl(toSort, runBegin, runMiddle, workVector);
			splitMerge_impl(toSort, runMiddle, runEnd, workVector);

			// Merge the resulting runs from workVector into toSort
			merge_impl(workVector, runBegin, runMiddle, runEnd, toSort);
		}

		template<class T>
		void sort_impl(std::vector<T>& toSort)
		{
			// Create a copy of the vector to sort.
			std::vector<T> workVector(toSort);

			// Sort data from workvector into toSort.
			splitMerge_impl(workVector, 0, toSort.size(), toSort);
		}

		template<class T>
		void sort(std::vector<T>& toSort)
		{
			// Noop for empty vectors or vectors with only a single element.
			if (toSort.size() <= 1) return;

			sort_impl(toSort);
		}
	}

	namespace bottomup
	{
		template<class T>
		void merge_impl(std::vector<T>& toSort, size_t runBegin, size_t runMiddle, size_t runEnd, std::vector<T>& workVector)
		{
			// Determine the starting index (used as a run head) for each run.
			size_t leftRunHead = runBegin;
			size_t rightRunHead = runMiddle;

			// While there are elements in the left or right runs...
			for (size_t mergeHead = runBegin; mergeHead < runEnd; ++mergeHead)
			{
				// If the left run head is a valid index and is less than or equal to the right run head (which also exists)...
				if (leftRunHead < runMiddle && (rightRunHead >= runEnd || toSort[leftRunHead] <= toSort[rightRunHead]))
				{
					std::swap(toSort[leftRunHead], workVector[mergeHead]);
					++leftRunHead;
				}
				else
				{
					std::swap(toSort[rightRunHead], workVector[mergeHead]);
					++rightRunHead;
				}
			}
		}

		template<class T>
		void sort_impl(std::vector<T>& toSort)
{
			// Cache the size of toSort to avoid repeated calls to size() later.
			size_t inputVectorSize = toSort.size();

			// Create a copy of the vector to sort.
			std::vector<T> workVector(inputVectorSize);

			// Start with a run size of 1, as this is already sorted.
			// Sequentially increase the size of the run by powers of 2 until the whole vector is sorted.
			for (size_t runSize = 1; runSize < inputVectorSize; runSize *= 2)
			{
				// Sequentially move along toSort in blocks of runSize * 2, merging each pair of runs each time.
				for (size_t mergeHead = 0; mergeHead < inputVectorSize; mergeHead += 2 * runSize)
				{
					merge_impl(toSort, mergeHead, std::min(mergeHead + runSize, inputVectorSize), std::min(mergeHead + 2 * runSize, inputVectorSize), workVector);
				}

				// The work vector now contains sorted runs of size runSize * 2.
				// Copy the work array into the sort array.
				//toSort.assign(workVector.begin(), workVector.end());
				toSort = workVector;
			}
		}

		template<class T>
		void sort(std::vector<T>& toSort)
		{
			// Noop for empty vectors or vectors with only a single element.
			if (toSort.size() <= 1) return;

			sort_impl(toSort);
		}
	}
}