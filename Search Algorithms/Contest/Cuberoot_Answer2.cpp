#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>

long long my_cbrtl(long long longnumber)
{
    long long counter = 1;
    long long temp = 1;
    while(temp<=longnumber)
    {
       temp = (counter*counter*counter);
       counter++;
    }
    return counter-2;
}

long long PresentAmount(long long number)
{
    long long CubeNum = my_cbrtl(number);
    long long tempnumber = number;
    long long counter =0;
    while(tempnumber>0)
    {
        CubeNum = CubeNum*CubeNum*CubeNum;
        tempnumber -= CubeNum;
        CubeNum= my_cbrtl(tempnumber);
        counter++;
    }
    return counter;
}

int main() {
    long long number;
    std::cin>>number;
    std::cout<< PresentAmount(number);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}