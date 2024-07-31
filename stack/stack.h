#ifndef STACK_H
#define STACK_H

#include<vector>
namespace mystack{
class stack {
std::vector<int>v;
public:
stack();
void push (int);
void pop(void);
int top(void);
};
}

#endif // STACK_H
