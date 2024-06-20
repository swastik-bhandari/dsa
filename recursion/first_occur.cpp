#include<iostream>
#include<vector>
using namespace std;
int first_occur(vector<int> &v , int i , int key)
{
if (i==v.size())
{
return -1;
}
if(v[i]==key)
{
return i;
}
return (first_occur(v,++i,key));
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
cout<<first_occur(v,0,key);
return 0;
}

