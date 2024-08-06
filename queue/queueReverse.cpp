#include<iostream>
#include<queue>
#include<stack>
using namespace std;
/////////////////
void reverseQueue(queue<int>&q)
{
stack<int> s;
while(!q.empty())
{
s.push(q.front());
q.pop();
}
while(!s.empty())
{
q.push(s.top());
s.pop();
}
}
//////////////////
int main ()
{
queue<int>q;
q.push(1);
q.push(2);
q.push(3);
q.push(4);
q.push(5);

reverseQueue(q);
while(!q.empty())
{
cout<<q.front();
q.pop();
}
return 0;
}
