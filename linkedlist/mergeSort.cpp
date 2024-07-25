#include<iostream>
using std::cout;
using std::cin;
using std::endl;
class node{
public:
int data;
node *next;
node(){
next=nullptr;
}
node (int x):data(x){}
};
class list{
public:
node *head;
node *tail;
list(){
head=nullptr;
tail=nullptr;
}
    ~list() {
        node* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
        }
void push_back(int x){
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
void push_front(int x){
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
void display(void)
{
node *temp=head;
while(temp!=nullptr)
{
std::cout<<temp->data;
temp=temp->next;
}
}
};
node* splitAtMid(node * Head)
{
node * slow =Head;
node * fast=Head;
node * prev;
while(fast && fast->next)
{
prev=slow;
slow=slow->next;
fast=fast->next->next;
}
prev->next=nullptr;
return slow;
}
///////////////////////////////////////////////////////
node* merge(node * Head , node *rightHead)
{
list *newlist = new list();
node *temp1=Head;
node *temp2=rightHead;
while(temp1!=nullptr && temp2!=nullptr)
{
if(temp1->data>temp2->data)
{
newlist->push_back(temp2->data);
temp2=temp2->next;
}
else
{
newlist->push_back(temp1->data);
temp1=temp1->next;
}
}
while(temp1){
newlist->push_back(temp1->data);
temp1=temp1->next;
}
while(temp2){
newlist->push_back(temp2->data);
temp2=temp2->next;
}
delete Head;
delete rightHead;
return newlist->head;
}
/////////////////////////////////////////////////////////
node * mergeSort (node * Head)
{
if(!Head || !Head->next)
{
return Head;
}
node * rightHead = splitAtMid(Head);
node *left=mergeSort(Head);
node *right=mergeSort(rightHead);
return(merge(left, right));
}
//////////////////////////////////////////////////////////

int main()
{
list l;
l.push_back(3);
l.push_back(2);
l.push_back(1);
l.push_back(4);
l.head=mergeSort(l.head);
l.display();
return 0;
}
