#include<iostream>
#include<stack>
using namespace std;
string reverseString(string &str)
{
string ans;
stack<char>ch;
for(int i=0 ;i<str.size() ; i++)
{
ch.push(str[i]);
}
while(!ch.empty())
{
ans+=ch.top();
ch.pop();
}
return ans;
}
int main ()
{
string str ="swastik";
string ans= reverseString(str);
cout<<ans;
return 0;
}
