#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

void itineraryFromTickets(vector<pair<string , string>>& v) {
unordered_map<string , string>m;
unordered_set<string>s;
for(pair<string , string>& p : v) {
m[p.first]=p.second;
s.insert(p.second);
}
string key;
for( auto& p : m) {
if(!s.count(p.first)) {
key=p.first;
break;
}
}
while(m.count(key)) {
cout<<key<<"->";
key=m[key];
}
cout<<key;
}


int main () {
vector<pair<string , string>>v ={{"chennai","bengaluru"},{"mumbai","delhi"},{"goa","chennai"},{"delhi","goa"}};
itineraryFromTickets(v);
return 0;
}
