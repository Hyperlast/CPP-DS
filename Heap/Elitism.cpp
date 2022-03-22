#include <iostream>
#include <iomanip>
#include <set>
#include <vector>

double GetMedian(std::multiset<int>& SET, std::multiset<int>::iterator& it)
{
    const int setSize = SET.size();
    double median = 0;
   
    if (setSize % 2 == 0)
    {
        auto itfront = it;
        itfront++;
        median = (double)*it + (double)*itfront;
        median /= 2;
    }
    else
    {
        it++;
        median = *it;
     
    }

    return median;
}
// 3 11 4 2 - 3 - 3,11-3,4,11

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout << std::fixed << std::setprecision(1);

    long long Queries;
    std::cin >> Queries;

    long long People;
    std::multiset<int> setMed;
    double Median = 0;
    std::multiset<int>::iterator it;
    std::cin >> People;
    setMed.insert(People);
    Median = People;
    std::cout << Median<<'\n';
    it = setMed.begin();
    Queries--;

    while (Queries > 0)
    {
        std::cin >> People;
        setMed.insert(People);
        if (People < *it)
        {
            it--;
        }
        Median = GetMedian(setMed, it);
        std::cout << Median << "\n";
        Queries--;
    }


    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}