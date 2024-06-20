#include<iostream>
using namespace std;
void set_array(int [] , int);
#define size 10

int linear_search(int [] , int , int );
int main()
{
  int arr[size];
int n=sizeof(arr)/sizeof(arr[0]);
int key;
cin>>key;
set_array(arr , n);
int index=linear_search(arr , n , key);
cout<<index;
return 0;
}
int linear_search(int arr[] , int n , int key)
{
  for (int i=0 ; i<n ; i++)
{
  if(arr[i]==key)
  {
    return i;
  }
}
return -1;
}
void set_array(int arr[] , int n)
{
  for(int i=0 ; i<n ; i++)
  {
    cin>>arr[i];
  }
}

