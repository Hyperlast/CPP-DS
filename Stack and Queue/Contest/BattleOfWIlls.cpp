#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

//Slow algorithm needs fixing

int main() {
    int Size;
    std::cin >> Size;
    std::vector<int> Result;

    for (int i = 0; i < Size; ++i)
    {
        int temp;
        std::cin >> temp;
        Result.push_back(temp);
    }

    int counter = 0;
    bool flag = false;

    while (!flag)
    {
        std::vector<int> tempArr;
        int Res_Size = Result.size();
        tempArr.push_back(Result[0]);
        for (int i = 1; i < Res_Size; ++i)
        {
            if (Result[i] <= Result[i - 1])
            {
                tempArr.push_back(Result[i]);
            }
        }


        if (Result.size() != tempArr.size())
        {
            Result = tempArr;
            counter++;
        }
        else
        {
            flag = true;
        }
    }

    std::cout << counter;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}