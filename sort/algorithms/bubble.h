#pragma once

#include <vector>

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
}