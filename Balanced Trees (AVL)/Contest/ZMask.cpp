#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <queue>
#include <string>

std::string FromNumToString(int& number)
{
    std::string Mnumber="";
    //size 20
    int Dec = number;
    std::string num;
    while (Dec > 0)
    {
        num += ((Dec % 2) + '0');
        Dec /= 2;
    }
    for (int i = 0; i < 20 - num.size(); ++i)
    {
        Mnumber += '0';
    }
    num+=Mnumber;
    Mnumber = "00000000000000000000";
    const int Size = num.size();
    for (int i = 0; i < Size; ++i)
    {
        Mnumber[i] = num[Size - i-1];
    }
    return Mnumber;
}

void recursionFunc(std::string& str, int& idx, std::set<std::string>& set)
{
    if (idx == 20)
    {
        return;
    }

    if (str[idx] == '0')
    {
        idx += 1;
        recursionFunc(str, idx, set);
    }

    if (str[idx] == '1')
    {
        std::string temp = str;
        temp[idx] ='0';
        idx++;
        int secidx = idx;
        set.insert(temp);
        set.insert(str);
        recursionFunc(temp, idx, set);
        
        recursionFunc(str, secidx, set);
    }

    return;
}

int main() {

    int Nums;
    std::cin >> Nums;
    std::set<std::string> setNums;

    int a;
    std::string temp;
    int idx;
    while (Nums > 0)
    {
        idx = 0;
        std::cin >> a;
        temp = FromNumToString(a);
        recursionFunc(temp, idx, setNums);
        Nums--;
    }

    std::cout << setNums.size();

    return 0;
}