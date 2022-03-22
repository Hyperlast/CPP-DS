#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <list>
#include <queue>

bool CheckCords(const int& Coord, const int& Border)
{
    if (Coord >= 0 && Coord < Border)
    {
        return true;
    }
    return false;
}

int AmountOfCovidInfected(std::vector<std::vector<int>>& Matrix,int& N,int&M, std::queue<std::pair<int, int>>& Cords,int& Time)
{
    std::set<std::pair<int, int>> CordsSet;
    std::queue<std::pair<int, int>> Newly = Cords;
    while (!Newly.empty())
    {
        CordsSet.insert(Newly.front());
        Newly.pop();
    }
    //  1    2
    // 3 4  5 6
    for (int i = 0; i < Time; ++i)
    {
        
        std::queue<std::pair<int, int>> Temp;
        while (!Cords.empty())
        {
            int j, k;
            j = Cords.front().first - 1;
            k = Cords.front().second;

            if (CheckCords(j, N) && CheckCords(k, M))
            {
                if (Matrix[j][k]==0)
                {
                    Matrix[j][k] = 1;
                    CordsSet.insert(std::make_pair(j, k));
                    Temp.push(std::make_pair(j, k));
                }
                
            }
            j = Cords.front().first + 1;
            k = Cords.front().second;

            if (CheckCords(j, N) && CheckCords(k, M))
            {
                if (Matrix[j][k]==0)
                {
                    Matrix[j][k] = 1;
                    CordsSet.insert(std::make_pair(j, k));
                    Temp.push(std::make_pair(j, k));
                }
                
            }
            j = Cords.front().first;
            k = Cords.front().second - 1;

            if (CheckCords(j, N) && CheckCords(k, M))
            {
                if (Matrix[j][k]==0)
                {
                    Matrix[j][k] = 1;
                    CordsSet.insert(std::make_pair(j, k));
                    Temp.push(std::make_pair(j, k));
                }
            }
            j = Cords.front().first;
            k = Cords.front().second + 1;

            if (CheckCords(j, N) && CheckCords(k, M))
            {
                if (Matrix[j][k]==0)
                {
                    Matrix[j][k] = 1;
                    CordsSet.insert(std::make_pair(j, k));
                    Temp.push(std::make_pair(j, k));
                }
            }
            Cords.pop();
        }

        Cords = Temp;
    }
    return CordsSet.size();
}


int main()
{
    int N, M;
    std::cin >> N;
    std::cin >> M;
    std::vector<std::vector<int>> Matrix(N,std::vector<int>(M,0));

    int TimeLoop;
    int CovidCount;
    std::cin >> TimeLoop;
    std::cin >> CovidCount;
    std::queue<std::pair<int, int>> Cords;
    int tempCov = CovidCount;
    int first,second;

    while(tempCov>0)
    {
        std::cin >> first >> second;
        std::pair<int, int>temp;
        temp.first = first-1;
        temp.second = second-1;
        Matrix[first-1][second-1] = 1;
        Cords.push(temp);
        tempCov--;
    }

    int Covid = AmountOfCovidInfected(Matrix, N, M, Cords,TimeLoop);
    int Healthy = (N * M) - Covid;
    std::cout << Healthy;
    return 0;
}