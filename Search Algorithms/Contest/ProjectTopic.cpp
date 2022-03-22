#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
int getClosestNumber(const int& number1,const int& number2,const int& x)
{
    if (abs(x - number1) > abs(x-number2))
    {
        return number2;
    }
    else
    {
        return number1;
    }
}

int main() {
    int ThemeSize;
    int PlayersSize;
    std::cin >> ThemeSize;
    std::cin >> PlayersSize;

    std::vector<int> ThemeArr;
    std::vector<int> PlayersArr;

    for (int i = 0; i < ThemeSize; ++i)
    {
        int temp;
        std::cin >> temp;
        ThemeArr.push_back(temp);
    }

    std::sort(ThemeArr.begin(), ThemeArr.end());

    for (int i = 0; i < PlayersSize; ++i)
    {
        int temp;
        std::cin >> temp;
        if (ThemeSize != 0)
        {
            std::vector<int>::iterator upper=std::lower_bound(ThemeArr.begin(),ThemeArr.end(),temp);
            
            int UpperIDX = (upper - ThemeArr.begin());
            int LowerIDX = 0;
            if (UpperIDX != 0)
            {
                LowerIDX = UpperIDX - 1;
            }

            if (UpperIDX > ThemeSize-1)
            {
                UpperIDX = ThemeSize - 1;
            }

            temp = getClosestNumber(ThemeArr[LowerIDX],ThemeArr[UpperIDX], temp);

        }
        PlayersArr.push_back(temp);
    }

    for (int i = 0; i < PlayersSize; ++i)
    {
        std::cout << PlayersArr[i] << "\n";
    }
    return 0;
}