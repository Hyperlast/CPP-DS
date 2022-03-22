#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

struct my_pair{
public:
    int idx;
    double PlayersFor;
    double PlayersAgainst;
    
};

bool TeamComparator(my_pair& rhs,my_pair& lhs)
{
     double Eff1 = ((rhs.PlayersFor*rhs.PlayersFor)/rhs.PlayersAgainst);
     double Eff2 = ((lhs.PlayersFor*lhs.PlayersFor)/lhs.PlayersAgainst);
    
    if(Eff1>Eff2)
    {
        return true;
    }
    if(Eff1<Eff2)
    {
        return false;
    }
    
    return rhs.PlayersFor>lhs.PlayersFor;
}

void My_Sort(std::vector<my_pair>& arr)
{
    std::sort(arr.begin(),arr.end(),TeamComparator);
}

int main() {
    
    int Number;
    std::cin>>Number;
    std::vector<my_pair> arr;
    for(int i=0;i<Number;++i)
    {
        double Number1;
        double Number2;
        std::cin>>Number1;
        std::cin>>Number2;
        my_pair temp;
        temp.idx = (i+1);
        temp.PlayersFor = Number1;
        temp.PlayersAgainst = Number2;
        arr.push_back(temp);
        
    }
    
    My_Sort(arr);
    
    for(int i=0;i<Number;++i)
    {
        std::cout<<arr[i].idx<<" ";
    }
        
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
