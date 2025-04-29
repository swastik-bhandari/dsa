//"If a function is called with the same set of arguments that determine its output, the result can be stored (memoized) and reused to avoid redundant computations."
#include<iostream>
#include<vector>

using namespace std;

int knapsack(vector<int>& wt, vector<int>& val, int n, int W, vector<vector<int>>& memory) {
    if(n == 0 || W == 0) {
        return 0;
    }
    if(memory[n][W] != -1) {
        return memory[n][W];
    }

    int ans1 = knapsack(wt, val, n-1, W, memory);
    int ans2 = 0;
    if(wt[n-1] <= W) {
        ans2 = val[n-1] + knapsack(wt, val, n-1, W-wt[n-1], memory);
    }

    memory[n][W] = max(ans1, ans2);
    return memory[n][W];
}


int main () {
vector<int> val = {15,14,10,45,30};
vector<int> wt = {2,5,1,3,4};
int n = wt.size();
int W = 7;
int w=0;
vector<vector<int>>v(n+1 , vector<int>(W+1,-1));
cout<< knapsack(wt , val , n , W ,v);
cout<<endl;
for(auto & it : v) {
for(auto & k : it) {
cout<<k<<" ";
}
cout<<endl;
}

return 0;
}
