#include<iostream>
using namespace std;
void function (int a, int b)
{
cout<<a*b<<endl;
}
int main ()
{
int a , b ;
cin>>a>>b;
void (*ptr)(int , int);
ptr=&function;
void (*ptr1)(int , int);
ptr1=function;
(*ptr)(a,b);
(*ptr)(3,2);
return 0;
}
