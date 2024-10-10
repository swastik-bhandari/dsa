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
friend void levelOrderTraverse(node * );
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
void levelOrderTraverse( node * root ) 
{
queue<node * >Q;
Q.push(root);
while (!Q.empty()){
if (root->left) {
Q.push(root->left) ;
}
if(root->right) {
Q.push(root->right);
}
cout<<root->data;
Q.pop();
root=Q.front();
}
}
int main ()
{
vector<int>v={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
node * root=buildTree(v);
levelOrderTraverse(root);
return 0;
}

