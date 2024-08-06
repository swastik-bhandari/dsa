#include<iostream>
#include<deque>
using namespace std;

////////////////////////
template<typename T>
class Queue {
private: // private members
deque<T>dq;

public: // public members

void push(int x)
{
dq.push_back(x);
}

void pop(void)
{
dq.pop_front();
}

T front(void)
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
}; // class Queue

int main() // driver code 
{
Queue<int>q;
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
