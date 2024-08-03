#include<iostream>
#include<stack>
#include<vector>
using namespace std;

/////////////////////////////////
bool validParenthesis(string str )
{
stack<char>s;
char ch;
for(int i=0 ; i<str.size() ; i++)
{
ch=str[i];
if(ch=='(' || ch=='{' || ch=='[' )
{
s.push(ch);
}
else {

if(!s.empty())
{
if(s.top()=='(' && ch==')' || s.top()=='{' && ch=='}' || s.top()=='[' && ch==']' )
{
s.pop();
}
else{
return false;
}
}
else {
return false;
}
}
}
if(s.empty())
{
return true;
}
else {
return false;
}
}
int main ()
{
string str="{()}[]";
cout<<validParenthesis(str);
return 0;
}
