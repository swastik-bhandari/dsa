#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int countDistinct(vector<int> &v) {
unordered_set<int>s;
for(int &it : v) {   // O(n)
s.insert(it);
}
for(auto &it : s) {
cout<<it<<" ";
}
cout<<endl;
return s.size();
}
int main () {
vector<int>v={4,3,2,5,6,7,3,4,2,1};
cout<<countDistinct(v);
return 0;
}
