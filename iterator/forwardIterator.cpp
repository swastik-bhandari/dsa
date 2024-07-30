#include<iostream>
#include<forward_list>
using namespace std;
int main()
{
forward_list<int> l={1,2,3,4};
l.push_front(0);                   /// push back is not supported in forward_list
for(forward_list<int>::iterator it=l.begin() ; it!=l.end() ; it++) // it<=l.end() not valid , < is not supported in iterators . 
{
cout<<*it;
}
return 0;
}
