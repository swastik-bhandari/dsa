#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int knapsack(vector<int>wt , vector<int>val , int idx ,int w , int W) {

if(w>W) {
return INT_MIN;
}
if(idx>=wt.size() || w == W) {
return 0;
}
int ans1 = knapsack(wt , val , idx+1, w , W);
int ans2 = val[idx]+ knapsack(wt , val , idx+1 , w+wt[idx] , W);

return (max(ans1 , ans2));
}


int main() {
vector<int> wt = {10,2,8,3};
vector<int> val ={150,20,10,20};
int W = 8;
int idx=0; 
int ans;
ans = knapsack(wt , val ,idx ,0 , W);
cout<<ans;
return 0;
}
