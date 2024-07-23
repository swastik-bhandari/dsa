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
int list:: searchItr(int key)
{
node *temp=head;
int i=0;
while(temp!=nullptr)
{
if(key==temp->data)
{
return i;
}
temp=temp->next;
i++;
}
return -1;
}
int list::searchRecHelper(int key , node * temp)
{
if(temp==nullptr)
{
return -1;
}
if(temp->data==key)
{
return 0;
}
return(searchRecHelper(key , temp->next)+1);
}
int list:: searchRec(int key )
{
return(searchRecHelper(key , head));
}
void list :: reverse(void)
{
node *prev=nullptr;
node *current=head;
node *after;
while(current!=nullptr)
{
after=current->next;
current->next=prev;
prev=current;
current=after;
}
tail=head;
head=prev;
}
void list :: removeNthFromBack(int idx)
{
node * temp=head;
int size=0;
while(temp!=nullptr)
{
size++;
temp=temp->next;
}
temp=head;
for(int i=0 ; i<size-idx-1 ; i++)
{
temp=temp->next;
}
node *toDelete=temp->next;
temp->next=temp->next->next;
delete toDelete;
}
node * list :: headObj(void)
{
return head;
}
bool list::checkPalindromeRec(void){
return (checkPalindromeRecHelper(head));
}
bool list::checkPalindromeRecHelper(node * temp2)
{
static node * temp1= head;
bool check=true;
if(temp2!=tail)
{
check=checkPalindromeRecHelper(temp2->next);
if(check==false)
{
return false;
}
}
if (temp1->data!=temp2->data)
{
return false;
}
else
{
temp1=temp1->next;
}
return true;
}
} //namespace mylist


