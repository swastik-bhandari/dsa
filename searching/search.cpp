#include<iostream>
using namespace std;
int search (int * , int , int );
int main ()
{
int a[]={8,7,6,1,2,3,4,5};
int n=sizeof(a)/sizeof(a[0]);
int key;
cin>>key;
cout<<search(a, n , key);
return 0;
}
int search (int *a , int n , int key)
{
  int s=0 , e=n-1;
  while(s<=e)
  {
int   m=s+(e-s)/2;
  if (a[m]==key)
  {
    return m;
  }
  else if (a[m]<=a[e])
  {
    if(key<=a[e] && key>a[m])
    {
      s=m+1;
    }
    else
    {
      e=m-1;
    }
  }

    else
    {
      if (key>=a[s] && key<a[m])
      {
        e=m-1;
      }
      else
      {
        s=m+1;
      }
    }
  }
  return -1;
}
