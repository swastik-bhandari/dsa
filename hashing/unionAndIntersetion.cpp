#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;

void Union(vector<int> &v1 , vector<int> &v2) {
unordered_set<int>s;
for(auto& it : v1) {
s.insert(it);
}
for(auto& it: v2) {
s.insert(it);
}
for(auto& it : s){
cout<<it;
}
}

void Intersection(vector<int>& v1  , vector<int>& v2) {
unordered_set<int>s;
for(auto& it: v1) {
s.insert(it);
}
for(auto& it : v2) {
if(s.count(it)) {
cout<<it;
s.erase(it);
}
}
}

int main () {
vector<int>arr1={7,3,9};
vector<int>arr2={6,3,9,2,9,4};
Union(arr1 ,arr2);
Intersection(arr1 , arr2);
return 0;
}
