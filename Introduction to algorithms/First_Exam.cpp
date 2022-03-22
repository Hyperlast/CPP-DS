#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

int my_strlen(std::string word)
{
    int i=0;
    while(word[i]!='\0')
    {
        ++i;
    }
    return i;
}

bool isThereEmpty(int* arr, int size)
{
    for(int i=0;i<size;++i)
    {
        if(arr[i]==-1)
        {
            return true;
        }
    }
    return false;
}

int main() {
    
    std::string word;
    char letter;
    std::cin>>word;
    //validation
    if(my_strlen(word)<1||my_strlen(word)>pow(10,6))
    {
        return -1;
    }
    int temp = my_strlen(word);
    std::cin>>letter;
    int* arr = new int[temp];
    //filling the array with 0 for the letter and -1 for everything else
    for(int i=0;i<temp;++i)
    {
        if(word[i]==letter)
        {
            arr[i]= 0;
        }
        else
        {
            arr[i]=-1;
        }
    }
    
    int counter= 1;
    for(int i=0;i<temp;++i)
    {
        if(arr[i]==0)
        {
            counter=1;
        }
        if(arr[i]!=0)
        {
            arr[i]=counter;
            counter++;
        }
    }
   
    bool start=false;
    int IDXfirst=-1;
    
    for(int j=temp-1;j>=0;--j)
    {
        if(arr[j]==0)
        {
            start=true;
            counter=1;
            IDXfirst=j;
        }
        if(start && arr[j]!=0)
        {
            if((arr[j]>counter))
            {
                arr[j]=counter;
                counter++;
            }
        }
    }
    
    counter=1;
    
    for(int k = IDXfirst; k>=0;--k)
    {
        if(arr[k]!=0)
        {
            arr[k]=counter;
            counter++;
        }
    }
    
    for(int i=0;i<temp;++i)
    {
        std::cout<<arr[i]<<" ";
    }
    //dynamic memory bin
    delete[] arr;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}