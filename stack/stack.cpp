#include"stack.h"
namespace mystack {
stack :: stack() {}

void stack :: push (int x)
{
v.push_back(x);
}
void stack :: pop(void)
{
v.pop_back();
}
int stack :: top (void)
{
int idx=v.size()-1;
return v[idx];
}
} // mystack namespace 
