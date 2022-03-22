#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>


int main() {
    
    int size;
    std::cin>>size;
    //validation
    if(size<1||size>pow(10,6))
    {
        return -1;
    }
    
    std::vector<int>arr;
    
    for(int i=0;i<size;++i)
    {
        // temp constraints = INT constraints
        int temp;
        std::cin>>temp;
        arr.push_back(temp);
    }
    //sorting numbers so you can go through negatives and repeating numbers easily 
    
    sort(arr.begin(),arr.end());
    
    int NumOfShirt=1;
    //algorithm
    
    for(int i=0;i<size;++i)
    {
        if(arr[i]>0 && arr[i]>NumOfShirt)
        {
            std::cout<<NumOfShirt;
            return 0; // end program when a number comes up
        }
        if(arr[i]>0 && arr[i]<=NumOfShirt)
        {
            NumOfShirt=arr[i];
        }
        if(arr[i]>0)
        {
           NumOfShirt++; 
        }
        
        
    }
    
    std::cout<<NumOfShirt;
    
    return 0;
}