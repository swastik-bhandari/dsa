#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class node {
int data;
node * left;
node * right;
public:
node() {}
friend node * buildTree(vector<int>);
friend pair<int , int> diameter(node * );
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
pair<int ,int> diameter(node * root )
{
if ( root == nullptr)
{

return pair<int , int >(0,0);
}
pair<int , int> leftmax = diameter(root->left);
pair<int , int> rightmax=diameter(root->right);
int currentheight=max(leftmax.first,rightmax.first) +1;
int currentdiameter= leftmax.first+rightmax.first+1;
int maxdiameter=max( max( leftmax.second , rightmax.second ) , currentdiameter);
return  pair<int , int>( currentheight ,maxdiameter) ;
}



int main ()
{
vector<int>v={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
node * root=buildTree(v);
pair<int , int> p= diameter(root);
cout<<p.first<<endl<<p.second;
return 0;
}
