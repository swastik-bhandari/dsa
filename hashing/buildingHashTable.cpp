#include<iostream>
using namespace std;

class node {
int value;
string key;
node * next ;
friend class HashTable;
public:
node () {}
node (string key , int value) : key(key) , value(value) , next(nullptr) {}
~node() {
if(next!=nullptr){
delete next;
}
}
};

class HashTable {
int totSize;
int currSize;
node ** table;
int hashFunction(string key);
void rehash(void);
public:
HashTable(int totSize ) : totSize(totSize) , currSize(0) {
table = new node * [totSize];
for(int i=0 ; i<totSize ; i++) {
table[i]=nullptr;
}
}

void insert(string key , int value ) ;
void erase(string key);
int search(string key);
void print(void);
bool exists( string key );

};

int HashTable::hashFunction(string key) {
int val=0;
for(int i=0 ; i<key.size() ; i++ )
{
val+= key[i]*key[i];
}
return val%totSize;
}

void HashTable::rehash ( void ) {
int oldSize=totSize;
int oldcurrSize = currSize;
node ** oldTable= table;

totSize=2*totSize;
currSize =0;
table= new node*[totSize];
for(int i=0 ; i<totSize ; i++ ) {
table[i]=nullptr;
}
for(int i=0 ; i<oldSize ; i++) {
node * temp = oldTable[i];
while(temp!=nullptr) {
insert(temp->key , temp->value);
temp=temp->next;
}
}
currSize=oldcurrSize; // extra precaution 
for(int i=0 ;i<oldSize ; i++){
delete oldTable[i];
}
oldTable=nullptr;
}

void HashTable :: insert(string key , int value ) {
currSize++;
node * newnode = new node (key , value);
int hashCode = hashFunction(key);
newnode->next=table[hashCode];
table[hashCode]=newnode;
double loadFactor = (double)currSize/totSize;
if(loadFactor>1) {
rehash();
}
}

int HashTable :: search(string key) {
int hashCode = hashFunction(key);
node * temp = table[hashCode];
while(temp!=nullptr) {
if( temp->key == key ) {
return temp->value;
break;
}
temp=temp->next;
}
return -1;
}

void HashTable:: print(void) {
for(int i=0 ; i<totSize ; i++) {
node * temp = table[i];
while(temp!=nullptr) {
cout<<temp->key<<" "<<temp->value<<endl;
temp=temp->next;
}
}
}

bool HashTable:: exists(string key ) {

int hashCode = hashFunction(key);
node * temp = table[hashCode];
while(temp!=nullptr) {
if(temp->key == key ) {
return true;
}
temp=temp->next;
}
return false;
}

void HashTable:: erase(string key) {
if(!exists(key)){
return;
}
int hashCode= hashFunction(key);
node * temp = table[hashCode];
node * prev=nullptr;
if(temp->key==key) {
table[hashCode]=temp->next;
temp->next=nullptr;             // it is important to null the next of node that is to be deleted because if next of temp is not null and is pointing 
delete temp;                   //to its adjecent node , all the nodes after it will be delete due to destructor ~node() {} . 
return;
}
while(temp!=nullptr ) {
if(temp->key==key) {
prev->next=temp->next;
temp->next=nullptr;
delete temp;
return;
}
prev=temp;
temp=temp->next;
}
}

int main () {
HashTable ht(4);
ht.insert("india" ,150);
ht.insert("china" ,150);
ht.insert("UK" ,20);
ht.insert("nepal" ,10);
ht.insert("US" , 50);
ht.erase("nepal");
ht.print();
return 0;
}
