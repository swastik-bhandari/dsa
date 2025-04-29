#include<iostream>
#include<vector>

using namespace std;

int knapsackTabulation(vector<int> &wt , vector<int> &val , int W) {
vector<vector<int>>v(val.size()+1 , vector<int>(W+1 , 0));
for(int i=1 ; i< v.size() ; i++) {
  for(int j=1 ; j< v[0].size() ; j++) {
  
  if( j - wt[i-1] >=0) {
  v[i][j] = max(val[i-1] + v[i-1][j-wt[i-1]] , v[i-1][j] );
}
else {
 v[i][j] =  v[i-1][j];
 }

}}

return v[v.size()-1][v[0].size()-1];
}


int main() {
vector<int> val = {5, 3, 4};  
    vector<int> wt ={3, 2, 4};
    int W = 6;
   cout << knapsackTabulation( wt, val , W);
   
   return 0;
   }
