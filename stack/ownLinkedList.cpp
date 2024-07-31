#include<iostream>

/////////////////////////////////////////////////
template<typename T>
class node {
public:
T data;
node *next;

node (T x):data(x), next(nullptr){}
};
//////////////////////////////////////////////////
template<typename T>
class stack {
private:
node<T> * head;

///////////
public:
void push (T x)
{
node<T> * newnode =new node<T>(x);
if(head==nullptr)
{
head=newnode;
}
else
{
newnode->next=head;
head=newnode;
}
}
void pop (void)
{
if(head==nullptr)
{
return;
}
else
{
node<T> *temp=head;
head=head->next;
delete temp;
}
}
T top(void)
{
return head->data;
}
};
int main ()
{
stack<int>s;
s.push(1);
s.push(2);
s.push(3);
std::cout<<s.top();
s.pop();
std::cout<<s.top();
return 0;
}

