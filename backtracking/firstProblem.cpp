#include<iostream>
using namespace std;
void changearr(int *arr , int n , int i)
{
if(i>=n)
{
return;
}
arr[i]=i+1;
changearr(arr,n,i+1);
arr[i]=arr[i]-2;
}
int main ()
{
const int size=5;
int arr[size]={0};
changearr(arr,size,0);
for(int i=0 ; i<size ; i++)
cout<<arr[i];
return 0;
}

