#include<iostream>
#include<stack>
#include<vector>
#include<climits>
using namespace std;

///////////////////////////////
int maxAreaInHistogram(vector<int> &v)
{
int size=v.size();
vector<int>rightMaxWidth(size,0);
rightMaxWidth[size-1]=1;
vector<int>leftMaxWidth(size, 0);
leftMaxWidth[0]=1;
stack<int>sL;
sL.push(0);
stack<int>sR;
sR.push(size-1);

/////////////// leftMaxWidth
for(int i=0 ; i<size ; i++)
{

while(!sL.empty() && v[i]<=v[sL.top()])
{
sL.pop();
}
if(sL.empty())
{
leftMaxWidth[i]=i+1;
}
else {
leftMaxWidth[i]=i-sL.top();
}
sL.push(i);
}
/////////////////// rightmaxwidth
for(int i=size-2 ; i>=0 ;i--)
{

//////////
while(!sR.empty() && v[i]<=v[sR.top()])
{
sR.pop();
}
if(sR.empty())
{
rightMaxWidth[i]=size-i;
}
else {
rightMaxWidth[i]=sR.top()-i;
}
sR.push(i);
}

///////////////// calculating area 
vector<int>area(size,0);
int max_area=INT_MIN;
for(int i=0 ; i<size ; i++)
{
area[i]=v[i]*(leftMaxWidth[i]+rightMaxWidth[i]-1);
if(max_area<area[i])
{
max_area=area[i];
}
}
return max_area;
}
int main ()
{
vector<int>v={2,1,5,6,2,3};
cout<<maxAreaInHistogram(v);
return 0;
}
