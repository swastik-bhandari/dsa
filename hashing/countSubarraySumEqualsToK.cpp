#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int countSubarray(vector<int>&v , int k) {
unordered_map<int , int>m;
m[0]=1;
int ans=0;
int sum=0;
for(int i=0 ; i<v.size() ; i++ ) {
sum+=v[i];
if(m.count(sum-k)) {   // left = sum-k   , sum =right        ,     ans += m[left] ; , m[right]++;
ans+=m[sum-k];
}
if(m.count(sum)) {
m[sum]++;
}
else {
m[sum]=1;
}
}
return ans;
}



int main () {
vector<int>v={0,0,0,0};
int k=0;
cout<<countSubarray(v , k);
return 0;
}
