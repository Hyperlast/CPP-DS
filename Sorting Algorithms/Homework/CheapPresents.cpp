#include <vector>
#include <iostream>

void myswap(int& num1, int&num2)
{
    int temp=num1;
    num1=num2;
    num2=temp;
}

int partition(std::vector<int>& arr, int low, int high)
{
    int pivot = arr[high];
    int i = low;
    
    for(int j=low;j<high;++j)
    {
        if(arr[j]<=pivot)
        {
            myswap(arr[i],arr[j]);
            i++;
        }
    }
    myswap(arr[i],arr[high]);
    return i;
}

void QuickSorting(std::vector<int>& arr, int low, int high)
{
    if(low<high)
    {
        int par=partition(arr,low,high);
        
        QuickSorting(arr, low, par-1);
        QuickSorting(arr, par+1, high);
    }
}


int main() {
    
    std::vector<int> arr;
    int PresentNum;
    std::cin>>PresentNum;
    
    for(int i=0;i<PresentNum;++i)
    {
        int temp;
        std::cin>>temp;
        arr.push_back(temp);
    }
    
    int NumberOfPeople;
    std::cin>>NumberOfPeople;
    
    QuickSorting( arr,0, PresentNum-1);
    
    long result=0;
    for(int i=0;i<NumberOfPeople;++i)
    {
        result+=arr[i];
    }
    
    std::cout<<result;
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}