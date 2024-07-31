#include<iostream>
#include"stack.h"
using std::cout;
using namespace mystack;
int main ()
{
stack s;
s.push(1);
s.push(2);
s.push(3);
std::cout<<s.top();
s.pop();
std::cout<<s.top();
return 0;
}
