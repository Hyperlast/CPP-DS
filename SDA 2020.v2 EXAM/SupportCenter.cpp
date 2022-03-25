#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_set>

std::priority_queue<int,std::vector<int>,std::greater<int>> pq;
std::vector<int> ans;
int main() {

    int Hm;
    int Interval;
    int B ;
    std::cin >> Hm>>Interval>>B;    
    int Q;
    std::cin >> Q;
    int temp;
    int time = 1;
    for (int i = 0; i < Q; ++i)
    {
        std::cin >> temp;
        pq.push(temp);
        if (B == 0)
        {
            continue;
        }
        if (time % Interval == 0)
        {
            int MemoryBoom = Hm;
            while (MemoryBoom)
            {
                ans.push_back(pq.top());
                pq.pop();
                MemoryBoom--;
            }
            B--;
        }
        time++;
    }

    while (B)
    {
        int MemoryBoom = Hm;
        while (MemoryBoom)
        {
            ans.push_back(pq.top());
            pq.pop();
            MemoryBoom--;
        }
        B--;
    }

    const int Size = ans.size();
    for (int i = 0; i < Size; ++i)
    {
        std::cout << ans[i] << " ";
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
