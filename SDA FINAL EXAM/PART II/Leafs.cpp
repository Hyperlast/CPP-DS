#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <set>
const int size = 200001;
std::vector<int> adjList[size];
int visited[size];
void init()
{
    for (int i = 0; i < size; ++i)
    {
        visited[i] = 0;
    }
}

void dfs(int v,long long& sum)
{
    visited[v] = 1;
   
    for (auto x : adjList[v])
    {
        if (!visited[x])
        {
            sum += x;
            dfs(x,sum);
        }
    }


}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int edges;
    int queries;
    std::cin >> edges>>queries;
    int from, to;
    for (int i = 0; i < edges; ++i)
    {
        std::cin >> from >> to;
        adjList[from].push_back(to);
    }

    
    while (queries)
    {
        init();
        
        long long cost = 0;
        int start;
        std::cin >> start;

        dfs(start, cost);
        std::cout << cost<<'\n';

        --queries;
    }

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}