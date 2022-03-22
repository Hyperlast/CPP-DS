#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <utility>
#include <unordered_map>
#include <unordered_set>
int main() {
    long long Querie;
    std::vector<long long> Keys;
    std::vector<long long> Doors;
    std::cin >> Querie;
    long long temp;

    for (long long i = 0; i < Querie; ++i)
    {
        std::cin >> temp;
        Keys.push_back(temp);
    }

    for (long long i = 0; i < Querie; ++i)
    {
        std::cin >> temp;
        Doors.push_back(temp);
    }
    std::unordered_multiset<long long> Mapper;
    long long counter = 0;
    for (long long i = 0; i < Querie; ++i)
    {
        if (Keys[i] != Doors[i])
        {
            Mapper.insert(Keys[i]);
            if (Mapper.count(Doors[i])>0)
            {
                Mapper.erase(Mapper.find(Doors[i]));
            }
            else
            {
                counter++;
            }
        }
    }
    std::cout << counter;
}