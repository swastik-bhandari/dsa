#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;

class node {
int data;
node * left;
node * right;
public:
node() {}
friend node * buildTree(vector<int>);
friend void topView(node * );
node ( int data) : data(data) {
left=nullptr;
right=nullptr;
}
};
static int idx=-1;
node * buildTree(vector<int>v ) {
idx++;
node * newnode = new node (v[idx]);
if(v[idx]==-1) {
return nullptr;
}
newnode->left=buildTree(v);
newnode->right=buildTree(v);
return newnode;
}
//////////////////////////////
////////////
void topView( node * root) {
map <int , int > m;
queue<pair<int , node * >> Q;
Q.push({0, root});
//////////////////////////
while(!Q.empty()) {
node * temp= (Q.front()).second;
int hd=(Q.front()).first;
if(!m.count(hd)){
m[hd]=temp->data;
}
if (temp->left){
Q.push({hd-1,temp->left});
}
if (temp->right){
Q.push({hd+1,temp->right});
}
Q.pop();
}
for(auto it : m)
{
cout<<it.first<<" " <<it.second<<endl;
}
}
///////////////////////////
////////////
int main ()
{
vector<int>v={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
node * root=buildTree(v);
topView(root);
return 0;
}

