#include<iostream>
#include<vector>
using namespace std;

bool is_target_sum(int num[] , int target_sum , int n) {
vector<vector<int>>v( n+1 , vector<int>(target_sum+1 , 0));
for(int i=1 ; i <v.size()  ; i++) {
for(int j=1 ; j< v[0].size() ; j++ ) {

  if( num[i-1] > j ) {
  v[i][j] = v[i-1][j];
  }
  else {
  v[i][j] = max(num[i-1] + v[i-1][j-num[i-1]] , v[i-1][j] );
  }
  if(v[i][j] == target_sum) {
  return true;
  }
  }}
  return false;
 }

int main () {

int num[] = {6, 1, 2 ,1};
int target_sum = 4;
int n = sizeof(num) / sizeof(num[0]);
cout<< is_target_sum(num , target_sum  , n);
return 0;
}


