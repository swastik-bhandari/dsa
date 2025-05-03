#include<iostream>
#include<vector>
using namespace std;

int longest_common_substring(string str1 , string str2) {

vector<vector<int>>dp( str1.size()+1 , vector<int>(str2.size()+1 , 0));
int max_sublength=0;
for(int i=1; i<dp.size() ; i++) {
  for(int j=1; j<dp[0].size() ; j++) {
    
    if(str1[i-1]==str2[j-1]) {
      dp[i][j] = dp[i-1][j-1] +1;
      }
    max_sublength = max(max_sublength , dp[i][j]);
    }}
return max_sublength;
}


int main () {
string str1 = "abgce";
string str2 = "abcde";

cout<<longest_common_substring(str1 , str2);

return 0;
}
