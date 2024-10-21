#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int minSum(vector<int> &v ) {
priority_queue<int , vector<int> , greater<int>>pq(v.begin() , v.end());
int sum=0 ;
while(pq.size()>1) {
int min1=pq.top();
pq.pop();
int min2=pq.top();
pq.pop();
sum+=min1+min2;
pq.push(min1+min2);
}
return sum;
}

int main () {
vector<int>v={4,3,2,6};
cout<<minSum(v);
return 0;
}
