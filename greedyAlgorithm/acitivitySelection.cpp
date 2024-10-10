#include<iostream>
using namespace std;
int maxActivity(pair<int, int > *p)
{
int count=1;
int i=0,j=1;
while(j<6)
{
if(p[i].second <= p[j].first) {
i=j;
j++;
count++;
}
else
{
j++;
}
}
return count ;
}
int main ()
{
pair<int , int >p[6];
for(int i=0 ; i<6 ; i++)
{
int x , y;
cin>>x>>y;
p[i]={x , y};
}
cout<<maxActivity(p);
return 0;
}
