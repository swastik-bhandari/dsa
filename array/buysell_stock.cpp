#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;
int main ()
{
  int a[]={7,1,5,3,6,4};
  int n =sizeof(a)/sizeof(a[0]);
  int max_profit=INT_MIN;
  int profit;
  for(int i=0 ; i<n;i++)
  {
    for(int j=0 ; j<i ; j++)
    {
      profit=a[i]-a[j];
    max_profit=max(profit , max_profit);
    }}
  cout<<max_profit;
  return 0;
}
