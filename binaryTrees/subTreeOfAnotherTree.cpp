#include<iostream>
#include<vector>
using namespace std;

class node {
int data;
node * left;
node * right;
public:
node() {}
friend node * buildTree(vector<int> , int &);
friend bool compare(node * , node * );
friend bool searching( node* , node * );
node ( int data) : data(data) {
left=nullptr;
right=nullptr;
}
};
node * buildTree(vector<int>v , int &idx) {
idx++;
node * newnode = new node (v[idx]);
if(v[idx]==-1) {
return nullptr;
}
newnode->left=buildTree(v , idx);
newnode->right=buildTree(v , idx);
return newnode;
}
bool searching(node * root1 , node * root2) {
if(root1==nullptr)
{
return 0;
}
if( root1->data==root2->data)
{
   if(compare(root1 , root2)) {
   cout<<"subtree found"<<endl;
   return 1;
   }
}
return (searching(root1->left , root2) || searching(root1->right , root2));
}
bool compare(node * root1 , node * root2)
{
if(root1==nullptr && root2==nullptr) {
return 1;
}
if(root1==nullptr || root2==nullptr)
{
return 0;
}
if( root1->data !=root2->data)
{
return 0;
}
bool val1= compare(root1->left, root2->left);
bool val2=compare(root1->right , root2->right);
return (val1 && val2);
}
int main ()
{
vector<int>v={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
vector<int>v2={2,4,-1,-1,5,-1,-1};
int idx=-1;
int idx2=-1;
node * root1=buildTree(v ,idx);
node * root2=buildTree(v2 , idx2);
cout<<searching(root1 , root2);
return 0;
}
