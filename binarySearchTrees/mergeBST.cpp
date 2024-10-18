#include<iostream>
#include<vector>
using namespace std;

class node {
public:
int data;
node * left;
node * right;
node() : data(-1) , left(nullptr) , right(nullptr) {}
node ( int data) : data(data) , left(nullptr) , right(nullptr) {}
};

void TreeConversion(node * root , vector<int> & v ) {
if(root==nullptr) {
return;
}
TreeConversion(root->left , v);
v.push_back(root->data);
TreeConversion(root->right , v);
}



int * mergeVector(vector<int>&v1 , vector<int>&v2){
int size = v1.size() + v2.size();
int * arr = new int [size] ;
int i=0 , j=0 , k=0;
while( i<v1.size() && j<v2.size() ) {
if(v1[i] <v2[j]) {
arr[k]=v1[i];
i++;
}
else {
arr[k]=v2[j];
j++;
}
k++;
}
while(i<v1.size()) {
arr[k]=v1[i];
i++ ;
k++;
}
while(j<v2.size()) {
arr[k]=v2[j];
j++;
k++;
}
return arr;
}

node * intoBalancedTree(int * arr ,int s ,int e) {

if(s>e) {
return nullptr;
}
int m=s+(e-s)/2;
node * root = new node (arr[m]);
root->left= intoBalancedTree(arr , s , m-1);
root->right=intoBalancedTree(arr , m+1 , e);
return root;
}


node * mergeBST(node * root1 , node * root2) {
vector<int>v1;
vector<int>v2;
TreeConversion(root1 , v1);
TreeConversion(root2 , v2);
int * arr = mergeVector(v1 , v2);
node * temp= intoBalancedTree(arr , 0  , v1.size() + v2.size()-1);
delete [] arr;
return temp;
}




int main () {
node * root1 = new node (2);
root1->left= new node (1);
root1->right= new node (4);

node * root2 = new node (9);
root2->left= new node(3);
root2->right= new node (120);

node * root= mergeBST(root1 , root2);
cout<<root->data;
cout<<root->left->data;
cout<<root->right->data;
cout<<root->left->right->data;
cout<<root->right->left->data;
cout<<root->right->right->data;

return 0;
}
