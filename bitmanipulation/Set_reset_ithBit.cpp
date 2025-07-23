#include<iostream>
using namespace std;

void updateBit(int & key , int position , bool is_set) {
  int a = (1 << (position-1));
  key = (key & (~a));

  if(is_set) {
    key = key | a;
  }

}

void setBit(int& key, int position){
  int a = (1 << (position-1));

  key = (key | a);
}

void resetBit(int & key , int position){
  int a = (1 << (position-1));

  key = (key & (~a));
}

/// you can use these setBit and reset Bit to update a bit . //////////// You can use different apprach as well .

void updateBit_using_function(int & key , int position , bool is_set) {

  if(is_set) {
    setBit(key , position);
   } else { 
    resetBit(key , position);
   }
}

int main() {
  int key, position;
  bool set_bit;
  // cout<<"enter:";
  // cin>>key>>position;

  // setBit(key , position);

  // cout<<key;
  // cin>> position;
  // resetBit(key , position);

  // cout<<key;

  cin>>key>>position>>set_bit;
  updateBit(key , position , set_bit);

  cout<<key;

  return 0;
}