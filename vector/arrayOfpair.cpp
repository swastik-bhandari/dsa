#include<iostream>
#include<utility>
using namespace std;
int main()
{
pair<int , int >p[5];
for(int i=0 ; i<5 ; i++)
{
p[i]={i,i+1};
}
for(int i=0 ; i<5 ; i++)
{
cout<<p[i].first<<p[i].second<<endl;
}
return 0;
}

