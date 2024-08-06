#include<iostream>
#include<deque>
using namespace std;

///////// driver code
int main ()
{
deque<int>q;
q.push_back(1);
q.push_front(0);
q.push_back(2);
q.push_front(-1);
q.push_back(3);
cout<<q.front()<<endl;
cout<<q.back()<<endl;
q.pop_back();
cout<<q.back()<<endl;
q.pop_front();
cout<<q.front()<<endl;
return 0;
}
