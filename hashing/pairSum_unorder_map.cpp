#include<iostream>
#include<vector>
#include<unordered_map>
#include<cmath>
using namespace std;

pair<int , int> pairSum(vector<int> & v , int target) {
unordered_map<int ,int> m;
for(int i=0 ; i<v.size() ; i++) {
int secPair = abs(v[i] - target) ;
if(m.find(secPair)!=m.end()) {
return pair<int , int>( m[secPair],i);
}
m[v[i]]=i;
}
return pair<int , int> (-1,-1);
}

int main () {
vector<int>v={1,2,7,11,15,5,9};
int target=12;
pair<int , int>p = pairSum(v ,target);
cout<<p.first<<" "<<p.second<<endl;
return 0;
}
