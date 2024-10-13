#include<iostream>
#include<vector>
using namespace std;

class node {
int data;
node * left;
node * right;
public:
node() {}
friend node * buildTree(vector<int>);
friend int findNode ( node * , int , int ) ;
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
int findNode( node * root , int n1 , int n2) {
if( root==nullptr)
{
return -1;
}
if( root->data==n1 || root->data==n2) {
return root->data;
}
int valueL=findNode(root->left , n1 , n2);
int valueR=findNode(root->right , n1 , n2) ;
if(valueL!=-1 && valueR!=-1) {
return root->data;
}
if(valueL!=-1) {
return valueL;
}
return valueR;
}
int main ()
{
vector<int>v={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
node * root=buildTree(v);
cout<<findNode(root , 4,5);
return 0;
}
