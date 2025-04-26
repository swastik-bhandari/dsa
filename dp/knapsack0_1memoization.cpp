//"If a function is called with the same set of arguments that determine its output, the result can be stored (memoized) and reused to avoid redundant computations."
#include<iostream>
#include<vector>

using namespace std;

int knapsack(vector<int>&wt , vector<int>&val , int n , int W , vector<vector<int>>&memory) {

if(n==0 || W==0) {
return 0;
}
int ans1=0;
int ans2=0;
if(memory[n][W] !=-1) {
return memory[n][W];
}
if(wt[n-1] <=W) { // add that element in the knapsack
 ans1 = knapsack(wt , val , n-1 , W , memory);
 ans2 = val[n-1] + knapsack(wt , val , n-1 , W-wt[n-1] , memory);
}
else { // do not add that element in the knapsack
ans1 = knapsack(wt , val , n-1 , W , memory);
}

 int max_val = max(ans1 , ans2);
 memory[n][W]= max_val;
 return max_val;
}

int main () {
vector<int> wt = {1, 8, 3};
vector<int> val = {1, 10, 15};
int n = wt.size();
int W = 3;
int w=0;
vector<vector<int>>v(n+1 , vector<int>(W+1,-1));
cout<< knapsack(wt , val , n , W ,v);
return 0;
}
