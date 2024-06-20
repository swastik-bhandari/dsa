#include<iostream>
using namespace std;
#include<algorithm>
#define size 3
int main ()
{
  int nums[size][size];
  for(int i=0 ; i<size ;i++)
  {
    for(int j=0 ; j<size ;j++)
    {
      cin>>nums[i][j];
    }
  }
  for (int i=0 ;i<size ;i++)
  {
    sort(nums[i] , nums[i]+size);
  }
for(int i=0 ; i<size ;i++)
  {
    for(int j=0 ; j<size ;j++)
    {
      cout<<nums[i][j];
    }
    cout<<endl;
  }
return 0;
}
