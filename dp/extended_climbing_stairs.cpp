/////////////// can take either 1 step or 2 step or 3 step . if n stairs are given , how may ways that he can climb the stairs 
// hint : forms a tribonacci 
#include<iostream>
using namespace std;

//////////// using tabulation /////////////////////////
int tabulation_ways_to_climb(int n ) {
int table[n+1];
table[0]=1;
table[1]=1;
table[2]=2;

for(int i=3 ; i<=n ; i++) {
table[i]=table[i-1]+table[i-2]+table[i-3];
}
return table[n];
}

//////////////////// using memoization (top-down) /////////////

int helper(int n , int memory[] ) {

if(n ==1 || n==0 ) {
return 1;
}
if(n==2) {
return 2;
}
if(memory[n]==0) {
 memory[n]= helper(n-1 , memory) + helper(n-2 , memory)+ helper(n-3 , memory);
}
return memory[n];
}

int memoization_ways_to_climb(int n) {
int memory[n+1]={0};
memory[0]=1;
memory[1]=1;
memory[2]=2;
return helper(n , memory);
}


int main() {
int n ;
cin>>n;

cout<<"answer from tabulation:"<<tabulation_ways_to_climb(n)<<endl;
cout<<"answer from memoization:"<<memoization_ways_to_climb(n);

return 0;
}
