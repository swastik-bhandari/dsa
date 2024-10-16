#include<iostream>
#include<vector>
using namespace std;

class node {
public:
int data;
node * left;
node * right;
public:
friend node * buildBST( vector<int>, int  , int  ) ;
friend node * BalancedBST_from_BST(node * ) ;
friend void inOrder(node *  , vector<int> &) ;
node () : data(-1) , left(nullptr) , right(nullptr) { }
node (int data) : data(data) , left(nullptr) , right(nullptr) {}
};

void inOrder( node * root , vector<int> &v) {
if( root==nullptr) {
return;
}
inOrder(root->left , v) ;
v.push_back(root->data);
inOrder(root->right , v);
}

node * buildBST( vector<int> v, int s ,int e ) {
if (s>e) {
return nullptr;
}
int m=s+(e-s)/2;
node * root=new node (v[m]);
root->left=buildBST( v , s , m-1);
root->right=buildBST( v , m+1 ,e);
return root;
}

node * BalancedBST_from_BST(node * root) {
vector<int>v;
inOrder(root , v );

return buildBST(v , 0 , v.size()-1);
}



int main () {
node * root=new node (6);
root->left=new node(5);
root->left->left=new node(4);
root->left->left->left = new node (3);
root->right = new node (7);
root->right->right= new node (8);
root->right->right->right= new node (9);
node * root1= BalancedBST_from_BST(root);
try {
cout<<root1->data;
cout<<root1->left->data;
cout<<root1->right->data;
cout<<root1->left->left->data;
cout<<root1->left->right->data;
cout<<root1->right->left->data;
cout<<root1->right->right->data;
}
catch (...) {
cout<<"error";
}
return 0;
 }
