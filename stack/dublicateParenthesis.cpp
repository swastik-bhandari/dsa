#include<iostream>
#include<string>
#include<stack>
#include<cstdlib>
using namespace std;

//////////////////////////////////////////////
bool dublicateParenthesis(string str)
{

stack<char>s;
char ch;

////////////////////////////
for(int i=0 ; i<str.size() ; i++)
{
ch=str[i];

if(ch!=')')
{
s.push(ch);
}
else
{
if(s.empty())
{
cout<<"invalid parenthesis";
exit(1);
}
if(s.top()=='(')
{
return true;
}
else
{
while(s.top()!='(')
{
s.pop();
}
s.pop();
}
}
}
if(s.empty())
{
return false;
}
else
{
cout<<"invalid parenthesis";
exit(1);
}
}
int main ()
{
string str="((x)+(y))";
cout<<dublicateParenthesis(str);
return 0;
}
