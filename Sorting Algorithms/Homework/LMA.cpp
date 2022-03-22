#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

class Date
{
public:
    int idx;
    std::string strDate;
};

bool DateComparator(const Date &first, const Date &second)
{
    std::string FirstString;
    std::string SecondString;
    FirstString+=first.strDate.substr(15,4);
    FirstString+=first.strDate.substr(12,2);
    FirstString+=first.strDate.substr(9,2);
    FirstString+=first.strDate.substr(0,2);
    FirstString+=first.strDate.substr(3,2);
    FirstString+=first.strDate.substr(6,2);
    
    
    
    SecondString+=second.strDate.substr(15,4);
    SecondString+=second.strDate.substr(12,2);
    SecondString+=second.strDate.substr(9,2);
    SecondString+=second.strDate.substr(0,2);
    SecondString+=second.strDate.substr(3,2);
    SecondString+=second.strDate.substr(6,2);

    
    for(int i=0;i< 14;i++)
    {
        if((FirstString[i]-'0')>(SecondString[i]-'0'))
        return false;
        if((FirstString[i]-'0')<(SecondString[i]-'0'))
        return true;
    }

    return first.idx<second.idx;
}

void SortDates(std::vector<Date>& dates)
{
    sort(dates.begin(), dates.end(),DateComparator);
}

int main()
{
    
    int number;
    std::cin >> number;
    std::vector<Date> arr;
    for (int i = 0; i < number; ++i)
    {
        std::string StringDate;
        std::string time;
        std::cin >> time;
        std::string date;
        std::cin >> date;
        StringDate += time;
        StringDate += ' ';
        StringDate += date;

        Date temp;
        temp.strDate = StringDate;
        temp.idx = (i + 1);
    
        arr.push_back(temp);
    }

    
   SortDates(arr);

    for(int i=0;i<number;++i){
        std::cout<<arr[i].idx<<"\n";
    }


    return 0;
}