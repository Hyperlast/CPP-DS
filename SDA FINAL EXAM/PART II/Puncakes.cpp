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

int main() {
    int pancakes;
    std::cin >> pancakes;
    int chefsamount;
    std::cin >> chefsamount;
    std::vector<int> chefs;
    int time;
    for (int i = 0; i < chefsamount; ++i)
    {
        std::cin >> time;
        chefs.push_back(time);
    }
    int PancakesMade = 0;
    time = 1;
    while (PancakesMade != pancakes)
    {
        for (int i = 0; i < chefsamount; ++i)
        {
            if (time % chefs[i] == 0)
            {
                PancakesMade++;
            }
        }
        if (PancakesMade >= pancakes)
        {
            break;
        }
        time++;
    }
    std::cout << time;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}