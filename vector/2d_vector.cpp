#include<iostream>
#include<vector>
using namespace std;
void display (vector<vector<int>> &);
int main ()
{
vector<vector<int>>mat; //={{1,2,3},{4,5,6},{7,8,9}};
mat[0]
display (mat);
return 0;
}
void display(vector<vector<int>> &mat)
{
for (int i=0 ; i<mat.size() ; i++)
  {
  for (int j= 0 ; j<mat[i].size() ; j++)
    {
    cout<<mat[i][j]<<" ";
    }
    cout<<endl;
  }
}

