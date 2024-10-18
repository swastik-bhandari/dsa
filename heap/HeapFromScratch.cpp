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
return v[0];
}

bool empty(void) {
return(v.empty());
}

};

int main () {
Heap hp ; 
hp.push(50);
hp.push(100);
hp.push(30);
cout<<hp.top()<<endl;
cout<<hp.empty()<<endl;
return 0;
}


