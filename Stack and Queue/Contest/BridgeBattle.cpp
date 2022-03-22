#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <list>
void TolastPositive(std::list<int>& sad, std::vector<int>& Res, std::list<int>::iterator& it,int& size)
{
    const int Size = size;
    if (size != 0)
    {
        while (*it > 0)
        {
            it++;
            if (it == sad.end())
            {

                for (int i = 0; i < Size; ++i)
                {
                    auto itte = sad.begin();
                    Res.push_back(*itte);
                    sad.pop_front();
                    size--;
                }

                return;
            }
        }
    }
    
}
void PopbackNegative(std::list<int>& sad, std::vector<int>& Res, std::list<int>::iterator& it, int& size)
{
    const int Size = size;
    if (size != 0)
    {
        for (int i = 0; i < Size; ++i)
        {

            auto it = sad.begin();
            if (*it > 0)
            {
                break;
            }
            Res.push_back(*it);
            sad.pop_front();
            size--;
        }
    }
}

void ResultFunc(std::list<int>& sad, std::vector<int>& Res)
{
    int size = sad.size();

    //6 5 3 -1 -5 -1 3 2 -5
    std::list<int>::iterator it=sad.begin();
    PopbackNegative(sad,Res,it, size);
    it = sad.begin();
    TolastPositive(sad,Res,it, size);
    auto itnext = it;
    it--;
    while (itnext != sad.end())
    {
        // -1 -2 4 5 6 -3 -6 -7 -8 2 3
        if (*itnext > 0)
        {
            TolastPositive(sad, Res, it,size);
            if (size == 0)
            {
                return;
            }
            itnext = it;
            it--;
        }
        if (*it < 0)
        {
            PopbackNegative(sad, Res, it,size);
            it = sad.begin();
            TolastPositive(sad, Res, it,size);
            if (size == 0)
            {
                return;
            }
            itnext = it;
            it--;
        }
        else
        {
            if (abs(*it) > abs(*itnext))
            {
                sad.erase(itnext);
                size--;
                itnext = it;
                itnext++;
                if (itnext == sad.end())
                {
                    itnext--;
                    continue;
                }
            }
            else
            {
                if (abs(*it) < abs(*itnext))
                {
                    sad.erase(it);
                    size--;
                    it = itnext;
                    if (itnext == sad.begin())
                    {
                        continue;
                    }
                    it--;
                }
                else
                {
                    if (abs(*it) == abs(*itnext) && it != itnext)
                    {
                        auto backup = it;
                        if (it == sad.begin())
                        {
                            backup == itnext;
                            backup++;
                            if (backup == sad.end())
                            {
                                sad.erase(it);
                                sad.erase(itnext);
                                size -= 2;
                                break;
                            }

                        }
                        else
                        {
                            backup--;
                        }
                        sad.erase(it);
                        sad.erase(itnext);
                        size -= 2;
                        it = backup;
                        itnext = it;
                        itnext++;
                        if (itnext == sad.end())
                        {
                            Res.push_back(*it);
                            sad.erase(it);
                            size--;
                            break;
                        }
                    }
                }
            }
        }
        if (size == 0)
        {
            return;
        }

    }

    //auto itt = sad.begin();
       //for (int i = 0; i < size; ++i)
       //{
       //        std::cout << *itt<<" ";
       //        itt++;
       //}

}

int main() {

    std::list<int> sad;
    int numberOfQueries;
    std::cin >> numberOfQueries;

    for (int i = 0; i < numberOfQueries; ++i)
    {
        int number;
        std::cin >> number;
        sad.push_back(number);
    }
    std::vector<int>result;
    ResultFunc(sad, result);
    const int size = result.size();

    for (int i = 0; i < size; ++i)
    {
        std::cout << result[i] << " ";
    }
}