#include<iostream>
using namespace std;

class node {
int data ;
node * left;
node * right;
public:
friend node * buildBST (int * , int) ;
friend node * insert( node * , int ) ;
friend void inOrder( node * );
friend node * searchBST( node * , int );
friend node * deleteNode ( node * , int  ) ;
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

node * deleteNode ( node * root , int key ) {
if( root==nullptr) {
return nullptr;
}
if( root->data == key ) {

if (!root->left && !root->right) {
delete root ;
return nullptr;
}
if( root->left || root->right ) {
node * temp = (root->left)?(root->left) : (root->right) ;
delete root ;
return temp;
}

}
if( key < root->data ) {
root->left=deleteNode(root->left , key );
return root;
}
root->right=deleteNode(root->right , key );
return root;
}

int main () 
{
int arr[6]={5,1,3,4,2,7};
node * root=buildBST(arr ,6);
int key =4;

return 0;
} 
