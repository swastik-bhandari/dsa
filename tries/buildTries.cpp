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

int main ( )  {
vector<string>v={"the","their" , "a" , "there" , "thee" };
Tries t;
for(int i=0 ; i<v.size() ; i++ ) {
t.insert(v[i]);
}
cout<<t.search("the");
return 0;
}
















