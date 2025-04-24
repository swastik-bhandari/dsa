/////////// here i start my journey to dynamic programming ! //////////////// 

/////// 0 1 2 3 4 5 -> 0 1 1 2 3 5 8  , x->fibo(x)
#include<iostream>

using std::cout;
using std::endl;
using std::cin;

int helper(int x , int memory[] ) {
if(x==0) {
return 0;
}
if(x==1) {
return 1;
}

if(memory[x]==0) {
 int ans = helper(x-1 , memory) + helper(x-2 , memory);
 memory[x]=ans;
}
return memory[x];
}
//////////////////////////////
int fibo(int n){
int memory[n+1]={0};
memory[1]=1; //// no need , but make sense 

return helper(n , memory);
}


int main() {
int n ;
cin>>n;
cout<< fibo(n);
return 0;
}

