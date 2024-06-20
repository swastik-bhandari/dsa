#include<iostream>
#include<vector>
using namespace std;
void conquer(int arr[] , int s, int e, int mid)
{
vector<int>v;
int i=s;
int j =mid+1;
while(i<=mid && j<=e)
{
if(arr[i]>arr[j])
{
v.push_back(arr[j]);
j++;
}
else
{
v.push_back(arr[i]);
i++;
}
}
for(i ; i<=mid ; i++)
{
v.push_back(arr[i]);
}
for(j ; j<=e ; j++)
{
v.push_back(arr[j]);
}
for(int i=s , x=0; i<=e ; i++)
{
arr[i]=v[x++];
}
}
void divide(int arr[] , int s , int e  )
{
int mid=s+(e-s)/2;
if(e>s)
{
divide(arr ,s , mid);
divide(arr , mid+1 , e);
conquer(arr , s, e , mid);
}
}
int main ()
{
const int size=6;
int arr[size];
for(int i=0 ; i<size ; i++)
cin>>arr[i];
divide(arr , 0 , size-1);
for(int i=0 ; i<size ; i++)
cout<<arr[i];
return 0;
}


