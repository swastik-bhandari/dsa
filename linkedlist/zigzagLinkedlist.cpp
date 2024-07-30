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
void reverse(node *&slow)
{
node *prev=nullptr;
node *current=slow;
node *after;
while(current!=nullptr)
{
after=current->next;
current->next=prev;
prev=current;
current=after;
}
slow=prev;
}
void zigzaglist(node *head)
{
node *slow=splitAtMid(head);
reverse(slow);
node *left=head;
node *right=slow;
node *leftNext;
node *rightNext;
node * tail;
while(left && right)
{
leftNext=left->next;
rightNext=right->next;
left->next=right;
right->next=leftNext;
tail=right;
left=leftNext;
right=rightNext;
}
tail->next=right;
}
int main ()
{
list l ;
for(int i=0 ; i<5 ; i++)
{
l.push_back(i+1);
}
l.display();
zigzaglist(l.head);
std::cout<<endl;
l.display();
return 0;
}
