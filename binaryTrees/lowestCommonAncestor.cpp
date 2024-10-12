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
bool findpath(node * root , int n1 , int n2) {

if(root==nullptr)
{
return 0;
}
bool num1=findpath(root->left , n1 , n2);
bool num2=findpath(root->right , n1 , n2);
if(root->value==n1 || root->data==n2) {
return 1;
}
int main ()
{
vector<int>v={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
node * root=buildTree(v);
return 0;
}
