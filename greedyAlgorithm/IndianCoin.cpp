#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main ()
{
vector<int>v{1,2,5,10,20,50,100,500,2000};
sort(v.begin() , v.end() , greater<int>());
int count=0;
int amount ;
cin >> amount;

for(int &coin : v) {

int d =amount/coin;

count+=d;

amount-=coin*d;
d=0;
if(amount<=0)
{
break;
}
}
cout<<count;
return 0;
}


