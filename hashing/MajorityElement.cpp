// find the element that appears more than n/3 times , where n is the total number of elements
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

void majorityElement(vector<int> &v) {
unordered_map<int ,int>m;
for(int i=0 ; i<v.size() ; i++ ) {   // O(n) + constant(for insertion )

if(m.count(v[i])) {
m[v[i]]++;
}
else {
m[v[i]]=1;
}
}

int fq=v.size()/3;
for( pair<int,int> it : m ) { // O(n) in worst case if all elements are unique; , map and unordered_map uses pair for storing key value pair .

if(it.second > fq ) {
cout<<it.first;
}
}
}






int main () {
vector<int>v={1,2};

majorityElement(v);

return 0;
}
