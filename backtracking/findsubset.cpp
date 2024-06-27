#include<iostream>
using namespace std;
void printsubset(string str , string ans )
{
if (str=="")
{
cout<<ans<<" ";
return;
}
printsubset(str.substr(1,str.size()-1) ,ans+str[0]);
printsubset(str.substr(1,str.size()-1) , ans);
}
int main ()
{
string str ;
cin>>str;
printsubset(str , "");
return 0;
}

