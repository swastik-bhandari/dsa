#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

int zeroSumLargestSubarray(vector<int>& v) {
unordered_map<int,int>m;
int sum=0;
int maxL=0;
for(int i=0 ; i<v.size() ; i++ ) { //O(n)
if(v[i]==0) {
maxL=max(maxL ,1);
}
sum+=v[i];
if(sum==0) {
maxL=max(maxL , i+1);
}
if(m.count(sum)){
maxL=max(maxL , i-m[sum]);
}
else {
m[sum]=i;
}
}
return maxL;
}

int main () {
vector<int>v={-2,2,-8,1,7,10};
cout<<zeroSumLargestSubarray(v);
return 0;
}
