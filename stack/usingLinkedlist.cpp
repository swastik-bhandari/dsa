#include<iostream>
#include<list>
using namespace std;
template<typename T>
class stack {
list<T>l;
public:
void push (T x)
{
l.push_front(x);
}
void pop (void)
{
l.pop_front();
}
T top(void)
{
return l.front();
}
};
int main ()
{
stack<int>s;
s.push(1);
s.push (2);
s.push(3);
cout<<s.top();
s.pop();
cout<<s.top();
return 0;
}
