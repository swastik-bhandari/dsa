#include<iostream>
using namespace std;

int main() {
  /////// and operator & //////////
  cout<< (3 & 5);   // 011 & 101 = 001  (1)

  ////// OR operator | ////////////
  cout<< (3 | 5); /// 011 | 101 = 111   (7)

  /////// XOR operator ^ ////////////
  cout<< (3 ^ 5);//// 011 ^ 101 = 110   (6)
   bool x = ~0;
  cout<< (~0); // -1

  ////////////// ~ => one's complement . for 4 bit system , it  is stored as 1101 . first bit is sign 1= neg , 101 (5) is magnitude. 1101 is stored in system . But while printing output . While printing that negative number , The internal system using 2's complement . 

  /// for 1's complement . We put the symbol according to MSB (+ if 0 , - if 1) . we take 1's complement of the number (~101(5) => 010(2)) . 

  /// for 2's complement . We put the symbol according to MSB (+ if 0 , - if 1) . we take 2's complement of the number . 1's complement of (5) + 1 => 010+1 => 011 (3) . 

  cout<< (7 << 2);   // ( a << b) => a * (2^b)  ( left shift)

  cout<< (7 >> 2); // (a >> b)  => a / (2^b)   ( right shift)
  

  return 0;
}