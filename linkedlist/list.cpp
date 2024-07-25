#include"list.h"
namespace mylist {
list::list():head(nullptr),tail(nullptr){}
list::~list(){
node *temp;
if(isCircle())
{
while(head!=tail)
{
temp=head;
head=head->next;
tail->next=head;
delete temp;
}
delete head;
}
else
{
while(head!=nullptr)
{
temp=head;
head=head->next;
delete temp;
}
}
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
bool list :: checkPalindrome (void){
//using slow and fast pointer technique
node * slow=head;
node * fast=head;
while(fast!=nullptr && fast->next!=nullptr)
{
slow=slow->next;
fast=fast->next->next;
}
node * prev=nullptr;
node * current=slow;
node * after;
while(current!=nullptr)
{
after=current->next;
current->next=prev;
prev=current;
current =after;
}
node *temp1=head;
node *temp2=prev;
while(temp2!=nullptr){
if(temp1->data!=temp2->data)
{
return false;
}
temp1=temp1->next;
temp2=temp2->next;
}
return true;
}
bool list::isCircle(void)
{
node * fast=head;
node *slow=head;
while(fast && fast->next)
{
slow=slow->next;
fast=fast->next->next;
if(slow==fast)
{
return 1;
}
}
return 0;
}
void list::makeCircular(void)
{
tail->next=head;
}
void list::removeCircle(void)
{
node *fast=head;
node *slow=head;
while(fast && fast->next)
{
slow=slow->next;
fast=fast->next->next;
if(slow==fast)
{
break;
}
}
if(!fast || !fast->next)
{
return;
}
slow=head;
if(slow==fast) // if the linkedlist is purely circular , slow=head=fast
{
while(fast->next!=slow)
{
fast=fast->next;
}
fast->next=nullptr;
}
else
{
node *prev;
while(slow!=fast)
{
prev=fast;
fast=fast->next;
slow=slow->next;
}
prev->next=nullptr;
}
}
///////////////////////////////////////////////////////// Merge Sort
void list::sort(void)
{
head=mergeSort(head);
node *temp=head;
while(temp->next){
temp=temp->next;
}
tail=temp;
}
node * list::mergeSort (node * Head)
{
if(!Head->next || !Head)
{
return Head;
}
node * rightHead = splitAtMid(Head);
node *left=mergeSort(Head);
node*right=mergeSort(rightHead);
return (merge(left , right));
}
node* list::splitAtMid(node * Head)
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

node* list :: merge(node * Head , node *rightHead)
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

} //namespace mylist


