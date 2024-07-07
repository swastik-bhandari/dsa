#include<iostream>
using namespace std;
template<typename T>
class node {
public:
T data ;
node<T> *next;
node()
{
next=nullptr;
}
node(T x):data(x){}
};
template<typename T>
class list {
public:
node<T> *head;
node<T> *tail;
list(){
head = nullptr;
tail= nullptr;
}
void push_back( T x)
{
node<T> * newnode = new node<T>;
newnode->data=x;
if (head==nullptr)
{
head=newnode;
tail=newnode;
}
else
{
tail->next=newnode;
tail=newnode;
}
}
};
int main ()
{
list<int>l;
l.push_back(5);
l.push_back(6);
l.push_back(7);
node<int>*ptr = l.head;
while(!(ptr==nullptr))
{
cout<<ptr->data;
ptr=ptr->next;
}
return 0;
}



