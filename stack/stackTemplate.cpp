#include<iostream>
#include<vector>
using std::cin;
using std::cout;
using std::endl;
template<typename T>
class stack{
private:
std::vector<T> v;
public:
stack() {}
void  push (T x)
{
v.push_back(x);
}
void pop(void)
{
v.pop_back();
}
T top (void)
{
int idx=v.size()-1;
return v[idx];
}
};
int main ()
{
stack<char> s;
s.push('c');
s.push('h');
s.push('a');
cout<<s.top();
s.pop();
cout<<s.top();
return 0;
}
