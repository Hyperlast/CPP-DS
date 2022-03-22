#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

const int Size = 1e5;

std::vector<std::pair<int,int>> adjList[Size];
std::pair<int, std::pair<int, int>> edgeList[Size];
int n, m;
int Par[Size];
int depth[Size];

int find(int v) 
{
    if (v == Par[v])
    {
        return v;
    }
        
    return Par[v]=find(Par[v]);
}

void Union(int from,int to)
{
    int first = find(from);
    int second = find(to);
    if (first != second)
    {
        if (depth[first] > depth[second])
        {
            Par[second] = first;
        }
        else
        {
            Par[first] = second;
        }

        if (depth[first] == depth[second])
        {
            depth[first]++;
        }
            
    }
}

void init()
{
    for (int i = 0; i < Size; ++i)
    {
        Par[i] = i;
        depth[i] = 0;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int x, y;
    std::cin >> n >> m;
    init();
    for (int i = 0; i < m; ++i)
    {
        std::cin >> x >> y;
        Union(x, y);
    }
    int Queries;
    std::cin >> Queries;

    int temp;
    int first;
    int second;

    while (Queries)
    {
        std::cin >> temp;
        std::cin >> first >> second;
        if (temp == 1)
        {
            if (find(first) == find(second))
            {
                std::cout << 1;
            }
            else
            {
                std::cout << 0;
            }
        }
        else
        {
            if (find(first) != find(second))
            {
                Union(first, second);
            }
        }
        Queries--;
    }
    return 0;
}