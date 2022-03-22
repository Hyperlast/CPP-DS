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
const long long Size = 100001;
long long dist[Size];

std::vector<std::pair<long long, std::pair<long long, long long>>>adjacencyList[Size];
std::vector<long long> kilos;
void Dijkstra(long long kilograms)
{
    for (long long i = 0; i < Size; i++) dist[i] = LLONG_MAX;

    dist[1] = 0;

    std::priority_queue< std::pair<long long, long long>, std::vector <std::pair<long long, long long>>,std::greater<std::pair<long long, long long>>> pq;

    pq.push({ 0,1 });

    while (!pq.empty())
    {
        long long current = pq.top().second;
        long long costToCurrent = pq.top().first;
        pq.pop();

        for (const std::pair<long long, std::pair<long long, long long>>& i : adjacencyList[current])
        {

            long long child = i.first;
            long long costToBattery = i.second.second;
            long long Kilos = i.second.first;
            if (dist[child] > costToCurrent + costToBattery)
            {
                if (Kilos <= kilograms)
                {
                    dist[child] = costToCurrent + costToBattery;
                    pq.push({ costToCurrent + costToBattery , child });
                }
                 
            }

        }
    }
}

long long Binary_Search(long long& battery, long long& Vertices)
{
    long long result = LLONG_MAX;
    long long left = 0;
    long long right = 100000000000023;
    while (left <= right)
    {
        long long mid = (left + right)/2;
        Dijkstra(mid);

        if (dist[Vertices] > battery)
        {
            left = mid + 1;
        }
        else
        {
            result = mid;
            right = mid - 1;
        }

        
    }
    if (result == LLONG_MAX)
    {
        return -1;
    }
    return result;
}

int main()
{
    long long numberOfEdges = 0, numberOfVertices = 0, battery = 0, costKilos = 0;
    long long from = 0;
    long long to = 0;
    std::cin >> numberOfVertices;
    std::cin >> numberOfEdges;
    std::cin >> battery;
    long long temp = numberOfEdges;
    long long batterycost;
    //initializing graph
    while (temp)
    {
        std::cin >> from >> to >> costKilos >> batterycost;
        adjacencyList[from].push_back({ to, {costKilos,batterycost} });
        kilos.push_back(costKilos);
        temp--;
    }

    std::cout << Binary_Search(battery, numberOfVertices);
    return 0;
}