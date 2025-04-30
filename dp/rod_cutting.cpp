#include<iostream>
#include<vector>
using namespace std;

int max_price(int price[] , int l ) {
vector<vector<int>>dp(l+1 , vector<int>(l+1 , 0));

for(int i=1 ; i<dp.size() ; i++) {
 for(int j=1 ; j<dp[0].size() ; j++) {
  
  if(i <= j ) {
  dp[i][j] = max(price[i-1] + dp[i][j-i] , dp[i-1][j]);
  }
  else {
  dp[i][j] = dp[i-1][j];
  }
  }}
  return dp[l][l];

}

int main() {
int price[] = {1,5,8,9,10,17,17,20};
int l = sizeof(price) / sizeof(price[0]);

cout<< max_price(price , l);
return 0;
}


