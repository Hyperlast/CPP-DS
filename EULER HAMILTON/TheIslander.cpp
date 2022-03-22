#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <set>
const int N = 100000;
int degree[N];
int numberOfEdges = 0, numberOfVertices = 0;
std::vector<std::string> answer;
std::vector<int>adjacencyList[N];
bool visited[N]{ 0 };
std::set<int> arr; 

void dfs(int v)
{
    if (visited[v] == 1)
    {
        return;
    }
    
    visited[v] = 1;
    for (auto neighbour : adjacencyList[v])
    {
        if (!visited[neighbour])
        {
            dfs(neighbour);
        }
       
    }
}

bool checker(int s)
{
    for (int i = 1; i < N; ++i)
    {
        visited[i] = 0;
    }
    if(arr.size()!=numberOfVertices)
    {
        return false;
    }
    int counter = 0;
    for (auto it=arr.begin(); it!= arr.end(); ++it)
    {
        if(visited[*it]==0)
        {
            dfs(*it);
            counter++;
        }
    }
    
    for (int i = 0; i < N; ++i)
    {
       adjacencyList[i].clear();
    }
    arr.clear();
    
    if (counter != 1)
    {
        return false;
    }

    return true;
}

int main() {

    int from = 0, to = 0;
    int querie = 0;
    std::cin >> querie;

    while (querie--) {

        int numberOfOddDegree = 0;
        std::cin >> numberOfVertices >> numberOfEdges;

        for (int i = 0; i < N; i++)
        {
            degree[i] = 0;
        }

        while (numberOfEdges)
        {
            std::cin >> from >> to;
            numberOfOddDegree=from;
            arr.insert(from);
            arr.insert(to);
            adjacencyList[from].push_back(to);
            adjacencyList[to].push_back(from);
            degree[to]++;
            degree[from]++;
            numberOfEdges--;
        }

        if (!checker(numberOfOddDegree))
        {
            answer.push_back("none\n");
            continue;
        }
        numberOfOddDegree = 0;
        for (int i = 0; i < N; i++)
        {

            if (degree[i] % 2 != 0)  numberOfOddDegree++;

        }

        if (numberOfOddDegree == 0) 
        {
            answer.push_back("ecycle\n");
        }
        else if (numberOfOddDegree == 0 || numberOfOddDegree == 2)
        {
            answer.push_back("epath\n");
        }
        else 
        {
            answer.push_back("none\n");
        }
    }
    const int Size = answer.size();
    for (int i = 0; i < Size; i++)
    {
        std::cout << answer[i];
    }

    return 0;
}