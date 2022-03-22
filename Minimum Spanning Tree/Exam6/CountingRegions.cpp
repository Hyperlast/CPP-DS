#include <iostream>
#include <vector>
#include <set>

const int MAX_SIZE = 1e5 + 2;
std::vector<std::vector<int>> adjList(MAX_SIZE);
bool visited[MAX_SIZE]{ 0 };


void dfs(int begin) {
    visited[begin] = 1;
    for (auto it : adjList[begin]) 
    {
        if (!visited[it]) 
        {
            dfs(it);
        }
    }
}

int components(int vertices) {
    int comp = 0;
    for (int i = 0; i < vertices; i++) 
    {
        if (!visited[i]) 
        {
            dfs(i);
            comp++;
        }
    }
    return comp;
}

int main() {
    

    int Graphs;
    std::cin >> Graphs; 
    std::vector<int> result;
    
    for (int i = 0; i < Graphs; i++) 
    {
        int vertices, edges;
        std::cin >> vertices >> edges;

        int from, to;
        for (int i = 0; i < edges; i++) 
        {
            std::cin >> from >> to;


            adjList[from].push_back(to);
            adjList[to].push_back(from);

        }
        result.push_back(components(vertices));

        for (int i = 0; i < MAX_SIZE; i++) 
        {
            visited[i] = 0;
            adjList[i].clear();
        }
    }
    const int Sizer = result.size();
    for (int i = 0; i < Sizer ; i++) 
    {
        std::cout << result[i] << " ";
    }


    return 0;
}