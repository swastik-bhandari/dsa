#include<iostream>
#include<vector>
using namespace std;

class node {
int data ;
node * left;
node * right;
public:
friend node * buildBST (int * , int) ;
friend node * insert( node * , int ) ;
friend void inOrder( node * );
friend void rootToLeafPath( node * , vector<int> );
node() : left(nullptr) , right(nullptr) , data(-1) {}
node( int data) : data(data) , left(nullptr) , right(nullptr) {}
};

node * insert( node * root , int value ) {
if( root == nullptr)
{
root=new node (value) ;
return root ;
}
if( value < root->data) {
root->left = insert(root->left , value);
}
if( value > root->data) {
root->right= insert(root->right , value) ;
}
return root;
}

node * buildBST ( int *arr , int n ) {
node * root = nullptr;
for(int i=0 ; i<n ; i++) {
root = insert(root , arr[i]);
}
return root;
}
void inOrder( node * root) {
if( root == nullptr) {
return;
}
inOrder(root->left);
cout<<root->data;
inOrder(root->right);
}

void printRange(vector<int> v) {

for(int it : v) {
cout<<it;
}
cout<<endl;
}

void rootToLeafPath ( node * root , vector<int> v) {
if( root==nullptr) {
return;
}
v.push_back(root->data);
rootToLeafPath(root->left , v);
rootToLeafPath(root->right , v);

if(!root->left && !root->right) {
printRange(v);
}
v.pop_back();
}

int main () 
{
int arr[6]={5,1,3,4,2,7};
node * root=buildBST(arr ,6);
vector<int>v;
rootToLeafPath(root , v);
return 0;
} 
