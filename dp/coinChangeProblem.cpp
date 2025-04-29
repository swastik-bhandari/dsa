#include<iostream>
#include<vector>
using namespace std;

int num_of_combinations(int coins[] , int amount , int n) {
vector<vector<int>>dp(n+1 , vector<int>(amount+1 , 0));
for(int i=0 ; i<n+1 ; i++) {
dp[i][0] = 1;
}


for(int i=1 ; i<dp.size() ; i++) {
  for(int j=1 ; j<dp[0].size() ; j++) {
    
    if(coins[i-1] <= j ) {
    
    dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]];
    }
    else {
    dp[i][j] = dp[i-1][j];
    }
    
}}
for(auto & it : dp) {
for(auto & ik : it) {
cout<<ik<<" ";
}
cout<<endl;
}
return dp[n][amount];
}

int main () {
int coins[] = {1,2,5};
int n = sizeof(coins)/sizeof(coins[0]);
int amount = 5;

cout<< num_of_combinations(coins , amount , n );
return 0;
}
