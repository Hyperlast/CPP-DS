#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>

long long PresentAmount(long long number)
{
    long long CubeNum = cbrtl(number);
    long long tempnumber = number;
    long long counter =0;
    while(tempnumber>0)
    {
        CubeNum = CubeNum*CubeNum*CubeNum;
        tempnumber -= CubeNum;
        CubeNum= cbrtl(tempnumber);
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
