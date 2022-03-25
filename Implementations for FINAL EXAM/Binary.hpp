#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <string>
#include <queue>
bool binary_searchIT(std::vector<int>arr, const int NumS)
{
	int l = 0;
	int r = arr.size() - 1;
	while (l <= r)
	{
		int middle = l + (r - l) / 2;

		if (arr[middle] == NumS)
		{
			return true;
		}

		if (arr[middle] < NumS)
		{
			l = middle + 1;
		}
		else
		{
			r = middle - 1;
		}

	}

	return false;
}