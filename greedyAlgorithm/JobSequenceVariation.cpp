/* #include<iostream>  // It is optimum but it does not handle for cases when 2 or more max values have same date for date >1
#include<vector>
#include<algorithm>
using namespace std;

int main ()
{
vector<pair<int , int>> v={ {100, 2}, {15, 1}, {50, 2}, {25, 1} };

sort(v.begin() , v.end() , [](pair<int , int>p1 , pair<int , int> p2) {

if(p1.second==p2.second)
{
return (p1.first>p2.first);
}
else
{
return(p1.second<p2.second);
}
});
///////////////////////
////////////////
int arr[30]={0};
int count=0;
int value=0;
for(pair<int , int>&p : v)
{
if(arr[p.second]==0) {
arr[p.second]=p.first;
count++;
value+=p.first;
}
}
cout<<count<<endl<<value;
return 0;
} */

