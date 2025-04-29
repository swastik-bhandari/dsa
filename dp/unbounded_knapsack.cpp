#include<iostream>
#include<vector>
using namespace std;

int unbounded_knapsack(int num[] , int wt[] , int W , int n ) {
vector<vector<int>>v(n+1 , vector<int>(W+1 , 0));

for(int i=1 ; i<v.size() ; i++) {
for(int j=1 ; j<v[0].size() ; j++) {

if(wt[i-1] <= j) {
v[i][j] = max(num[i-1] + v[i][j - wt[i-1]] , v[i-1][j]);
}
else {
v[i][j] = v[i-1][j];
}
}}
return v[n][W];
}

int main () {

int num[] = {15,14,10,45,30};
int wt[] = {2,5,1,3,4};
int n = sizeof(num) / sizeof(num[0]);
int W = 7;

cout<< unbounded_knapsack(num , wt , W , n );

return 0;
}
