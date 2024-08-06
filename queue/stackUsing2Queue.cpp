#include<iostream>
#include<queue>
using namespace std;

///////////////////////////
class Stack {
private:
queue<int>q1;
queue<int>q2;
public:

void push(int x)
{
while(!q1.empty())
{
q2.push(q1.front());
q1.pop();
}
q1.push(x);
while(!q2.empty())
{
q1.push(q2.front());
q2.pop();
}
}

void pop(void)
{
q1.pop();
}

int top(void)
{
return q1.front();
}

bool empty(void)
{
return q1.empty();
}

};

int main ()
{
Stack s;
s.push(1);
s.push(2);
s.push(3);

while(!s.empty())
{
cout<<s.top();
s.pop();
}
return 0;
}

