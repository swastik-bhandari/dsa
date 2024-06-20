#include<iostream>
#include<algorithm>
void sort_arr(int * , int);
void display_arr(int * , int);
using namespace std;
int main ()
{
int a[]={1,2,3,4};
int n =sizeof(a)/sizeof(a[0]);
sort_arr(a,n);
display_arr(a,n);
return 0;
}
void sort_arr(int *a , int n)
{
//bool is_sorted=false;
while(n!=1)
{
for(int i=0 ; i<n-1; i++)
{
if(a[i]>a[i+1])
{
//is_sorted=true;
swap(a[i],a[i-1]);
break;
}
}
n--;
}
//(is_sorted==false)?cout<<"sorted":cout<<"notsorted";
}

void display_arr(int *a, int n)
{
for(int i=0 ; i<n ; i++)
{
cout<<a[i]<<",";
}
}
