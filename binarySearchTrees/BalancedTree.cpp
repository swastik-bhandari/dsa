#include<iostream>
#include<vector>
using namespace std;

class node {
public:
int data;
node * left;
node * right;
public:
friend node * buildBST( int * , int  , int  ) ;
node () : data(-1) , left(nullptr) , right(nullptr) { }
node (int data) : data(data) , left(nullptr) , right(nullptr) {}
};

node * buildBST( int * arr , int s ,int e ) {
if (s>e) {
return nullptr;
}
int m=s+(e-s)/2;
node * root=new node (arr[m]);
root->left=buildBST( arr , s , m-1);
root->right=buildBST( arr , m+1 ,e);
return root;
}
int main () {
int arr[]={3,4,5,6,7,8,9};
int size =7;
node * root= buildBST( arr , 0 ,size-1);
cout<<root->data;
cout<<root->left->data;
cout<<root->right->data;
cout<<root->left->left->data;
cout<<root->left->right->data;
cout<<root->right->left->data;
cout<<root->right->right->data;
return 0;
 }
