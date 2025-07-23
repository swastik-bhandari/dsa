#include<iostream>
using namespace std;

int main() {
  int a;
  cin>> a;
  if(!(a & 1)) {
    cout<<"even";

  }
  else {
    cout<<"odd";
  }
  return 0;
  
}