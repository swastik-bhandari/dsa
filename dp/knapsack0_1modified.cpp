#include<iostream>
#include<vector>

using namespace std;

int knapsack(vector<int>&wt , vector<int>&val , int n , int W) {

if(n==0 || W==0) {
return 0;
}
int ans1=0;
int ans2=0;
if(wt[n-1] <=W) { // add that element in the knapsack
 ans1 = knapsack(wt , val , n-1 , W);
 ans2 = val[n-1] + knapsack(wt , val , n-1 , W-wt[n-1]);
}
else { // do not add that element in the knapsack
ans1 = knapsack(wt , val , n-1 , W);
}
 return max(ans1 , ans2);
}

int main () {
vector<int> wt = {1, 8, 3};
vector<int> val = {1, 10, 15};
int W = 3;
int n = wt.size();
int w=0;
cout<< knapsack(wt , val , n , W);
return 0;
}
