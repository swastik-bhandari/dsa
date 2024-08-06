#include<iostream>
#include<deque>
using namespace std;

////////////////////////
template<typename T>
class Stack {
private: // private members
deque<T>dq;

public: // public members

void push(int x)
{
dq.push_front(x);
}

void pop(void)
{
dq.pop_front();
}

T top(void)
{
return dq.front();
}

bool empty(void)
{
if(dq.empty())
{
return true;
}
else {
return false;
}
}
}; // class Stack

int main() // driver code 
{
Stack<int>s;
s.push(1);
s.push(2);
s.push(3);
while(!s.empty())
{
cout<<s.top()<<endl;
s.pop();
}
return 0;
}
