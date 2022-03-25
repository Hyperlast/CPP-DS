#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
const int N = 1000005;

bool visited[N];
std::vector<int> adjList[N];
int component[N];
int br = 0;

void dfs(int start)
{
    visited[start] = 1;
    component[start] = br;
    for (auto x : adjList[start])
    {
        if (!visited[x])
        {
            dfs(x);
        }
    }
}

void compdfs()
{
    
    for (int i =0;i<N;++i)
    {
        if (!visited[i])
        {
            dfs(i);
            br++;
        }
    }
}

int main() {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int Vert, edges;
    std::cin >> Vert >> edges;

    int to, from;
    for (int i = 0; i < edges; ++i)
    {
        std::cin >> to >> from;
        adjList[to].push_back(from);
        adjList[from].push_back(to);
    }

    compdfs();

    int Q;
    std::cin >> Q;
    for (int i = 0; i < Q; ++i)
    {
        std::cin >> from >> to;
        if (component[from] == component[to])
        {
            std::cout << 1<<" ";
        }
        else
        {
            std::cout << 0<<" ";
        }
    }


    return 0;
}