#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <set>
#include <climits>
const long long Modulus = 1000000007;
const long long Size = 100001;
std::pair<long long, long long> Dist[Size];
std::vector<std::pair<long long, long long>> adjacencyList[Size];

void Dijkstra(long long start, long long MaxEdge)
{
    for (long long i = 0; i < Size; ++i)
    {
        Dist[i].first = LLONG_MAX;
        Dist[i].second = 0;
    }
    Dist[start].first = 0;
    Dist[start].second = 1;
    std::priority_queue< std::pair<long long, long long>, std::vector<std::pair<long long, long long>>, std::greater<std::pair<long long, long long>> > pq;
    pq.push({ 0,start });
    while (!pq.empty())
    {
        long long current = pq.top().second;
        long long costToCurrent = pq.top().first;
        pq.pop();

        if (costToCurrent > Dist[current].first)
        {
            continue;
        }

        for (std::pair<long, long> i : adjacencyList[current])
        {

            long long child = i.first;
            long long costToChildOfCurrent = i.second;

            if (Dist[child].first > costToCurrent + costToChildOfCurrent)
            {
                Dist[child].first = costToCurrent + costToChildOfCurrent;
                pq.push({ costToChildOfCurrent + costToCurrent , child });
                Dist[child].second = Dist[current].second;
            }
            else if (Dist[child].first == costToCurrent + costToChildOfCurrent)
            {
                Dist[child].second = (Dist[child].second + Dist[current].second) % Modulus;
            }

        }
    }

    if (Dist[MaxEdge].second)
    {
        std::cout << Dist[MaxEdge].first << " ";
        std::cout << Dist[MaxEdge].second;
    }
    else
    {
        std::cout << -1 << " ";
        std::cout << 0 ;

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
    while (temp)
    {
        std::cin >> from >> to >> costToChildOfCurrent;
        adjacencyList[from].push_back({ to, costToChildOfCurrent });
        temp--;
    }

    Dijkstra(1, numberOfVertices);

    return 0;
}