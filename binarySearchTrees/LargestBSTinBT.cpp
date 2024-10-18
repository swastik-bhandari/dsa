#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

class info;
class node {
public:
int data ;
node * left;
node * right;
public:
friend node * buildBST (int * , int) ;
friend node * insert( node * , int ) ;
friend info LargestBSTinBT(node * );
friend void inOrder( node * );
node() : left(nullptr) , right(nullptr) , data(-1) {}
node( int data) : data(data) , left(nullptr) , right(nullptr) {}
};

class info {
public:
int mx ;
int mn;
bool isBST ;
int size;
info(int mx , int mn , bool isBST , int size ) : mx(mx) , mn(mn) , isBST(isBST) , size(size) {}
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

info LargestBSTinBT(node * root ) {
if( root==nullptr ) {
return info(INT_MIN , INT_MAX , true , 0) ;
}
info valueL = LargestBSTinBT(root->left);
info valueR = LargestBSTinBT(root->right);

int Max=max(root->data , max(valueL.mx , valueR.mx));
int Min=min(root->data , min(valueL.mn , valueR.mn));

if(valueL.isBST && valueR.isBST 
   && root->data > valueL.mx 
    && root->data < valueR.mn )
{
return info(Max , Min , true , valueL.size + valueR.size +1);
}
return info(Max , Min , false , max(valueL.size , valueR.size));
}

int main () 
{
//int arr[6]={5,1,3,4,2,7};
//node * root=buildBST(arr,6);
node * root= new node (50);
root->left = new node (30);
root->left->left= new node (5);
root->left->right= new node (20);
root->right = new node (60);
root->right->left = new node (45);
root->right->right = new node (70);
root->right->right->left = new node (65);
root->right->right->right= new node (80);

info val = LargestBSTinBT(root);
cout<<val.size;
return 0;
} 
