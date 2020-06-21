#pragma once

#include <vector>

namespace quick
{
	template<class T>
	size_t partition(std::vector<T>& toSort, size_t low, size_t high)
	{
		T pivot = toSort[(high + low) / 2];

		while (true)
		{
			while (toSort[low] < pivot)
			{
				++low;
			}

			while (toSort[high] > pivot)
			{
				--high;
			}

			if (low >= high)
			{
				return high;
			}

			std::swap(toSort[low], toSort[high]);

			++low;
			--high;
		}
	}

	template<class T>
	void sort_impl(std::vector<T>& toSort, size_t low, size_t high)
	{
		if (low < high)
		{
			size_t partitionBorder = partition(toSort, low, high);
			sort_impl(toSort, low, partitionBorder);
			sort_impl(toSort, partitionBorder + 1, high);
		}
	}

	template<class T>
	void sort(std::vector<T>& toSort)
	{
		// Noop for empty vectors or vectors with only 1 element.
		if (toSort.size() <= 1) return;

		sort_impl(toSort, 0, toSort.size() - 1);
	}
}