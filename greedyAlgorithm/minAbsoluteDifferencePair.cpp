#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int main ()
{
vector<int>A={4,1,8,7};
vector<int>B={2,3,6,5};

sort(A.begin() , A.end());
sort(B.begin() , B.end());

int sumOfMinAbsValue = 0;
for(int i=0 ; i<A.size() ; i++)
{
sumOfMinAbsValue+=abs(A[i]-B[i]);
}
cout<<sumOfMinAbsValue;
return 0;
}
