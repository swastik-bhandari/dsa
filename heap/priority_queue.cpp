#include<iostream>
#include<queue>
using namespace std;

int main () {

priority_queue<int> pq;
pq.push(5);
pq.push(10);
pq.push(3);
while(!pq.empty()) {
cout<<pq.top();
pq.pop();
}
return 0;
}
