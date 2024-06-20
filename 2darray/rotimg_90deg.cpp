#include<iostream>
using namespace std;
#define size 3
void rotate_mat(int (*)[size] , int , int );
int main ()
{
int arr[][size]={{1,2,3},{4,5,6},{7,8,9},{10,11,12}};
int n=sizeof(arr)/sizeof(arr[0]);
int m=sizeof(arr[0])/sizeof(arr[0][0]);
for (int i=0 ; i<n; i++)
{
for (int j=0 ; j<m ; j++)
{
cout<<arr[i][j]<<" ";
}
cout<<endl;
}
cout<<endl;
rotate_mat(arr , n , m );
return 0;
}
void rotate_mat(int arr[][size] , int n , int m)
{
int rot_mat[m][n];
for (int i=0 ; i<n ; i++)
  {
  for (int j=0 ; j<m ; j++)
    {
    rot_mat[j][n-i-1]=arr[i][j];
    }
  }
for (int i=0 ; i<m; i++)
{
for (int j=0 ; j<n ; j++)
{
cout<<rot_mat[i][j]<<" ";
}
cout<<endl;
}
}

