#include<iostream>
using namespace std;

class node {
public:
int data ;
node * next;
node (int x ) :data(x) , next(nullptr) {}
};

class Queue {
public:
node *head;
Queue(){
head=nullptr;
}
void push (int x)
{
node * newnode = new node (x);

if (head==nullptr)
{
head=newnode;
}
else {
node *temp=head;
while(temp->next!=nullptr)
{
temp=temp->next;
}
temp->next=newnode ;
}
}
void pop (void)
{
if(head==nullptr)
{
cout<<"empty";
return;
}
node * temp;
temp=head;
head=head->next;
delete temp;
}
int front(void)
{
if(head==nullptr)
{
cout<<"empty";
return -1;
}
return head->data;
}
bool empty(void)
{
if(head==nullptr)
{
return true;
}
else {
return false;
}
}
};
int main ()
{
Queue q;
q.push(1);
cout<<q.front();
q.push(2);
cout<<q.front();
q.push(3);
cout<<q.front();
q.pop();
cout<<q.front();
return 0;
}

