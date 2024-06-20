#include<iostream>
using std::cin ;
using std::cout;
using std::endl;
const int size_matrix=4;
void diag_sum(int [][size_matrix] , int);
int main ()
{
int a[][size_matrix]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
//calculating order of matrix 
int n=sizeof(a)/sizeof(a[0]);
cout<<n<<endl;
diag_sum(a , n);
return 0;
}
//function to calculate the sum of primary and secondary diagonal element 
void diag_sum(int a[][size_matrix] , int n )
{
int sum=0;
for (int i=0 ; i< n ; i++)
{
if ( i!=(n-i-1) )
{
sum+=a[i][i] + a[i][n-1-i];
}
else
{
sum+=a[i][i];
}
}
cout<<sum;
}
