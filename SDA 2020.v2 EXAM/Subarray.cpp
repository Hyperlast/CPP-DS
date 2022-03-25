#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_set>

std::queue<int> q;
std::unordered_set<int> set;
int main() {
    int Q;
    std::cin >> Q;
    int temp;
    int ans = 0;
    for (int i = 0; i < Q; ++i)
    {
        int br;
        std::cin >> temp;
        if (set.count(temp) == 0)
        {
            set.insert(temp);
            q.push(temp);
        }
        else
        {
            while (q.front() != temp && !q.empty())
            {
                set.erase(q.front());
                q.pop();
            }
            q.pop();
            q.push(temp);
        }
        br = q.size();
        ans = std::max(br, ans);
       
    }
    std::cout << ans;

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}