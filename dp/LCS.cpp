#include<iostream>
#include<vector>
using namespace std;



int lenght_of_LCS(string str1, string str2) {
vector<vector<int>>dp(str1.size()+1 , vector<int>(str2.size()+1 , 0));

for(int i=1 ; i<dp.size() ; i++) {
  for(int j=1 ; j<dp[0].size() ; j++) {
    
    if(str1[i-1]==str2[j-1]) {
      dp[i][j] = dp[i-1][j-1]+1;
      }
    else {
      dp[i][j] = max( dp[i-1][j] , dp[i][j-1]);
      }
    }}
   for(auto & it : dp) {
   for(auto & ik :it) {
   cout<<ik<<" ";
   }
   cout<<endl;
   }
   return dp[str1.size()][str2.size()];
 } 
    

int main() {

string str1 = "abc";
string str2 = "def";

cout<<lenght_of_LCS(str1 , str2);
return 0;
}
