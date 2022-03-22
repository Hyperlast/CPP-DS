#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

const int Size = 10001;

std::pair<int, std::pair<int, int>> edgeList[Size];
//         Price         from to       

int n, m;
int Par[Size];

int find(int v)
{
    if (v == Par[v])
    {
        return v;
    }

    return Par[v] = find(Par[v]);
}


void init()
{
    for (int i = 0; i < Size; ++i)
    {
        Par[i] = i;
    }
}

void kruskal()
{
    std::sort(edgeList, edgeList + m);
    init();
    int LowerPrice = 1;
    int UpperPrice = 30000;
    for (int i = 0; i < m; ++i)
    {
        int tempV = n;
        init();
        for (int j = i; j < m; ++j)
        {
            int from = find(edgeList[j].second.first);
            int to = find(edgeList[j].second.second);
            int price1 = edgeList[j].first;
            int price2 = edgeList[i].first;
            if (from != to)
            {
                Par[from] = to;
                tempV--;
                if (tempV == 1)
                {
                    if ((UpperPrice - LowerPrice) > (price1 - price2))
                    {
                        LowerPrice = price2;
                        UpperPrice = price1;
                    }
                    break;
                }
            }
        }
        if (tempV > 1)
        {
            break;
        }
    }
    std::cout << LowerPrice << " " << UpperPrice;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int x, y;
    std::cin >> n >> m;
    int price;
    for (int i = 0; i < m; ++i)
    {
        std::cin >> x >> y >> price;
        edgeList[i] = { price,{ x,y} };
    }
    kruskal();
    return 0;
}