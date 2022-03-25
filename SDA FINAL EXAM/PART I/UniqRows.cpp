#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>


std::unordered_map<std::string, int> map;
int main()
{
    int N,M;
    std::cin >> N >> M;
    char f;
    std::vector<std::string> vec;
    for (int i = 0; i < N; ++i)
    {
        std::string str;
        for (int j = 0; j < M; ++j)
        {
            std::cin >> f;
            str += f;
        }
        vec.push_back(str);
    }

    for (int i = 0; i < N; ++i)
    {
        map[vec[i]]++;
    }

    int ans = 0;
    for (auto it = map.begin(); it != map.end(); ++it)
    {
        if (it->second == 1)
        {
            ans++;
        }
    }
    std::cout << ans;
    return 0;
}