#include<iostream>
using namespace std;

///////////////////////////
class Queue {
private: ///// private members
int *arr ;
int currentSize;
int capacity;
int f;
int rear;
public: /////// public members

Queue(int capacity) {
this->capacity=capacity;
arr= new int[capacity];
currentSize=0;
f=0;
rear=-1;
}

///////////////////
~Queue()
{
delete[] arr;
}

/////////////////
void push (int x)
{
if(currentSize>=capacity)
{
cout<<"house full"<<endl;
return;
}
rear=(rear+1)%capacity;
arr[rear]=x;
currentSize++;
}

//////////////////////
void pop(void)
{
if(empty())
{
cout<<"empty";
return;
}
f=(f+1)%capacity;
currentSize--;
}

///////////////////
int front(void)
{
if(empty())
{
cout<<"empty";
return -1;
}
return arr[f];
}

////////////////////////
bool empty(void)
{
if(currentSize==0)
{
return 1;
}
return 0;
}
};

////////////// driver code 
int main ()
{
Queue q(3);
//q.push(1);
//q.push(2);
//q.push(3);
//q.pop();
//cout<<q.empty();
//q.push(4);
//cout<<q.front();
return 0;
}
