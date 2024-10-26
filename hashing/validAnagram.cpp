#include<iostream>
#include<unordered_map>
using namespace std;

bool validAnagram(string s , string t) {
unordered_map<char , int>m;
if(s.size()!=t.size()) {
return false;
}
for(int i=0 ; i<s.size() ; i++) {

if(m.count(s[i])) {
m[s[i]]++;
}
else {
m[s[i]]=1;
}
}

for(int i=0 ;i<t.size() ;i++) {

if(m.count(t[i]) && m[t[i]]>0) { // m.count(t[i]) is non necessaryly needed , because m[t[i]] will eventually return 0 if key doesnt exist.
m[t[i]]--;
continue;
}
return false;
}
return true;
}

int main () {
string s="listen";
string t="silenn";

cout<<validAnagram(s , t);
return 0;
}
