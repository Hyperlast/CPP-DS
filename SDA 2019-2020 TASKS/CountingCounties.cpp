#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_set>

const int size = 100000;
bool visited[size];

void dfs(int v, std::vector<int>adjList[size])
{
    visited[v] = 1;
    for (auto x : adjList[v])
    {
        if (!visited[x])
        {
            dfs(x,adjList);
        }
    }
}

int main() {
    
    int testQs;
    int vert, edge;
    int from, to;
    std::cin >> testQs;
    while (testQs)
    {
        std::vector<int>adjList[size];
        std::cin >> vert >> edge;
        
        for (int i = 0; i < edge; ++i)
        {
            std::cin >> from >> to;
            adjList[from].push_back(to);
            adjList[to].push_back(from);
        }
        
        int comps = 0;
        for (int i = 0; i < vert; i++)
        {
            visited[i] = 0;
        }

        for (int i = 0; i < vert; ++i)
        {
            if (!visited[i])
            {
                dfs(i,adjList);
                comps++;
            }
        }

        std::cout << comps << " ";
        testQs--;
    }


    return 0;
}


