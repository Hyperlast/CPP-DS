#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <list>

int DesipherChar(char& ch)
{
    // a-z->0-24 && A-Z 25 - 50 && 0-9 51->60//
    // a-z 97-122 A-Z 65-90 0-9 48-57
    if (ch >= 'a' && ch <= 'z')
    {
        return ch - 97;
    }
    
    if (ch >= 'A' && ch <= 'z')
    {
        return ch - 39;
    }

    if (ch >= '0' && ch <= '9')
    {
        return ch + 4;
    }
    return -1;
}


int main() {
    std::string Lections;
    std::cin >> Lections;
    // a-z->0-24 && A-Z 25 - 50 && 0-9 51->60//
    std::vector<std::vector<std::pair<int, char>>> listOFChars(62);
    const int size =Lections.length();
    for (int i = 0; i < size; ++i)
    {
        std::pair<int, char> tempPair;
        tempPair.first = i;
        tempPair.second = Lections[i];
        int idx = DesipherChar(Lections[i]);
        listOFChars[idx].push_back(tempPair);
    }
    std::vector<int> idx;
    for (unsigned i = 0; i < 62; ++i)
    { 
        if (listOFChars[i].size()==1)
        {
            auto h = listOFChars[i].begin();
            idx.push_back(h->first);
        }   
    }
    std::sort(idx.begin(), idx.end());
    const int idxsize = idx.size();
    for (int i = 0; i < idxsize; ++i)
    {
        std::cout << idx[i] << " ";
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}