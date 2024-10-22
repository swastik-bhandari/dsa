// i used pair inside deque to store both index and value , but you do this question only storing the index in the queue .

#include<iostream>
#include<vector>
#include<deque>
using namespace std;

void slidingWindowMax(vector<int> &v , int k ) {
deque<pair<int , int>>dq;

for(int i=0 ; i<v.size() ; i++) {

while(!dq.empty() && dq.back().second < v[i]) {
dq.pop_back();
}
dq.push_back(make_pair(i , v[i]));

while(!dq.empty() && dq.front().first < i-k+1 ) {
dq.pop_front();
}

if(i > k-2) {
cout<<dq.front().second;
}
}
}

int main () {
vector<int>v={7,8,3,6,2,10 ,1 ,4 ,9};
int k=5;
slidingWindowMax(v , k);
return 0;
}
