#include<iostream>
#include<string>
using namespace std;
int main ()
{
string str ; 
getline(cin , str);
for (auto ch : str)
{
cout<<ch<<" ";
}
return 0;
}
