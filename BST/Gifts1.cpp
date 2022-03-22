#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

const int Size = 1000001;

std::vector<int> tree[Size];

/*
* parent node               child node 
    data                       data
tree[0] -> std::Vector<int> {1,2,3}
*/

void DFS(int& num,int& counter)
{
    
    for (auto x : tree[num])
    {
        counter++;
        DFS(x, counter);
    }
}


int main() {

    int Loop;
    std::cin >> Loop;
    int temp = Loop;
    int idx, idx2;
    std::vector<int> nodes;
    while (Loop > 1)
    {
        std::cin >> idx >> idx2;
        nodes.push_back(idx2);
        // parent          child
        tree[idx].push_back(idx2);
        Loop--;
    }
    int counter = 0;
    //9
    //    0 1
    //    0 2
    //    1 3
    //    1 4
    //    1 5
    //    1 6
    //    4 7
    //    7 8
    //8 6 0 0 2 0 0 1 0
    std::cout << temp-1<<" ";
    const int LoopSize = nodes.size();
    for (int i = 0; i < LoopSize ; ++i)
    {
        counter = 0;
        DFS(nodes[i], counter);
        std::cout << counter << " ";
    }

    return 0;
}