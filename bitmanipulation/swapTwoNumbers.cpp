#include<iostream>
using namespace std;

int main() {
  int a;
  int b; 
  cin>>a>>b;
   
  int c = (a^b);
   a = (a^c);
   b = (b^c);

   cout<<a;
   cout<<b;



  return 0;
}