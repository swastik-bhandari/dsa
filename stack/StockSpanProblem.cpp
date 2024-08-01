#include<iostream>
#include<vector>
#include<stack>
using namespace std;
//////////////////////////
void stockSpan(vector<int>&v)
{
vector<int>span;
stack<int>prevHigh;

span.push_back(1);
prevHigh.push(0);

for(int i=1 ; i<v.size() ; i++)
{
while(!prevHigh.empty() && v[i]>=v[prevHigh.top()])
{
prevHigh.pop();
}
if (!prevHigh.empty())
{
span.push_back(i-prevHigh.top());
}
else
{
span.push_back(i);
}
prevHigh.push(i);
}
for(int i=0 ; i < span.size()  ; i++)
{
cout<<span[i]<<" ";
}
}
int main ()
{
vector<int>v={100,80,60,70,60,85,100};
stockSpan(v);
return 0;
}

