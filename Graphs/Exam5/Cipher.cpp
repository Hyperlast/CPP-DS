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
    long long N = 3;
    long long result = permutation(num1)/6;
    return result;
}

int main() {
    long long size;
    std::cin >> size;
    std::vector<std::string> arr;
    std::string temp;
    for (long long i = 0; i < size; ++i)
    {
        std::cin >> temp;
        arr.push_back(temp);
    }

    std::unordered_map<std::string, long long> map;
    for (long long i = 0; i < size; ++i)
    {
        map[arr[i]]++;
    }
    
    for (long long i = 0; i < size; ++i)
    {
        std::cout << map[arr[i]] << " ";
    }
    return 0;
}