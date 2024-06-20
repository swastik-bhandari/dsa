#include<iostream>
using std::cin;
using std::cout;
using std::endl;
bool  search_key(int (*)[4] , int  ,int ,int  );
int main ()
{
  int arr[][4]={{10,20,30,40},{15,25,35,45},{27,29,37,48},{32,33,39,50}};
  int n=sizeof(arr)/sizeof(arr[0]);
  int m=sizeof(arr[0])/sizeof(arr[0][0]);
  int key;
  cout<<"enter the key"<<endl;
  cin>>key;
if( !search_key(arr , n , m , key ))
{
cout<<-1;
}

  return 0;
}
bool search_key(int (*ptr)[4] , int n , int m , int key )
{
  int srow=0 , scol=0;
  int erow=n-1 , ecol=m-1;

  while(srow<=erow && scol<=ecol)
  {
    if (key>ptr[srow][ecol])
    {
      srow++;
    }
    else if (key<ptr[srow][ecol])
    {
      ecol--;
    }
    else{
  cout<<srow<<","<<ecol;
    return true;
      }
  }
  return false;
}
