#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>



int main() {

    std::vector<long long> x;
    std::vector<long long> y;
   
    int first;
    int second;
    std::cin >> first >> second;
    int temp;
    for (int i = 0; i < first; ++i)
    {
        std::cin >> temp;
        x.push_back(temp);
    }

    for (int i = 0; i < second; ++i)
    {
        std::cin >> temp;
        y.push_back(temp);
    }
    std::sort(x.begin(), x.end());
    for (int i = 0; i < second; ++i)
    {
        auto it = std::lower_bound(x.begin(), x.end(), y[i])-x.begin();

        std::cout << it<<" ";
        
    }
    return 0;
}