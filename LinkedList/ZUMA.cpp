#include <bits/stdc++.h> //gcc header
#include <list>

#define endl '\n'
void DeleteFunc(std::list<int>& list, std::list<int>::iterator& itback, std::list<int>::iterator& it,
    std::list<int>::iterator& itfront, int& counter)
{
    auto itb = itback;
    auto itf = itfront;
    int FoolCounter = 0;
    /// check if there are atleast 3 elements to delete
    if (*itback != *it && *it != *itfront)
    {
        return;
    }
    while (*itb == *it)
    {
        if (itb == list.begin())
        {
            FoolCounter++;
            break;
        }
        itb--;
        FoolCounter++;
    }
    while (*itf == *it)
    {
        itf++;
        if (itf == list.end())
        {
            FoolCounter++;
            break;
        }
        FoolCounter++;
    }
    if (itback == it || it == itfront)
    {
        FoolCounter--;
    }
    if (FoolCounter+1 < 3)
    {
        return;
    }
    //deleting elements
    itb = itback;
    itf = itfront;
    while (*itb == *it)
    {
        if (itb == it)
        {
            if (it == list.begin())
            {
                break;
            }
            itb--;
        }
        else
        {
            list.erase(itb);
            itb = it;
            if (it != list.begin())
            {
                itb--;
            }
            counter++;
        }
    }

    while (*itf == *it)
    {
        if (itf == it)
        {
            itf++;
            if (itf == list.end())
            {
                itf--;
                break;
            }
        }
        else
        {
            list.erase(itf);
            itf = it;
            itf++;
            if (itf == list.end())
            {
                itf--;
                counter++;
                break;
            }
            counter++;
        }
        
    }
    //it==itback || it == itfront || itback!=it!= itfront
    if (it == itb)
    {
        if (it!=list.begin())
        {
            itb--;

        }
        else
        {
            list.erase(it);
            counter++;
            return;
        }
    }
    if (it == itf)
    {
        itf++;
        if (itf == list.end())
        {
            itf--;
            list.erase(it);
            counter++;
            return;
        }
    }
    list.erase(it);
    counter++;
    it = itb;
    if (*itb == *itf && itb != itf)
    {
        DeleteFunc(list, itb,it, itf, counter);
    }
}



int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::list<int> list;
    int NumCol;
    std::cin >> NumCol;
    for (int i = 0; i < NumCol; ++i)
    {   
        int temp;
        std::cin >> temp;
        list.push_back(temp);
    }

    std::vector<std::list<int>::iterator> iterators;
    // 1 3 2 2 2 3 1 1
    // 
    auto ittemp = list.begin();
    iterators.push_back(ittemp);
    for (int i = 0; i < NumCol; ++i)
    {
        ittemp++;
        iterators.push_back(ittemp);
    }


    int Queries;
    std::cin >> Queries;
    int tempQ = Queries;
    while (tempQ > 0)
    {

        int position;
        std::cin >> position;
        int color;
        std::cin >> color;

        if (list.size() == 0)
        {
            printf("%s\n", "Game Over");
        }
        else
        { 
             int counter1 = 0;

            auto it = iterators[position];   
            it++;
            list.insert(it,color);
            it--;
            iterators[iterators.size() - 1] = it;
            iterators.push_back(list.end());
           
           

            
            /*auto temp = list.begin();
            for (int i = 1; i <= list.size(); ++i)
            {
                printf("%d ", *temp);
                temp++;
            }
            printf("\n");*/
            

            auto itfront = it;
            itfront++;
            if (itfront == list.end())
            {
                itfront--;
            }
            auto itback = it;
            if (itback != list.begin())
            {
                itback--;
            }

            if (*itback != *it && *itfront != *itfront)
            {
                printf("%d\n", counter1);
            }
            else
            {
                DeleteFunc(list, itback, it, itfront, counter1);
                printf("%d\n", counter1);
                counter1 = 0;
            }
            
          
        }

        --tempQ;
    }
    auto it = list.begin();
    if (list.size() == 0)
    {
        printf("%d\n", -1) ;
    }
    else
    {
        for (unsigned i = 1; i <= list.size(); ++i)
        {
            printf("%d ", *it);
            it++;
        }
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    return 0;
}