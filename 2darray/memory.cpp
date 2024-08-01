#include<iostream>
#include<algorithm>
using namespace std;
#define size 2
int main ()
{
int nums[size][size];
for(int i=0 ; i <size ;i++)
{
for(int j=0 ; j<size ; j++)
{
cin>>nums[i][j];
}
}
for(int i=0 ; i <size ;i++)
{
for(int j=0 ; j<size ; j++)
{
cout<<&nums[i][j]<<" ";
}
}
cout<<"\n";
int a=0;
for(int i=0 ; i <size ;i++)
{
for(int j=0 ; j<size ; j++)
{
cout<<nums+a++<<" ";
}
}
cout<<endl;
for(int i=0 ; i <size ;i++)
{
for(int j=0 ; j<size ; j++)
{
cout<<*(nums[i]+j)<<" ";
}
}
cout<<&nums+1<<" ";
return 0;
}


