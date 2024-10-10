#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int W=50;


int main ()
{
int maxValue=0;
int weight=W;
vector<int>val{100,60 , 120 };
vector<int>wt{20 , 10 , 30};
vector<pair<int ,int>>v;
//////////////////////
///////////
for(int i=0 ; i<val.size() ; i++)
{
v.push_back(make_pair(val[i]/wt[i] , i));
}
sort(v.begin() , v.end() , [](pair<int , int>p1 , pair<int ,int>p2) { return p1.first>p2.first ; });
///////////////////////////////////
///////////////////////
//////
for(int i= 0 ; i <v.size() ; i++)
{
if(wt[v[i].second] <= weight)
{
maxValue+=wt[v[i].second]*v[i].first;
weight-=wt[v[i].second];
}
else
{
maxValue+=weight*v[i].first;
weight=0;
break;
}
}
cout<<maxValue;
return 0;
}

