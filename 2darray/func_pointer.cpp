#include<iostream>
using std :: cin ;
using std :: cout;
using std :: endl;
void array(int (*)[3] , int );
int main ()
{
int arr[][3]={{1,2,3},{4,5,6}};
int n =sizeof(arr)/sizeof(arr[0]);
array(arr , n );// arr is a row pointer , clearly , row pointer is passed to the function .
cout<<arr+2<<endl;
cout<<&arr[1]+1<<endl;
cout<<arr[1]+1<<endl;
return 0;
}
void array (int (*ptr)[3] , int n )
{
for(int i=0 ; i<n ; i++)
{
 for(int j=0 ; j < 3 ; j ++)
 {
 cout<<*(*(ptr+i)+j)<<" ";
 }
}
}

 
