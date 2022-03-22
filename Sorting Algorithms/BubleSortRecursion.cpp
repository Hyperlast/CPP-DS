#include <iostream>
#include <vector>

void Myswap(int& num1, int& num2) {
    int temp = num1;
    num1=num2;
    num2=temp;
}

void bubbleSortRecursion(std::vector<int>& arr,int n)
{
    if(n==1)
    return;

    for(int i=0;i<n-1;++i){
        if(arr[i]>arr[i+1]){
            Myswap(arr[i],arr[i+1]);
        }
    }

    return bubbleSortRecursion(arr,n-1);

}

void printarr(const std::vector<int>& arr)
{
    for(int i=0;i<arr.size();++i){
        std::cout << arr[i] << std::endl;
    }
}

int main()
{

    std::vector<int> arr ={1,0,4,5,6,2,3,4,10,20,15,2,-1};
    int n = arr.size();

    printarr(arr);
    std::cout<<"\n\n\n";
    bubbleSortRecursion(arr,n);

    printarr(arr);
    return 0;
}