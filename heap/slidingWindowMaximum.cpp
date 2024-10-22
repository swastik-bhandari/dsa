#include<iostream>
#include<queue>
#include<vector>
using namespace std;

void slidingWindowMaximum(vector<int>&v , int k ) {
priority_queue<pair<int,int>>pq;
for(int i=0 ; i<v.size() ; i++) {
pq.push(make_pair(v[i] , i));
while(pq.top().second < i-k+1) {
pq.pop();
}
if(i>k-2) {
cout<<pq.top().first;
}
}
}

int main () {
vector<int> v={1,3,-1,-3,5,3,6,7};
int k=4;
slidingWindowMaximum(v ,k);
return 0;
}
