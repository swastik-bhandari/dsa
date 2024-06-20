#include<iostream>
using namespace std;
int main ()
{
int **mat=new int *[4];
for (int i=0 ; i<4 ; i++)
{
 mat[i]=new int [3];
}
for (int i=0 ; i<4 ;i++)
 {
 for (int j=0 ; j <3 ; j++)
   {
   cin>>mat[i][j];
   }
  }
  
for (int i=0 ; i<4 ;i++)
 {
 for (int j=0 ; j <3 ; j++)
   {
   cout<<mat[i][j]<<" ";
   }
  cout<<endl;
  }
for (int i=0 ; i<4 ; i++)
{
delete [] mat[i];
mat[i]=nullptr;
}
delete [] mat;
mat=nullptr;
return 0;
}
