#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;
int main ()
{
int a[]={-5,-3,-2,-5,-1,-4};
int n=sizeof(a)/sizeof(a[0]);
int max_sum=INT_MIN;
int sum=0;
for(int i=0 ; i<n ; i++)
{
sum+=a[i];
max_sum=max(sum , max_sum);
if (sum<0)
{
sum=0;
}}
cout<<max_sum;
return 0;
}
