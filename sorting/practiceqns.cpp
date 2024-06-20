#include<iostream>
using namespace std;
#include<algorithm>
int main ()
{
  char ch[]={'f','b','a','e','c','d'};
  int n=sizeof(ch)/sizeof(ch[0]);
  sort(ch , ch+n);
for(int i=0 ; i<n ; i++)
{
  cout<<ch[i];
}
return 0;
}
