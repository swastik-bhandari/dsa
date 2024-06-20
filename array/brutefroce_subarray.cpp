#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;
void maxsum_subarray(int *a , int n )
{
int max_subarray=INT_MIN;
for(int i=0 ; i<n ; i++)
{
for(int j=i ; j<n; j++)
{
int sum=0;
for(int k=i ; k<=j ; k++)
{
sum+=a[k];
}
max_subarray=max(sum , max_subarray);
}
}
cout<<max_subarray;
}
int main ()
{
int a[]={2,-3,3,6,-4,5};
int n = sizeof(a)/sizeof(a[0]);
maxsum_subarray(a, n);
return 0;
}
