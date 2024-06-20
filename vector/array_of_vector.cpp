#include<iostream>
#include<vector>
using namespace std;
int main ()
{
vector<int>v[3];
v[0].push_back(3);

v[0].push_back(9);

v[1].push_back(1);

v[2].push_back(8);

v[2].push_back(7);

v[2].push_back(5);
for(int i=0 ; i <3 ; i++)
{
  for (int j=0 ; j<v[i].size() ; j++)
  {
    cout<<v[i][j];
  }
  cout<<endl;
}
return 0;
}
