#include<iostream>
using std::cin;
using std::cout;
template<typename T>
class node {
public:
T data ;
node(){
next=nullptr;
}
node(T x):data(x){}
node<T> *next;
};
template<typename T>
class list {
public:
node<T> *head;
node<T> *tail;
public:
list(){
head=nullptr;
tail=nullptr;
}
void push_front(T x)
{
node<T>* newnode=new node<T>(x);
if(head==nullptr)
{
head=newnode;
tail=newnode;
}
else
{
newnode->next=head;
head=newnode;
}}
};
int main ()
{
list<int>l;
l.push_front(5);
l.push_front(6);
l.push_front(7);
node<int> *it=l.head;
while(it!=nullptr)
{
cout<<it->data;
it=it->next;
}
return 0;
}

