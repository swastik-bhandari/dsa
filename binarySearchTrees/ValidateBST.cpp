#include<iostream>
#include<climits>
using namespace std;

class node {
public:
int data ;
node * left;
node * right;
public:
friend node * buildBST (int * , int) ;
friend node * insert( node * , int ) ;
friend void inOrder( node * );
friend bool validateBST(node * , int , int );
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

bool validateBST(node * root , int mx , int mn ) {
if( root==nullptr) {
return true;
}
if( root->data <= mn || root->data >= mx ) {
return 0;
}
bool valueL = validateBST(root->left , root->data , mn) ;
bool valueR = validateBST(root->right , mx , root->data ) ;
return ( valueL && valueR) ;
}

int main () 
{
int arr[]={5,1,4,3,7};
node * root= buildBST(arr , 5);
cout<<validateBST(root , INT_MAX , INT_MIN);
return 0;
} 
