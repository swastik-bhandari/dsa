#include<iostream>
using namespace std;
int binary_search(int * , int , int);
int main ()
{
int a[] = {1,2,3,4,5,6,7};
int n=sizeof(a)/sizeof(a[0]);
int key;
cin>>key;
int c=binary_search(a , n , key);
cout<<c;
return 0;
}
int binary_search(int *a , int n , int key)
{
int s=0 , e=n-1;
while(s<=e)
{
int  m=s+(e-s)/2;
if(a[m]==key)
{
return m;
}
else if (a[m]<key)
{
s=m+1;
}
else{
e=m-1;
}
}
return -1;
}
