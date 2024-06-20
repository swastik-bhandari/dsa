#include<iostream>
#include<climits>
#include<algorithm>
//1e+5 is bydefault double 
#define size (int)1e+5
using namespace std;
int main ()
{
int nums[]={1,4,1,3,2,4,3,7};
int n=sizeof(nums)/sizeof(nums[0]);
int freq[size]={0};
int max_value=INT_MIN;
int min_value=INT_MAX;
//first part
for(int i=0 ; i<n ; i++)
{
max_value=max(max_value,nums[i]);
min_value=min(min_value,nums[i]);
}
//second part
for(int i=0 ;i<n ; i++)
{
freq[nums[i]]++;
}
//final part
for(int i=min_value , j=0 ;i<=max_value ;i++)
{
while(freq[i]>0)
{
nums[j++]=i;
freq[i]--;
}
}
for(int i=0 ; i<n ;i++)
cout<<nums[i];
return 0;
}
