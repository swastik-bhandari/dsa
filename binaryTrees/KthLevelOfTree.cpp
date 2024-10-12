#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class node {
int data;
node * left;
node * right;
public:
node() {}
friend node * buildTree(vector<int>);
friend void KthLevel(node * , int);
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
void KthLevel(node * root , int key ) {

queue<pair<int , node *>>Q;
int depth;
node * temp ;
Q.push({1,root});
while(!Q.empty()) {
temp=(Q.front()).second;
depth =(Q.front()).first;

if(temp->left){
Q.push({depth+1 , temp->left});
}
if(temp->right) {
Q.push({depth+1 , temp->right});
}
Q.pop();
if(depth==key)
{
cout<<temp->data;
}
if(depth>key) {
break;
}
}
}
int main ()
{
vector<int>v={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
node * root=buildTree(v);
KthLevel(root , 3);
return 0;
}
