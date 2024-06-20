#include<iostream>
#include<cstring>
#include<utility>
using namespace std;
int main ()
{
char word[]="code";
int s=0;
int e=strlen(word)-1;
while(s<e)
{
swap(word[s],word[e]);
s++;
e--;
}
cout<<word;
return 0;
}
