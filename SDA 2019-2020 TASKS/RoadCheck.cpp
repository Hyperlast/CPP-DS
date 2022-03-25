#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_set>

const int Size = 1001;
int Matrix[Size][Size];

int main() {
    int N, M;
    std::cin >> N >> M;

    int to, from, cost;
    for (int i = 0; i < Size; ++i)
    {
        for (int j = 0; j < Size;++j)
        {
            Matrix[i][j] = -1;
        }
    }

    for (int i = 0; i < M; ++i)
    {
        std::cin >> to >> from >> cost;
        Matrix[to][from] = cost;
        Matrix[from][to] = cost;
    }

    int K;
    std::cin >> K;
    std::cin >> from;
    long long ans = 0;
    for (int i = 0; i < K-1; ++i)
    {
        std::cin >> to;
        if (Matrix[from][to] != -1)
        {
            ans += Matrix[from][to];
        }
        else
        {
            std::cout << "-1";
            return 0;
        }
        from = to;
    }
      
    std::cout<<ans;
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}