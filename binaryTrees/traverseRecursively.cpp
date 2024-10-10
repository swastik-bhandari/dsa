#include<iostream>
#include<vector>
using namespace std;

class node {
int data;
node * left;
node * right;
public:
node() : data(0 ) , left(nullptr) , right(nullptr) {}
node ( int data) : data(data) {
left=nullptr;
right=nullptr;
}
friend node * buildTree(vector<int>);
friend void preOrderTraverse(node * );
friend void inOrderTraverse(node * );
friend void postOrderTraverse(node *);
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
////////////////////////////////////// preOrderTraverse
void preOrderTraverse (node * root) {
if(root==nullptr)
{
return;
}
cout<<root->data;
preOrderTraverse(root->left);
preOrderTraverse(root->right);
}
//////////////////////////////////// inOrderTraverse
void inOrderTraverse (node * root) {
if( root ==nullptr)
{
return;
}
inOrderTraverse(root->left);
cout<<root->data;
inOrderTraverse(root->right);
}
////////////////////////////////// postOrderTraverse 
void postOrderTraverse(node * root) {
if( root ==nullptr) {
return;
}
postOrderTraverse(root->left);
postOrderTraverse(root->right);
cout<<root->data;
}
int main ()
{
vector<int>v={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
node * root=buildTree(v);
//preOrderTraverse(root);
//inOrderTraverse(root);
postOrderTraverse(root);
return 0;
}
