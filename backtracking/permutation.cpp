#include<iostream>
using namespace std;
void permutation (string str , string ans )
{
if (str.size()==0)
{
cout<<ans<<endl;
return;
}
for(int i=0 ; i<str.size() ; i++)
{
char ch=str[i];
string temp=str;
temp.erase(i,1);
permutation(temp,ans+ch);
}
}
int main ()
{
string str;
cin>>str;
permutation(str , "");
return 0;
}
