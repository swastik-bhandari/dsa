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
friend void printInRange(node * , pair<int,int> ) ;
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

void printInRange(node * root , pair<int, int>p ) {
if(root==nullptr) {
return;
}
if(root->data > p.first) {
printInRange(root->left, p );
}
if(root->data >= p.first && root->data <= p.second ) {
cout<<root->data;
}
if(root->data < p.second ) {
printInRange(root->right , p ) ;
}
}
int main () 
{
int arr[9]={8,5,3,1,4,6,10,11,14};
node * root=buildBST(arr ,9);
pair<int , int> p= {4,12};
printInRange(root , p ) ;
return 0;
} 
