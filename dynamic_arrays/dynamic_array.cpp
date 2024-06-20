#include<iostream>
using namespace std;
int *func (void )
{
int size;
cin>>size;
int *ptr=new int [size];
for ( int i=0 ; i< size ; i++)
{
cin>>ptr[i];
}
for (int i=0 ; i<size ; i++)
{
cout<<*(ptr+i);
}
return ptr;
}
int main ()
{
int *ptr=func();
cout<<endl<<ptr<<endl;
delete [] ptr;
ptr=nullptr;
return 0;
}
