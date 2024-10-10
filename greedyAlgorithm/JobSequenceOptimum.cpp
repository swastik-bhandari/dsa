#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
int main ()
{
vector<pair<int, int>> v={{1,20},{2,10},{2,40},{1,30}};

///////// arranging the pairs in decending order with respect to profit .
sort(v.begin() , v.end() , [](pair<int , int >p1 , pair<int , int>p2) { return (p1.second>p2.second) ;});

/////// finding the maximum deadline 

int l=INT_MIN ;
for(pair<int , int> &p :v)
{
if(l<p.first)
{
l=p.first;
}
}
//////////////////////// 
int profit =0;
vector<int>timestrap(l,0);
for(int i=0 ; i<v.size() ; i++)
{
int deadline =v[i].first;
while(deadline>0)
{
if(timestrap[deadline-1]==0)
{
timestrap[deadline-1]=1;
profit+=v[i].second;
break;
}
deadline--;
}
}
cout<<profit;
return 0;
}
