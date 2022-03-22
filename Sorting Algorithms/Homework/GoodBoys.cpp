#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

struct BodyBuilder
{
public:
    int idx;
    double di;
    double ti;
};

bool HumanComparator(const BodyBuilder &lhs, const BodyBuilder &rhs)
{
    double efficiency1 = ((lhs.di) * (lhs.di) / lhs.ti);
    double efficiency2 = ((rhs.di) * (rhs.di) / rhs.ti);

    if (efficiency1 > efficiency2)
    {
        return true;
    }
    else if (efficiency1 < efficiency2)
    {
        return false;
    }

    return lhs.di > rhs.di;
}

void XSort(std::vector<BodyBuilder> &arr)
{
    sort(arr.begin(), arr.end(), HumanComparator);
}

int main()
{

    int GoodBoys;
    std::cin >> GoodBoys;

    std::vector<BodyBuilder> arr;

    for (int i = 0; i < GoodBoys; ++i)
    {
        int idx = i + 1;
        int temp1;
        std::cin >> temp1;
        int temp2;
        std::cin >> temp2;

        BodyBuilder Temp;
        Temp.di = temp1;
        Temp.ti = temp2;
        Temp.idx = idx;

        arr.push_back(Temp);
    }

    XSort(arr);

    for (int i = 0; i < GoodBoys; ++i)
    {
        std::cout << arr[i].idx << " ";
    }

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}