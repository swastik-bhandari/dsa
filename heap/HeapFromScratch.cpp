#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Heap {
private:
vector<int> v;
public:

void push( int x ) {
v.push_back(x);
int n=v.size()-1;
while(n>0) {
int i=(n-1)/2;

if(v[i]>v[n]) {
break;
}
swap(v[i] , v[n]);
n=i;
}
}

int top(void) {
if(v.empty()) {
return -1;
}
return v[0];
}

bool empty(void) {
return(v.empty());
}

void heapify(int p) {

int maxIdx=p;
int c1=p*2+1;
int c2=p*2+2;
if(c1<v.size() && v[maxIdx] < v[c1]) {
maxIdx=c1;
}
if(c2<v.size() && v[maxIdx] < v[c2] ) {
maxIdx=c2;
}
if(p!=maxIdx) {
swap(v[maxIdx] , v[p]);
heapify(maxIdx);
}
}

void pop(void) {
swap(v[0] , v[v.size()-1]);
v.pop_back();
heapify(0);
}

};

int main () {
Heap hp ; 
hp.push(50);
hp.push(100);
hp.push(30);
cout<<hp.top()<<endl;
cout<<hp.empty()<<endl;
hp.pop();
cout<<hp.top()<<endl;
return 0;
}


