#include<iostream>
#include<vector>
using namespace std;

class node {
int data;
node * left;
node * right;
public:
node() {}
friend node * buildTree(vector<int> &, int &);
friend int KthAncestor(node * , int , int );
node ( int data) : data(data) {
left=nullptr;
right=nullptr;
}
};

node* buildTree(vector<int>& v, int& idx) {
    if (idx >= v.size() || v[idx] == -1) {
        idx++;
        return nullptr;
    }
    node* newnode = new node(v[idx]);
    idx++;
    newnode->left = buildTree(v, idx);
    newnode->right = buildTree(v, idx);
    return newnode;
}


int KthAncestor(node * root , int n , int k ) {
if (root==nullptr) {
return -1;
}
if( root->data == n ) {
return 1;
}
int leftN=KthAncestor(root->left , n , k );
int rightN=KthAncestor(root->right , n , k );
if( leftN==k || rightN==k) {
cout<<root->data;
}
if(leftN==-1 && rightN==-1) {
return -1;
}
if( leftN!=-1 ) {
return leftN+1;
}
return rightN+1;
}

int main ()
{
vector<int>v={8,1,2,4,-1,-1,5,-1,-1,3,6,-1,-1,3,-1,-1};
int idx=0;
node * root=buildTree(v, idx);
cout<<endl<<KthAncestor(root , 6 , 3);
return 0;
}
