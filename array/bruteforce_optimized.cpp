#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;
int main ()
{
  int max_sum=INT_MIN;
  int a[]={2,-3 , 4 ,-5,8,6};
  int n=sizeof(a)/sizeof(a[0]);
  for(int i=0 ; i<n ; i++)
  {
    int sum=0;
    for(int j=i ; j<n ; j++)
    {
    sum+=a[j];
    max_sum=max(max_sum , sum);
    }
  }
  cout<<max_sum;
  return 0;
}
