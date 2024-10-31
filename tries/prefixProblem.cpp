#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class node {
unordered_map<char , node * > m;
bool endOfWord;
int freq;
public:
friend class Tries;
node () : freq(0) , endOfWord(false) {}
};

class Tries {
node * root;
public:
Tries () {
root = new node ;
}
void insert(string str) {
node * temp = root;
for(int i=0 ; i<str.size() ; i++ ) {
char ch=str[i];
if(!temp->m.count(ch)){
node * newnode = new node;
temp->m[ch]=newnode;
}
temp=temp->m[ch];
temp->freq++;
}
temp->endOfWord=true;
}

string helper(string str ) {
string prefix="";
node *temp = root;
for(int i=0 ; i<str.size() ; i++ ) {

if(temp->freq==1) {
return prefix;
}
temp=temp->m[str[i]];
prefix+=str[i];
}
return prefix;
}

};

void printPrefix( Tries t  , vector<string>&v) {

for(int i=0 ; i <v.size() ; i++ ) {
cout<<t.helper(v[i])<<endl;
}
}

int main () {
vector<string>v={"zebra" , "duck" , "dog" , "dove" , "donkey" , "done" };
Tries t;
for(int i=0 ; i <v.size() ; i++  ) {
t.insert(v[i]);
}
printPrefix(t, v);
return 0;
}


