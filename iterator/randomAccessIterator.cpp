//vector is a random access interator which support arithmetic operations like addition, subtraction, and comparison.
#include<iostream>
#include<vector>
using namespace std;
int main ()
{
vector<int>v={1,2,3,4};
vector<int>::iterator it;
it=v.end()-1;
cout<<*it;
for(it=v.begin() ; it<v.end() ; it++)
{
cout<<*it;
}
return 0;
}
