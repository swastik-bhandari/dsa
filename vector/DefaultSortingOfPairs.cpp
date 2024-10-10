#include<iostream>
#include<utility>
#include<algorithm>
#include<vector>
using namespace std;
bool modifiedCompare(pair<int , int >&p1 , pair<int , int>&p2)
{
return (p1.second<p2.second);
}
int main ()
{
vector<pair<int , int > > v ;
v.push_back(make_pair(0,9));
v.push_back(make_pair(1,2));
v.push_back(make_pair(2,4));

sort(v.begin() , v.end() , modifiedCompare );
for(int i=0 ;i<3 ;i++)
{
cout<<"("<<v[i].first<<","<<v[i].second<<")"<<endl;
}
return 0;
}
