#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
const int Size = 1000;

int dist[Size];
void init()
{
    for (int i = 0; i < Size; ++ i)
    {
        dist[i] = INT_MAX;
    }
}
void bfs(int start, std::vector < int > adjList[1000])
{
    dist[start] = 0;
    std::queue<int> q;
    q.push(start);
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        for (auto x : adjList[curr])
        {
            if (dist[x] > dist[curr] + 1)
            {
                dist[x] = dist[curr] + 1;
                q.push(x);
            }
        }
    }
}

int main() {
    int Q;
    std::cin >> Q;
    while (Q)
    {
        std::vector < int > adjList[1000];
        int vert, edge;
        std::cin >> vert >> edge;
        int from, to;
        for (int i = 0; i < edge; ++i)
        {
            std::cin >> from >> to;
            adjList[from].push_back(to);
            adjList[to].push_back(from);
        }
        int start;
        std::cin >> start;
        init();
        bfs(start, adjList);

        for (int i = 1; i <= vert; ++i)
        {
            if (i != start)
            {
                if (dist[i] == INT_MAX)
                {
                    std::cout << "-1 ";
                }
                else
                {
                    std::cout << dist[i] * 6<<" ";
                }
            }
        }
        std::cout<<'\n';
        --Q;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}