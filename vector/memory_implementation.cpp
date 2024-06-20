#include<iostream>
#include<vector>
using namespace std;
int main ()
{
vector<int>v={1,2,3,4,5};  // v is an object of class vector stored in stack.
cout<<v.size()<<endl;
cout<<v.capacity()<<endl;
cout<<&v[0]<<endl;
cout<<&v<<endl;
v.push_back(6);
cout<<v.size()<<endl;
cout<<v.capacity()<<endl;
cout<<&v[0]<<endl;
cout<<v.data();  //v.data()+i is same as v[i]
return 0;
}
