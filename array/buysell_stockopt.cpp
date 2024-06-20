#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;
int calc_profit(int *buy , int *sell , int n)
{ int max_profit=0;
  int profit;
  for(int i=0 ; i<n ; i++)
  {
    profit=sell[i]-buy[i];
    max_profit=max(max_profit , profit);
  }
  return max_profit;
}
int main ()
{
  int sell[]={7,1,5,3,6,4};
  int n=sizeof(sell)/sizeof(sell[0]);
  int buy[n]={INT_MAX};
  for(int i=1 ; i<n ; i++)
  {
buy[i]=min(sell[i],buy[i-1]);
  }
  int max_profit=calc_profit(buy, sell , n);
cout<<max_profit;
return 0;
}

