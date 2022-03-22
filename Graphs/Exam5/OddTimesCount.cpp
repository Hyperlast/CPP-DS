#include <cmath>
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <utility>
#include <unordered_map>
#include <unordered_set>

int main() {
    long long size;
    std::cin >> size;
    long long  temp;
    std::unordered_map<long long, long long> map;
    for (long long i = 0; i < size; ++i)
    {
        std::cin >> temp;
        map[temp]++;
    }

    int sum = 0;
    for (auto it = map.begin();it!=map.end();++it)
    {
        if (it->second % 2 != 0)
        {
            sum += it->first * it->second;
        }
    }
    
    std::cout << sum;
    return 0;
}