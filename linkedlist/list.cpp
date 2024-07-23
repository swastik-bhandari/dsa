#include"list.h"
namespace mylist {
list::list():head(nullptr),tail(nullptr){}
list::~list(){
node *temp;
while(head!=nullptr)
{
temp=head;
head=head->next;
delete temp;
}
head=nullptr;
}
void list::push_back(int x){
node* newnode =new node(x);
if(head==nullptr)
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
void list::push_front(int x){
node *newnode = new node(x);
if(head==nullptr)
{
head=newnode;
tail=newnode;
}
else
{
newnode->next=head;
head=newnode;
}
}
void list::display(void)
{
node *temp=head;
while(temp!=nullptr)
{
std::cout<<temp->data;
temp=temp->next;
}
}
void list::pop_back(void)
{
node *temp=head;
while(temp->next!=tail)
{
temp=temp->next;
}
temp->next=nullptr;
delete tail;
tail=temp;
}
void list::pop_front(void) {
if(head==nullptr)
{
return;
}
else
{
node *temp=head;
head=head->next;
delete temp;
}
}
} //namespace mylist
