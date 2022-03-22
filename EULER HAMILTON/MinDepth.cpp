#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
const int N = 100000;
int degree[N];
int numberOfEdges = 0, numberOfVertices = 0;
std::vector<int>adjacencyList[N];
bool visited[N] = { 0 };


int main() {

    int from = 0, to = 0;
    int querie = 0;
    std::cin >> querie;
    querie--;
    for (int i = 0; i < N; i++)
    {
        degree[i] = 0;
    }

    while (querie)
    {
        std::cin >> from >> to;
        adjacencyList[from].push_back(to);
        adjacencyList[to].push_back(from);
        degree[to]++;
        degree[from]++;
        querie--;
    }
    std::queue<int> q;
    for (int i = 0; i < N; ++i)
    {
        if (degree[i] == 1)
        {
            q.push(i);
        }
    }
    std::set<int> ans;
    while (!q.empty())
    {   
        
        int temp = q.size();
        ans.clear();
        while (temp>0)
        {
            int current = q.front();
            ans.insert(current);
            q.pop();
            for (auto neighbour : adjacencyList[current])
            {
                degree[neighbour]--;
                if (degree[neighbour] == 1)
                {
                    q.push(neighbour);
                }
                


            }
            --temp;
        }

       
    }
    for (auto it = ans.begin(); it != ans.end(); ++it)
    {
        std::cout << *it << " ";
    }
    return 0;

}