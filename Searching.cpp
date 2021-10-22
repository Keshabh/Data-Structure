#include<iostream>
using namespace std;

//declare linear_search and binary_search functions to perform searching on arr
int linear_search(int arr[],int n,int k);
int binary_search(int arr[],int n,int k);

int main()
{
    //declare the array arr 
    int arr[20],n,k,ans;
    //read the size of arr
    cout<<"Enter n: ";
    cin>>n;
    //read the values from array
    cout<<"Enter elements in an array: \n";
    for(int i=0;i<n;i++)
      cin>>arr[i];
    
    //read the value of element to be found i.r k
    cout<<"\nEnter the value to be found in the array: ";
    cin>>k;
    
    //search the element through both the algorithm
    //search through linear search
    cout<<"\nUsing Linear Search: \n";
    ans=linear_search(arr,n,k);
    if(ans==-1)
      cout<<"No such element found in the array.\n";
    else
      cout<<"Element found at location: "<<ans<<"\n";
    
    //search through binary search
    cout<<"\nUsing Binary Search: \n";
    //sort the arr to be passed in binary_search function
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                //swap it
                int t=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=t;
            }
        }
    }
    //display the sorted arr
    cout<<"Sorted Array : ";
    for(int i=0;i<n;i++)
      cout<<arr[i]<<" ";
    //call binary_search function
    ans=binary_search(arr,n,k);
    if(ans==-1)
      cout<<"\nNo such element found in the array.\n";
    else
      cout<<"\nElement found at location: "<<ans<<"\n";
      
}

//define linear_search function
int linear_search(int arr[],int n,int k)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]==k)
        {
            return i+1;
        }
    }
    return -1;
}

//define binary_search function
int binary_search(int arr[],int n,int k)
{
    int start=0,end=n-1;
    while(start<=end)
    {
        int mid=(start+end)/2;
        if(arr[mid]==k)
          return mid+1;
        //if k is bigger than mid, then go to right sub-array
        else if(k>arr[mid])
        {
            start=mid+1;
        }
        //if k is smaller than mid , then we need to go to left sub-array
        else if(k<arr[mid])
        {
            end=mid-1;
        }
    }
    return -1;
}
