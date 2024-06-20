#include<iostream>
using namespace std;
void print_num ( int );
int main ()
{
int x ;
cin>>x;
print_num(x);	
return 0;
}
void print_num(int x)
{
if(x>0)
{
cout<<x;
print_num(x-1);
}
}


