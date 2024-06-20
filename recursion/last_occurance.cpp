#include<iostream>
#include<vector>
using namespace std;
int last_occur(vector<int> &v , int i , int key)
{
if(i==v.size())
{
return -1;
}
int idx=last_occur(v,i+1 , key);
if(idx==-1 && key==v[i])
{
return i;
}
return idx;
}
int main ()
{
vector<int>v;
int size=5;
for(int i=0 ;i<5;i++)
{
int temp;
cin>>temp;
v.push_back(temp);
}
cout<<"enter key"<<endl;
int key;
cin>>key;
cout<<last_occur(v,0,key);
return 0;
}

