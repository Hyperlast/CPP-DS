#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

long long MinSum(std::vector<int>& arr, const int& SubSize)
{
    std::queue<int> WindowArr;
    long long minSum = arr[0];
    for (int i = 0; i < SubSize; ++i)
    {
        if (minSum > arr[i])
        {
            minSum = arr[i];
        }
        WindowArr.push(arr[i]);
    }

    const int ArrSize = arr.size();
    long long lastMin = minSum;
    for (int i = SubSize; i < ArrSize; ++i)
    {
        int first = WindowArr.front();
        WindowArr.pop();
        WindowArr.push(arr[i]);
        if (lastMin >= arr[i])
        {
            minSum += arr[i];
            lastMin = arr[i];
        }
        else
        {
            if (lastMin != first && lastMin < arr[i])
            {
                minSum += lastMin;
            }
            else
            {
                lastMin = arr[i - (SubSize - 1)];
                for (int j = (i - (SubSize - 1)); j <= i; ++j)
                {
                    if (lastMin > arr[j])
                    {
                        lastMin = arr[j];
                    }
                }
                minSum += lastMin;
            }

            
        }

    }

    return minSum;
}

int main() {

    int NumOfEl;
    std::cin >> NumOfEl;
    int SizeOfVecs;
    std::cin >> SizeOfVecs;
    std::vector<int> numbers;
    for (int i = 0; i < NumOfEl; ++i)
    {
        int temp;
        std::cin >> temp;
        numbers.push_back(temp);
    }
    if (SizeOfVecs == 0)
    {
        return 0;
    }
    std::cout << MinSum(numbers, SizeOfVecs);

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}