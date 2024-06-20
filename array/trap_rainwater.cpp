#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;
int main ()
{
int bar[]={0,1,0,2,1,0,1,3,2,1,2,1};
int n=sizeof(bar)/sizeof(bar[0]);
int left_max[n]={0};
int right_max[n]={0};
right_max[n]=0;
for (int i=1 ; i<n ; i++)
{
  left_max[i]=max(left_max[i-1],bar[i-1]); 
}
for (int i=n-2 ; i>=0 ; i--)
{
  right_max[i]=max(right_max[i+1],bar[i+1]);
}
int c , water_trap=0;
for(int i=1 ; i<n-1 ; i++)
{
   c=min(left_max[i] , right_max[i])-bar[i];
   if (c>0)
   {
   water_trap+=c;
   }
}
cout<<water_trap;
return 0;
}
