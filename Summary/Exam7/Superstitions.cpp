#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <unordered_set>

const long long N = 400000;
const long long M = 2000;
long long degree[N];
long long numberOfEdges = 0, numberOfVertices = 0;
std::pair<long long, std::pair<long long, long long>> edgeList[N];
std::vector<long long> adjList[N];
bool Matrix[M][M];
bool visited[N] = { 0 };

//std::vector<long long> 
int main() {

    std::cin >> numberOfEdges >> numberOfVertices;
    long long temp = numberOfVertices;

    long long from, to;
    long long price;
    long long i = 0;

    while (numberOfVertices)
    {
        std::cin >> from >> to >> price;
        Matrix[from][to] = 1;
        edgeList[i] = { price,{from,to} };
        i++;
        numberOfVertices--;
    }

    long long K;
    std::cin >> K;
    std::unordered_set<long long> Nums;
    long long num;

    while (K)
    {
        std::cin >> num;
        Nums.insert(num);
        --K;
    }

    for (long long i = 0; i < temp; ++i)
    {
        if (Nums.count(edgeList[i].first) > 0)
        {
            Matrix[edgeList[i].second.first][edgeList[i].second.second] = 0;
        }
    }

    long long Queries;
    std::cin >> Queries;
    
    long long path;
    
    while (Queries)
    {
        bool flag = true;
        std::vector<long long> paths;
        long long amount;
        std::cin >> amount;
        long long tempam=amount;
        while (amount)
        {
            std::cin >> path;
            paths.push_back(path);
            --amount;
        }
        for (long long i = 0; i < tempam-1; ++i)
        {
            if (Matrix[paths[i]][paths[i + 1]] == 0)
            {
                flag = false;
            }
        }
        if (flag)
        {
            std::cout << 1;
        }
        else
        {
            std::cout << 0;
        }
        --Queries;
    }

    

    return 0;
}