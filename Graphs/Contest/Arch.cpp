#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <list>
const int N = 10000000;
std::vector<long long> adjacencyList[N];
std::unordered_map<long long,bool> visited;
std::unordered_map<long long, bool> Stack;

bool isCyc(int v)
{
    if (!visited[v])
    {
        visited[v] = true;
        Stack[v] = true;

        for (auto i = adjacencyList[v].begin(); i != adjacencyList[v].end(); ++i)
        {
            if (!visited[*i] && isCyc(*i))
            {
                return true;
            }
            else if (Stack[*i])
            {
                return true;
            }
               
        }

    }
    Stack[v] = false;  
    return false;
}

int main() {
    int Q;
    std::cin >> Q;
    int E;
    long long Start = 0;
    long long End;
    std::vector<int> Result;
    while (Q > 0)
    {
        std::cin >> E;
        std::set<long long> set;
        while (E > 0)
        {
            std::cin >> Start;
            std::cin >> End;
            set.insert(Start);
            set.insert(End);
            adjacencyList[Start].push_back(End);

            E--;
        }
        
        bool isCyclic = false;

        visited.clear();
        Stack.clear();

        for (auto i = set.begin(); i !=set.end(); i++)
        {
            if (isCyc(*i))
            {
                isCyclic = true;
            }
        }

        Result.push_back(isCyclic);


        for (auto& i : adjacencyList)
        {
            i.clear();
        }

        visited.clear();
        Stack.clear();

        Q--;
    }

    const int size = Result.size();
    for (long long i = 0; i < size; ++i)
    {
        std::cout << Result[i] << " ";
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}