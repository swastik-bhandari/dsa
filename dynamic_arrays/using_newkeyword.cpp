#include<iostream>
using namespace std;
int * func(void)
{
int *ptr=new int ;
cout<<ptr<<endl;
*ptr=5;
return ptr;
}
int main ()
{
int *ptr=func ();
cout<<ptr<<endl;
cout<<*ptr<<endl;
delete ptr;
cout<<*ptr;
ptr=nullptr;
return 0;
}
