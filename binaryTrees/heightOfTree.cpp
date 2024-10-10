#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class node {
int data;
node * left;
node * right;
public:
node() {}
friend node * buildTree(vector<int>);
friend int height (node * );
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

int height(node * root )
{
if(root==nullptr)
{
return 0 ;
}
int h1=height(root->left);
int h2=height(root->right);
return (max(h1,h2)+1);
}
int main ()
{
vector<int>v={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
node * root=buildTree(v);
cout<<height(root);
return 0;
}
