#include<iostream>
#include<queue>
using namespace std;

////////////////////
void interLeaveQueue(queue<int>&q1)
{
int size=q1.size();
queue<int>q2;
for(int i=0 ; i<size/2 ;i++)
{
q2.push(q1.front());
q1.pop();
}

while(!q2.empty())
{
q1.push(q2.front());
q2.pop();
q1.push(q1.front());
q1.pop();
}
}
int main ()
{
queue<int>q;
q.push(1);
q.push(2);
q.push(3);
q.push(4);
q.push(5);
q.push(6);
q.push(7);
q.push(8);
q.push(9);
q.push(10);
interLeaveQueue(q);
while(!q.empty())
{
cout<<q.front()<<"->";
q.pop();
}
}
