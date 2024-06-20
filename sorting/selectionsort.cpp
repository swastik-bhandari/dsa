#include<iostream>
#include<algorithm>
using namespace std;
int main ()
{
int nums[]={5,4,1,3,2};
int n=sizeof(nums)/sizeof(nums[0]);
for(int i=0 ; i<n-1 ; i++)
{
for(int j=i+1 ; j<n ; j++)
{
if (nums[i]>nums[j])
{
swap(nums[i],nums[j]);
}
}
}
for(int i=0 ; i<n ; i++)
{
cout<<nums[i];
}
return 0;
}
