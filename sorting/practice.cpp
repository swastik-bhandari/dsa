#include<iostream>
#include<algorithm>
using namespace std;
int main ()
{
  char ch[]={'e','a','d','c','f','b'};
  int n=sizeof(ch)/sizeof(ch[0]);
  for(int i=1 ; i<n ; i++)
  {int j=i;
    while(ch[j-1]>ch[j] &&  j>0)
    {
      swap(ch[j] , ch[j-1]);
    j--;
    }
  }
  for(int i=0 ; i<n ;i++)
    cout<<ch[i];
  return 0;
}
