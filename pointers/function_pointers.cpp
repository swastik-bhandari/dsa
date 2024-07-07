#include<iostream>
using namespace std;
int sum(int a , int b)
{
return a+b;
}
void sub(int a , int b)
{
cout<<a-b;
}
int main ()
{
int (*ptr)(int , int)=&sum;
cout<<(*ptr)(4,5);
cout<<endl;
void (*ptr1)(int , int)=&sub;
(*ptr1)(4,2);
return 0;
}
