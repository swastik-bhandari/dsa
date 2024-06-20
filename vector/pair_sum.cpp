#include<iostream>
#include<vector>
using namespace std;
vector<int> pair_sum (vector<int> & , int );
int main ()
{
  vector<int> v={2,7,11,15};
  int key ;
  cin>>key;
  vector<int> ans =pair_sum(v,key);
  for(auto it : ans)
  {
    cout<<it;
  }
  return 0;
}
vector<int> pair_sum( vector<int> &v , int key)
{
  
        vector<int>ans;
  int s=0 ; 
  int e=v.size()-1;
  while(s<e)
  {
    if(v[s]+v[e]>key)
    {
      e--;
    }
    else if (v[s]+v[e]<key)
    {
      s++;
    }
    else
    {
      ans.push_back(s);
      ans.push_back(e);
      return ans;
    }
  }
  ans.push_back(-1);
  return ans;
}
