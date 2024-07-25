// it + number , is not valid 
// l.begin()-1 is not valid 
#include<iostream>
#include<list>
using namespace std ;
int main ()
{
list<int>l={1,3,3,4,5};
cout<<l.size()<<endl;
list<int>::iterator it;
it=l.begin();
for( it ; it!=l.end() ; it++) // traverse forward 
{
cout<<*it;
}
it=l.end();
it--;
for( it ; it!=l.begin() ; it--) // traverse backward 
{

cout<<*it;
}
cout<<*(l.begin());
return 0;
}
