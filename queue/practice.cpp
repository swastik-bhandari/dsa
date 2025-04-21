#include<iostream>
using namespace std;

class circularQueue {
int f;
int r;
int *arr;
int capacity;
int currSize;
public:
circularQueue(int capacity) : capacity(capacity) {
f=0;
r=-1;
currSize=0;
arr = new int[capacity];
}
~circularQueue(void) {
delete[] arr;
}

bool isEmpty(void) {
if(currSize==0) {
return true;
}
return false;
}
bool isFull(void) {
if(currSize==capacity) {
return true;
}
else {
return false;
}
}

void push(int x) {

if(isFull()) {
return;
}

r = (r+1)%capacity;

arr[r]=x;
currSize++;
}

void pop(void) {

if (isEmpty()){
return;
}

f=(f+1)%capacity;
currSize--;
}
int front(void) {
if(currSize==0) {
return -1;
}
return arr[f];
}
};
int main() {
circularQueue pq(5);
pq.push(3);
pq.push(7);
cout<<pq.front();
pq.pop();
cout<<pq.front();
return 0;
}






