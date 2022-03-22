#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <set>
#include <climits>
#include <cmath>
const long long Size = 100002;
int dist[Size];

std::vector<std::pair<int, int>>adjacencyList[Size];

void Dijkstra(long long v)
{
    for (long long i = 0; i < Size; i++) dist[i] = INT_MAX;

    dist[v] = 0;

    std::priority_queue< std::pair<long long, long long>, std::vector <std::pair<long long, long long>>, std::greater<std::pair<long long, long long>> > pq;
    pq.push({ 0,v });
    
    while (!pq.empty())
    {
        long long current = pq.top().second;
        long long costToCurrent = pq.top().first;
        pq.pop();

        if (costToCurrent > dist[current])
        {
            continue;
        }


        for (const std::pair<long long, long long>& i : adjacencyList[current])
        {

            long long child = i.first;
            long long costToChildOfCurrent = i.second;

            if (dist[child] > costToCurrent + costToChildOfCurrent)
            {
                dist[child] = costToCurrent + costToChildOfCurrent;
                pq.push({ costToChildOfCurrent + costToCurrent, child });
            }

        }
    }
}

int main()
{
    long long numberOfEdges = 0, numberOfVertices = 0, costToChildOfCurrent = 0;
    long long from = 0;
    long long to = 0;
    std::cin >> numberOfVertices;
    std::cin >> numberOfEdges;
    long long temp = numberOfEdges;
    //initializing graph
    while (temp)
    {
        std::cin >> from >> to >> costToChildOfCurrent;
        adjacencyList[from].push_back({ to, costToChildOfCurrent });
        adjacencyList[to].push_back({ from, costToChildOfCurrent });
        temp--;
    }
    std::cin >> temp;
    long long EdgeForT;
    while (temp)
    {
        std::cin >> EdgeForT;
        adjacencyList[100001].push_back({ EdgeForT, 0 });
        adjacencyList[EdgeForT].push_back({ 100001,0 });
        temp--;
    }
    std::cin >> temp;
    Dijkstra(100001);
    //Queries
    while (temp)
    {
        std::cin >> EdgeForT;
        std::cout<<dist[EdgeForT] << '\n';
        temp--;
    }
    return 0;
}