#include<iostream>
using namespace std;
int main ()
{
  int a[]={2,5,8,7,3};
  int n = sizeof(a)/sizeof(a[0]);
  int *ptr1 , *ptr2;
  ptr1=&a[0];
  ptr2=&a[n-1];
  while(ptr1<ptr2)
  {
    int temp= *ptr1;
    *ptr1=*ptr2;
    *ptr2=temp;
    ptr1++;
    ptr2--;
  }
for(int i=0 ; i<n ;i++)
{
  cout<<a[i];
}
  return 0;
}

