#include<iostream>
#include<algorithm>
using namespace std;
int main ()
{
int nums[]={1,4,1,3,2,4,3,7};
int n=sizeof(nums)/sizeof(nums[0]);
sort(nums, nums+n);//accending 
for(int i=0 ; i<n ; i++)
cout<<nums[i];
sort(nums , nums+n , greater<int>());//decending , from greater to smaller 
for(int i=0 ; i<n ; i++)
cout<<nums[i];
return 0;
}
