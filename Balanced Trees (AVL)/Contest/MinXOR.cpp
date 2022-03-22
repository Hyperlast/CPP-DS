#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bitset>
#include <set>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::set<int> numbers;
    numbers.insert(0);
    int AmountOfQueries;
    std::cin >> AmountOfQueries;
    int num;
    int MinBitSet = 0;
    bool firstel = true;
    while (AmountOfQueries > 0)
    {
        std::cin >> num;
        if (firstel)
        {
            numbers.insert(num);
            MinBitSet = 0 ^ num;
            firstel = false;
        }
        else
        {
            bool countNum = numbers.count(num);
            if (!countNum)
            {
                numbers.insert(num);
                auto it = numbers.find(num);
                auto itback = it;
                auto itforwards = it;
                itback--;
                itforwards++;
                if (itforwards != numbers.end())
                {
                    if ((*it ^ *itforwards) < (*it ^ *itback))
                    {
                        if ((*it ^ *itforwards) < MinBitSet)
                        {
                            MinBitSet = (*it ^ *itforwards);
                        }
                    }
                    else if ((*it ^ *itforwards) >= (*it ^ *itback))
                    {
                        if ((*it ^ *itback) < MinBitSet)
                        {
                            MinBitSet = (*it ^ *itback);
                        }
                    }
                }
                else
                {
                    if ((*it ^ *itback) < MinBitSet)
                    {
                        MinBitSet = (*it ^ *itback);
                    }
                }

            }

        }

        printf("%d\n", MinBitSet);
        AmountOfQueries--;
    }



    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}