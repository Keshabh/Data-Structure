#include<iostream>
using namespace std;

int bin_search(int [],int start, int end, int k);

int main()
{
    //declare the arr and read the value of n form user
    int arr[20],n,ans,k;
    cout<<"Enter n: ";
    cin>>n;
    
    //read the value of arr 
    cout<<"Enter the elements of an array: \n";
    for(int i=0;i<n;i++)
      cin>>arr[i];
      
    //read the value to be found in the array
    cout<<"Enter the element to be search: ";
    cin>>k;
    
    //sort the arr
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                //swap them
                int t=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=t;
            }
        }
    }
    
    //display the sorted array
    cout<<"\nSorted Array: ";
    for(int i=0;i<n;i++)
      cout<<arr[i]<<" ";
    
    //call bin_search function
    ans=bin_search(arr,0,n-1,k);
    if(ans==-1)
      cout<<"\n\nNo such element were found in the array.";
    else
      cout<<"\n\nElement "<<k<<" found at location: "<<ans;
    
      
}

int bin_search(int arr[],int start, int end, int k)
{
    if(start<=end)
    {
        int mid=(start+end)/2;
        if(arr[mid]==k)
          return mid+1;
        else if (k>arr[mid])
          return bin_search(arr,mid+1,end,k);
        else
          return bin_search(arr,start,mid-1,k);
    }
    else
     return -1;
}
