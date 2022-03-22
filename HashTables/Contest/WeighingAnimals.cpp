#include <cmath>
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <utility>
#include <unordered_map>
#include <unordered_set>
long long permutation(long long& Num)
{
    long long result=1;
    int i = 0;
    while (i!=3)
    {
        result *= Num;
        Num--;
        i++;
    }
    return result;
}
long long Combinatoric(long long& num1)
{
    long long result = permutation(num1)/6;
    return result;
}

int main() {
    long long Querie;
    std::cin >> Querie;
    long long Kilos;
    std::cin >> Kilos;

    std::unordered_map<long long, long long> RightSideOfIndex;
    std::unordered_map<long long, long long> LeftSideOfIndex;
    std::vector<long long> arr;
    long long temp;

    for (int i = 0; i < Querie; ++i)
    {
        std::cin >> temp;
        arr.push_back(temp);
        RightSideOfIndex[temp]++;
    }

    long long result = 0;
    if (Kilos==1)
    {
        for (auto it = RightSideOfIndex.begin(); it != RightSideOfIndex.end(); ++it)
        {
            if (it->second >= 3)
            {
                result += Combinatoric(it->second);
            }
        }
    }
    else
    {
        for (int i = 0; i < Querie; ++i)
        {
            long long AmountLeft = LeftSideOfIndex[arr[i] / Kilos];
            long long AmountRight = RightSideOfIndex[arr[i] * Kilos];
            if (arr[i] % Kilos==0)
            {
                result += AmountLeft * AmountRight;
            }
            LeftSideOfIndex[arr[i]]++;
            RightSideOfIndex[arr[i]]--;
        }
    }
    
    
    std::cout << result;
    
    return 0;
}