#include<iostream>
#include<vector>
using namespace std;

bool wildcard_matching(string str1 , string str2) {
vector<vector<bool>>dp(str1.size()+1 , vector<bool>(str2.size() +1 , 0));
dp[0][0]=1;
for(int i = 1 ; i<dp.size() ; i++) {
if(str1[i-1]!='*') {
break;
}
dp[i][0] = 1;

}

for(int i=1 ; i<dp.size() ; i++) {
  for(int j=1 ; j<dp[0].size() ; j++) {
  
   if(str1[i-1]=='*' && (dp[i-1][j] || dp[i][j-1] || dp[i-1][j-1] )) {
      dp[i][j] = true;
   } ///////////  * 
   
   if( str1[i-1]=='?' && dp[i-1][j-1] ) {
   dp[i][j] = true;
   } //////////////// ?
   

   if( dp[i-1][j-1] && str1[i-1]==str2[j-1] ) {
   dp[i][j] = true;
   } ////////////// character
      
   }}
   
   
   
   

for(auto & it : dp ) {
  for(auto  ik : it) {
    cout<<ik<<"  ";
    }
    cout<<endl;
  }

return dp[str1.size()][str2.size()];
}

int main() {
string str2 = "aa";
string str1 = "*";
cout<<wildcard_matching(str1 , str2);
return 0;
}

