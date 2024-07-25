#include<iostream>
#include<cstdlib>
using std::cin;
using std::cout;
using std::endl;
void add(int a, int b)
{
cout<<a+b;
}
void sub(int a, int b)
{
cout<<a-b;
}
void mul(int a, int b)
{
cout<<a*b;
}
void divide(int a, int b)
{
cout<<a/b;
}
int main ()
{
int num , a , b;
system("clear");
cout<<" 1:Add \n 2:Sub \n 3:Multiplication \n 4:division"<<endl;
cin>>num;
if(num>0 && num<5){
cout<<"enter two number \n";
cin>>a>>b;
void (*ptr[4])(int , int)={add , sub , mul , divide};
(*ptr[num-1])(a , b);
}
else
{
system("clear");
cout<<"error"<<endl;
}
return 0;
}
