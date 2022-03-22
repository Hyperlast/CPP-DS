#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

void merge(std::vector<int>& arr,int l,int m,int r)
{   
    const int size1= (m-l+1);
    const int size2= (r-m);
    int* arr1= new int[size1];
    int* arr2 = new int[size2];
    
    for(int i=0;i<size1;++i)
    {
        arr1[i]=arr[l+i];
    }

     for(int i=0;i<size2;++i)
    {
        arr2[i]=arr[m+i+1];
    }
    
    int i=0,j=0,k=l;
    while(i<size1 && j<size2)
    {
        if(arr1[i]>=arr2[j])
        {
            arr[k]=arr2[j];
            ++j;
            ++k;
        }
        else
        {
            arr[k]=arr1[i];
            ++i;
            ++k;
        }
    }
    
    while(i<size1)
    {
        arr[k]=arr1[i];
        i++;
        k++;
    }

    while(j<size2)
    {
        arr[k]=arr2[j];
        j++;
        k++;
    }
    delete[] arr1;
    delete[] arr2;
}

void mergeSort(std::vector<int>& arr,int l,int r)
{
    if(l<r)
    {
        int mid =l + (r-l)/2;
        
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
}

int main() {
    std::vector<int> arr;
    int n;
    std::cin>>n;
    for(int i=0;i<n;++i)
    {
        int temp;
        std::cin>>temp;
        arr.push_back(temp);
    }
    
    mergeSort(arr,0,arr.size()-1);
    
    std::vector<int> resultArr;
    resultArr.push_back(arr[0]);
    int j=0;
    const int Size= arr.size();
    for(int i =0;i<Size;++i)
    {
        if(arr[i]>resultArr[j])
        {
            resultArr.push_back(arr[i]);
            ++j;
        }
    }
    const int Size2 = resultArr.size();
    for(int i=0;i<Size2;++i)
    {
        std::cout<<resultArr[i]<<' ';
    }
     
    return 0;
}
