#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

const int Size = 200001;

std::pair<long long , std::pair<int,std::pair<int,std::pair<long long,int>>>> edgeList[Size];
//         Price         from           to        winnings idx
std::vector<int> idxs;
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

void Union(int from, int to)
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

bool comparator(std::pair<long long, std::pair<int, std::pair<int, std::pair<long long, int>>>> left,
    std::pair<long long, std::pair<int, std::pair<int, std::pair<long long, int>>>> right)
{
    if (left.first > right.first)
    {
        return false;
    }
    if (left.first < right.first)
    {
        return true;
    }
    if (left.first == right.first)
    {
        if (left.second.second.second.first > right.second.second.second.first)
        {
            return true;
        }
        else
            return false;
    }
    return false;
}

void kruskal()
{
    std::sort(edgeList, edgeList + m,comparator);
    init();
    int ans = 0;
    for (int i = 0; i < m; ++i)
    {
        int from = edgeList[i].second.first;
        int to = edgeList[i].second.second.first;
        if (find(from) != find(to))
        {
            Union(from, to);
            idxs.push_back(edgeList[i].second.second.second.second);
            ans += edgeList[i].second.second.second.first;
        }
    }
}


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int x, y;
    std::cin >> n >> m;
    long long price;
    long long winning;
    for (int i = 0; i < m; ++i)
    {
        std::cin >> x >> y>>price>>winning;
        edgeList[i] = { price,{ x,{ y,{winning,i+1}} } };
    }
    kruskal();
    const int Size = idxs.size();
    for (int i = 0; i < Size; ++i)
    {
        std::cout << idxs[i]<<'\n';
    }
    return 0;
}