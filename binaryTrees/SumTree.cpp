#include<iostream>
#include<vector>
using namespace std;

class node {
public:
int data;
node * left;
node * right;
node() {}
friend node * buildTree(vector<int>);
friend int sumTree(node * );
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

int sumTree(node * root) {
if ( root ==nullptr ) {
return 0;
}
int leftS=sumTree(root->left); 
int rightS=sumTree(root->right);
int temp=root->data;
root->data=leftS+rightS;
return ( temp + leftS+rightS) ;
}
int main ()
{
vector<int>v={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
node * root=buildTree(v);
sumTree(root);
cout<<root->data<<endl;
cout<<root->left->data<<endl;
cout<<root->right->data<<endl;
return 0;
}
