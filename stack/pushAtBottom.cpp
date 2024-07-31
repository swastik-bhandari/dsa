#include<iostream>
#include<stack>
using namespace std;
void pushAtBottom(stack<int> &s , int value)
{
if(s.empty())
{
s.push(value);
return;
}
int temp = s.top();
s.pop();
pushAtBottom(s,value);
s.push(temp);
}
int main()
{
stack<int>s;
s.push(1);
s.push(2);
pushAtBottom(s,0);
cout<<s.top();
s.pop();
cout<<s.top();
s.pop();
cout<<s.top();
return 0;
}
