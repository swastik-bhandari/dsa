#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

int zeroSumLargestSubarray(vector<int>& v , int k) {
unordered_map<int,int>m;
int sum=0;
int maxL=0;
for(int i=0 ; i<v.size() ; i++ ) { //O(n)
if(v[i]==k) {
maxL=max(maxL ,1);
}
sum+=v[i];
if(sum==k) {
maxL=max(maxL , i+1);
}
if(m.count(sum-k)){
maxL=max(maxL , i-m[sum-k]);
}
else {
if(!m.count(sum)) {
m[sum]=i;
}
}
}
return maxL;
}

int main () {
vector<int>v={15,-2,2,-8,1,7,10};
int k=7;
cout<<zeroSumLargestSubarray(v ,k);
return 0;
}
