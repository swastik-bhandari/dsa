#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class node {
unordered_map<char,node *> m;
bool endOfWord;
public:
friend class Tries;
node() :endOfWord(false) {}
};

class Tries {
node * root;
public:
Tries( ) {
root= new node;
}
void insert(string str) {
node * temp = root;
for(int i=0 ; i<str.size() ; i++ ) {

if( !temp->m.count(str[i]) ) {
node * newnode = new node;
temp->m[str[i]]=newnode;
}
temp= temp->m[str[i]];
}
temp->endOfWord=true;
}

bool searchPrefix(string str) {
node * temp = root;
for(int i=0 ; i<str.size() ; i++ ) {

if(!temp->m.count(str[i])) {
return false;
}
temp=temp->m[str[i]];
}
return true;
}

};

int main () {
vector<string>v={"apple" , "mango" , "man" , "women" };
Tries t;
for(int i=0 ;i<v.size() ; i++ ) {
t.insert(v[i]);
}
cout<<t.searchPrefix("wo");
}
