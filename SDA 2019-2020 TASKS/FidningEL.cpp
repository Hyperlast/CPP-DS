#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_set>


int main() {
    std::vector<int> el;
    int Q;
    std::cin >> Q;
    int temp;
    for (int i = 0; i < Q; ++i)
    {
        std::cin >> temp;
        el.push_back(temp);
    }

    std::cin >> Q;
    for (int i = 0; i < Q; ++i)
    {
        std::cin >> temp;
        auto itup = std::upper_bound(el.begin(), el.end(), temp)-el.begin();
        auto itlow = std::lower_bound(el.begin(), el.end(), temp)-el.begin();
        if (itup == itlow)
        {
            std::cout << itup << '\n';
        }
        else
        {
            std::cout << itlow << " " << (itup-1) << '\n';
        }
        
    }
}