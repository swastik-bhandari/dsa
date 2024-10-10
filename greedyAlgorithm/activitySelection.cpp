#include<iostream>
using namespace std;

class node {
int data;
node * next;
public:
node () {
data=0;
next=nullptr;
}
node (int data) : data (data) : next(nullptr){}
~node () {
}
};
class list {
private :
node * head ;
node * tail ;
void push_back(int x) {
node * newnode = new node (x);
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
 int a , b; 
list l;
l.

 
