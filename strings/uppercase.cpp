#include<iostream>
using namespace std;
int main ()
{
char sentence[100];
cin.getline(sentence,100);
int i=0;
while (sentence[i]!='\0')
{
if ( sentence[i]>='a' && sentence[i]<='z')
{
sentence[i]-=32;
}
i++;
}
cout<<sentence ;
return 0;
}
