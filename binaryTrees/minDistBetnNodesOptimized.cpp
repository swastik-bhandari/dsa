// If one of node which we pass does not exit , this algorithm will print 0 . if you want to print -1 to indicate node not found , you should consider optimized one .
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
friend node * findNode ( node * , int , int ) ;
friend int minDistance (node * , int , int );
friend int distance ( node * , int , int );
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
node * findNode( node * root , int n1 , int n2) {
if( root==nullptr)
{
return nullptr;
}
if( root->data==n1 || root->data==n2) {
return root;
}
node * valueL=findNode(root->left , n1 , n2);
node * valueR=findNode(root->right , n1 , n2) ;
if(valueL!=nullptr && valueR!=nullptr) {
return root;
}
if(valueL!=nullptr) {
return valueL;
}
return valueR;
}

int distance( node * lca ,int n ,int count) {
if( lca ==nullptr ) {
return -1;
}
count ++;
if( lca->data==n) {
return count;
}
int leftD= distance(lca->left , n , count);
int rightD= distance(lca->right , n , count);
if ( leftD ==-1 && rightD == -1) {
return -1;
}
return ((leftD !=-1)? leftD : rightD);
}

int minDistance ( node * root , int n1 , int n2 ) {
node * lca = findNode(root , n1 , n2);
int d = distance(lca  , n1  , -1 );
int d2 = distance(lca  , n2  , -1);
if( d==-1 || d2==-1){
return -1;
}
return d+d2;
}

int main ()
{
vector<int>v={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
node * root=buildTree(v);
cout<<minDistance(root , 2,4);
return 0;
}
