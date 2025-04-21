#include<iostream>
#include<vector>

using namespace std;

class node {
public:
int data;
node * left;
node * right;
friend void buildTree(vector<int>&);
public:
node(int data) : data(data) {
left = nullptr;
right = nullptr;
}
};

node * buildTree(vector<int>& v, int &idx) {
idx++;
node * newnode = new node(v[idx]);

if(v[idx]==-1) {
return nullptr;
}
newnode->left = buildTree(v , idx);
newnode->right = buildTree(v ,idx);
return newnode;
}
void inorder(node* root) {
if(root==nullptr) return;
inorder(root->left);
cout<<root->data;
inorder(root->right);
}




int main() {
int idx=-1;
vector<int>v={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
node * root = buildTree(v,idx);
inorder(root);
return 0;
}

