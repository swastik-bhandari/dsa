#include<iostream>
#include<queue>
#include<vector>
using namespace std;

char nonRepeatingLetter (string &str)
{
vector<int>v(26, 0);
queue<char>q;
char ch;
for(int i=0 ; i<str.size() ; i++)
{
ch=str[i];

v[ch-'a']++;

q.push(ch);
}
while(!q.empty())
{
if(v[q.front()-'a']==1)
{
return q.front();
}
q.pop();
}
throw runtime_error("no non repeating element found");
}
//driver code
int main ()
{
string str="aabccb";
try{
cout<<nonRepeatingLetter(str);
}
catch(const runtime_error & e)
{
cout<<e.what();
}
catch(...)
{
cout<<"error occured";
}
return 0;
}
