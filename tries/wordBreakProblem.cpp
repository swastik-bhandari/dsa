#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class node {
unordered_map<char , node * > m;
bool endOfWord;
public:
friend class Tries;
node() : endOfWord(false) {}
};
class Tries {
node * root;
public:
Tries( ) {
root = new node;
}
void insert(string str) {
node * temp = root;
char ch;
for(int i=0 ; i<str.size() ; i++ ) {
ch=str[i];
if(!(temp->m).count(ch)) {
node * newnode = new node ;
temp->m[ch]=newnode;
}
temp=temp->m[ch];
}
temp->endOfWord=true;
}
bool search(string str) {
node * temp = root;
for(int i=0 ; i<str.size() ; i++ ) {
if(!temp->m.count(str[i])) {
return false;
}
temp= temp->m[str[i]];
}
return temp->endOfWord;
}
};

bool helper(Tries &t , string str) {
string first;
string second;
if(!str.size()) {
return true;
}
for(int i= 0 ; i<str.size() ; i++ ) {
first = str.substr(0 , i+1);   , // str.substr(index , length);
second = str.substr(i+1 );  
if(t.search(first) && helper(t , second)) {
return true;
}
}
return false;
}

bool wordBreak(vector<string> &v , string str ) {
Tries t;
for(int i=0 ; i<v.size() ; i++ ) {
t.insert(v[i]);
}
return helper(t , str) ;
}

int main () {
vector<string>v={"i" , "like" ,"likes", "sam" , "samsung" , "sung" , "mobile" , "ice" };
string str="ilikessamsung";
cout<<wordBreak(v , str);
return 0;
}
