#include<iostream>
#include<vector>
using namespace std;


    int minDistance(string str1, string str2) {
     vector<vector<int>>dp(str1.size()+1 , vector<int>(str2.size()+1 , 0));

for(int i =1  ;i<dp.size() ; i++) {
dp[i][0] = i;   // deletion operations
}

for(int j=1 ; j<dp[0].size() ; j++) {
dp[0][j] = j;
}

for(int i=1 ; i<dp.size() ; i++) {
  for(int j=1 ; j<dp[0].size() ; j++) {
    int temp;
    if(str1[i-1]==str2[j-1]){
    temp = dp[i-1][j-1];
    }
    else{
    temp = dp[i-1][j-1]+1 ;
    }
    dp[i][j] = min(dp[i-1][j]+1, min(temp , dp[i][j-1]+1));
    }}
    
    return dp[str1.size()][str2.size()];
    

}

int main() {
string str1 = "horse";
string str2 = "ros";
cout<<minDistance(str1 , str2);
return 0;
}
