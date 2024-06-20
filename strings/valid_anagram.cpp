#include<iostream>
#include<string>
using namespace std;
bool is_anagram(string & , string &);
int main ()
{
string str1="race";
string str2="care";
if ( str1.length()==str2.length())
{
if (is_anagram(str1 , str2))
cout<<"anagram";
else
cout<<"notanagram";
}
else
{
cout<<"not anagram";
}
return 0;
}
bool is_anagram(string &str1 , string &str2)
{
int  count[26]={0};
for (int i=0 ; i<str1.length() ; i++)
{
count[str1[i]-'a']++;
}
for (int i=0 ; i<str2.length() ; i++)
{
if(count[str2[i]-'a']==0)
{
return false;
}
}
return true;
}
