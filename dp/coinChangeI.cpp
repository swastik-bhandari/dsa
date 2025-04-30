#include<iostream>
#include<vector>
using namespace std;

int coinChange(int coins[] , int amount , int n ) {
vector<vector<int>>dp(n+1 , vector<int>(amount+1 ,amount+1));
for(int i =0 ; i<dp.size() ; i++) {
dp[i][0] = 0;
}

for(int i=1 ; i<dp.size() ; i++) {
for(int j=1 ; j<dp[0].size() ; j++) {

if( coins[i-1] <= j ) {

dp[i][j] = min(1 + dp[i][j-coins[i-1]] , dp[i-1][j]);

}
else {
dp[i][j] = dp[i-1][j];
}
}}
for(auto &it : dp ) {
for(auto &ik : it) {
cout<<ik<<" ";
}
cout<<endl;
}
if(dp[n][amount]>amount){
return -1;
}
return dp[n][amount];
}


int main() {
int coins[] = {2,3};
int amount = 5;
int n = sizeof(coins) /sizeof(coins[0]);
cout<< coinChange(coins , amount , n);
return 0;
}
