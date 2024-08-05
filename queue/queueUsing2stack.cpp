#include<iostream>
#include<stack>
using namespace std;

////////////////////////////////////
class Queue {
stack<int>s1;
stack<int>s2;
public:
void push (int x)
{
///////
while(!s1.empty())
{
s2.push(s1.top());
s1.pop();
}
//////////////////////////
s1.push(x);
while(!s2.empty())
{
s1.push(s2.top());
s2.pop();
}
}
//////////////////////////////
void pop(void)
{
s1.pop();
}
///////////////////////////
int front(void)
{
return s1.top();
}
///////////
bool empty(void)
{
if(s1.empty())
{
return true;
}
else {
return false;
}
}

};////////
int main ()
{
Queue q;
q.push(1);
q.push(2);
q.push(3);
while(!q.empty())
{
cout<<q.front()<<endl;
q.pop();
}
return 0;
}
