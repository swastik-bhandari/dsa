#include<iostream>
using namespace std;
inline int no_of_subarray(int x)
{
return (x*(x+1))/2;
}
void print_subarray(int *a , int n )
{
for(int i=0 ; i<n ; i++)
{
for(int j=i ; j<n; j++)
{
for(int k=i ; k<=j ; k++)
{
cout<<a[k];
}
cout<<",";
}
cout<<endl;
}
}
int main ()
{
int a[]={1,2,3,4,5};
int n = sizeof(a)/sizeof(a[0]);
int total_subarray = no_of_subarray(n);
cout<<total_subarray<<"\n";
print_subarray(a, n);
return 0;
}
