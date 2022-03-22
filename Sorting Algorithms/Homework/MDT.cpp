#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
int NumDecoder(char Sym)
{
    if(Sym>='0' && Sym<='9')
    {
        return (Sym-'0');
    }
    
    if(Sym>='A' && Sym<='Z')
    {
        return (Sym-'A') + 37;
    }
    
    if(Sym>='a' && Sym<='z')
    {
        return(Sym-'a') + 11;
    }
    
    
    return 0;
}

int main() {
    
    int Number;
    std::cin>>Number;
    std::vector<char> MainArr;
    
    std::vector<int> IdxNumArr;
    
    for(int i=0;i<63;++i)
    {
        IdxNumArr.push_back(0);
    }

  
    for(int i=0;i<Number;++i)
    {
        
        char temp;
        std::cin>>temp;
        MainArr.push_back(temp);
    }
    //20
    //Abcabc10345ABCDE1234

    for(int i=0;i<Number;++i)
    {
        int idx = NumDecoder(MainArr[i]);
        IdxNumArr[idx]++;
    }
    
    for(int i=0;i<62;++i)
    {
        IdxNumArr[i+1]+=IdxNumArr[i];
    }

    std::vector<char> Sorted;

    for(int i=0;i<Number;++i)
    {
        Sorted.push_back('-');
    }

    for(int i=0;i<Number;++i)
    {
        //aA0123
        int ch = NumDecoder(MainArr[i]);
        int idx = IdxNumArr[ch]-1;
        Sorted[idx]=MainArr[i];
        IdxNumArr[ch]--;
    }
    
    for(int i=0;i<Number;++i)
    {
        std::cout<<Sorted[i];
    }

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
