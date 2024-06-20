#include<iostream>
#include<algorithm>
using namespace std;
#define size 6
int partition_arr(int arr[] ,int  s, int e)
{ 
int i=s-1;
for(int j=s ; j<e ; j++)
{
if(arr[j]<arr[e])
{
i++;
swap(arr[j],arr[i]);
}
}
i++;
swap(arr[i],arr[e]);
return i;
}
void quicksort(int arr[] ,int s , int e)
{
if(s>=e)
{
return;
}
int pivotidx=partition_arr(arr , s, e);
quicksort(arr , s, pivotidx-1);
quicksort(arr,pivotidx+1,e);
}
int main ()
{
int arr[size];
for(int i=0 ; i<size ; i++)
{
cin>>arr[i];
}
quicksort(arr , 0 , size-1);
for(int i=0 ; i<size ; i++)
{
cout<<arr[i];
}
return 0;
}

