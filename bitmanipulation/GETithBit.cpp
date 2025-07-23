#include<iostream>
using namespace std;

 bool returnIthBit(int a){
  int i;
  cin>>i;
  int b = (1 << i-1);

  return (a & b);

 }
int main() {
  int a;
  cin>>a;

  ////////// right shift; upto i ;

  cout<< returnIthBit(a);
  return 0;
}