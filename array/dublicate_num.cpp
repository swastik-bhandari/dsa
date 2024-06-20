#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
bool repeat_num (vector<int> & num , int n)
{
for(int i=1 ;i<n ; i++)
{
if ( num[i]==num[i-1])
{
return true;
}
}
return false;
}
int main ()
{
vector<int>num={1,3,2,4,5,2};
int 	n=sizeof(num)/sizeof(num[0]);
sort(num.begin(),num.end());
cout<<repeat_num(num , n);
return 0;
}
