#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <set>

std::unordered_map<char, bool> visited;
std::unordered_map<char, std::vector<char>> adjacencyList;
std::stack<char> sta;

void dfs(char v)
{
    visited[v] = 1;
    for (auto i : adjacencyList[v])
    {
        if (!visited[i])
        {
            dfs(i);
        }
    }
    sta.push(v);
}


void topologicalSort()
{
    for (auto i : adjacencyList)
    {
        char cur = i.first;
        if (!visited[cur])
        {
            dfs(cur);
        }

    }
}

size_t MinStrLenght(size_t first, size_t second)
{
    if (first > second)
    {
        return second;
    }
    return first;
}

void printTopoOrder(std::vector<std::string>& dictionary, int LoopSize)
{
    for (int i = 0; i < LoopSize - 1; ++i)
    {
        std::string word1 = dictionary[i];
        std::string word2 = dictionary[i + 1];

        for (size_t j = 0; j < MinStrLenght(word1.length(), word2.length()); ++j)
        {
            if (word1[j] != word2[j])
            {
                adjacencyList[word1[j]].push_back(word2[j]);
                break;
            }
        }
    }

    topologicalSort();

    while (!sta.empty())
    {
        std::cout << sta.top() << " ";
        sta.pop();
    }

}

int main()
{
    int NumOfStrngs;
    std::cin >> NumOfStrngs;
    std::vector<std::string> dictionary;
    std::string temp;
    for (int i = 0; i < NumOfStrngs; ++i)
    {
        std::cin >> temp;
        int size = temp.size();
        for (int j = 0; j < size; ++j)
        {
            adjacencyList[temp[j]] = std::vector<char>();
        }
        dictionary.push_back(temp);
    }

    printTopoOrder(dictionary, NumOfStrngs);
    return 0;
}