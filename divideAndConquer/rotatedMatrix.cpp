#include<iostream>
using namespace std;
int search(int *arr , int s , int e , int key)
{
if(s>e)
{
return -1;
}
int mid =s+(e-s)/2;
if(arr[mid]==key)
{
return mid;
}
if(arr[mid]<=arr[e])
{
if(key>arr[mid] && key<=arr[e])
{
return search(arr , mid+1 , e , key);
}
else
{
return search(arr , s , mid-1 , key);
}
}
else
{
if(key>=arr[s] && key<arr[mid])
{
return search(arr , s , mid-1, key);
}
else
{
return search(arr , mid+1 ,e , key);
}
}
}
int main ()
{
const int size=6;
int arr[size] , key;
cout<<"enter the key"<<"\n";
cin>>key;
cout<<"enter elements of array"<<"\n";
for(int i=0 ; i<size ; i++)
{
cin>>arr[i];
}
cout<<search(arr , 0 , size-1, key);
return 0;
}
