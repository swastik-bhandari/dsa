#include<iostream>
#include<vector>
#include<stack>
using namespace std;

///////////////////////////////////////////////////////////////////
void nextGreaterElement(vector<int> &v , vector<int> &span)
{
stack<int>greaterElement;
int size=v.size();
greaterElement.push(v[size-1]);

////////
for (int i=size-2 ; i >=0 ; i--)
{
while(!greaterElement.empty() && v[i]>=greaterElement.top())
{
greaterElement.pop();
}
if(greaterElement.empty())
{
span[i]=-1;
}
else
{
span[i]=greaterElement.top();
}
greaterElement.push(v[i]);
}
}
int main ()
{
vector<int>v={6,8,0,1,3};
vector<int>s={0,0,0,0,-1};
nextGreaterElement(v,s);
for(int i=0 ;i<s.size() ; i++)
{
cout<<s[i]<<" ";
}
return 0;
}


