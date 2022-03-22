//#include <bits/stdc++.h> gcc header
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

int ElAmount(const std::vector<int>& arr, const int& border, const int& sum,const std::vector<unsigned long long>& SumArr)
{
    if (border < arr[0])
    {
        return 0;
    }

    auto it = std::upper_bound(arr.begin(), arr.end(), border);
    int IDX = it - arr.begin() - 1;
  
    if (arr[IDX]>sum)
    {
        return 0;
    }
    //10 20 40 40 50 70 130
    //0  1  2  3  4  5  6
    //10 30 70 110 160 210 360
    if (SumArr[IDX] <= sum)
    {
        return IDX + 1;
    }

    unsigned long long tempSum = 0;
    tempSum = SumArr[IDX] - sum;
    auto it2 = std::upper_bound(SumArr.begin(), SumArr.end(), tempSum);
    int IDX2 = it2 - SumArr.begin();

    if (SumArr[IDX2 - 1] == tempSum)
    {
        IDX2 -= 1;
    }

    return (IDX - IDX2);
}

void printFunc(const int& Q, const std::vector<int>& QuerieArr, const int& N)
{
    //Sum optimisation from the internet with partial sums
    const int Size = QuerieArr.size();
    std::vector<unsigned long long> SumArr(Size);
    SumArr[0] = QuerieArr[0];
    for (int i = 1; i < Size; ++i)
    {
        SumArr[i] = QuerieArr[i] + SumArr[i - 1];
    }
    
    std::vector<int> Result;
    for (int i = 0; i < Q; ++i)
    {
        int Sum;
        int Border;
        std::cin >> Sum;
        std::cin >> Border;
        
        Result.push_back(ElAmount(QuerieArr, Border, Sum,SumArr));

    }
    const int Size2 = Result.size();
    for(int i=0;i < Size2;++i)
    {
        printf("%i\n", Result[i]);
    }
    
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    int Q;
    std::cin >> N;
    std::cin >> Q;
    std::vector<int> QuerieArr;
    for (int i = 0; i < N; ++i)
    {
        int temp;
        std::cin >> temp;
        QuerieArr.push_back(temp);
    }

    std::sort(QuerieArr.begin(), QuerieArr.end());
    printFunc(Q, QuerieArr, N);

    return 0;
}