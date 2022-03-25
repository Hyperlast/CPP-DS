#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_set>

const int Size = 600001;
const int Vet = 100001;
std::pair<int, std::pair<int, int>> EdgeList[Size];
int parent[Vet];
int depth[Vet];

int Find(int v)
{
    if (parent[v] == v)
    {
        return v;
    }
    return Find(parent[v]);
}

void Union(int left, int right)
{
    int first = Find(left);
    int second = Find(right);
    if (depth[first] < depth[second])
    {
        parent[first] = second;
    }
    else
    {
        parent[second] = first;

        if (depth[second] == depth[first])
        {
            depth[first]++;
        }
    }

}


int main() {
    int Vert, Edges;
    std::cin >> Vert >> Edges;

    int from, to, cost;
    for (int i = 0; i < Edges; ++i)
    {
        std::cin >> from >> to >> cost;
        EdgeList[i] = { cost,{from,to} };

    }
    int ans = 0;
    for (int i = 0; i < Vet; ++i)
    {
        parent[i] = i;
        depth[i] = 0;
    }

    std::sort(EdgeList, EdgeList + Edges);
    for (int i = Edges - 1 ; i >= 0 ; --i)
    {
        from = EdgeList[i].second.first;
        to = EdgeList[i].second.second;
        cost = EdgeList[i].first;

        int FromP = Find(from), toP = Find(to);
        if (FromP != toP)
        {
            Union(FromP, toP);
        }
        else
        {
            ans += cost;
        }
    }
    std::cout << ans;
    return 0;
}
