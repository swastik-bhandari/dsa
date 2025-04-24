#include<iostream>
#include<vector>
using namespace std;

void floodFill ( vector<vector<int>>&v , int r , int cl , int init_val , int final_val) {

if(init_val==final_val) {
return;
}

if(r<0 || cl <0 || r>=v.size() || cl>=v[0].size() || init_val != v[r][cl]) {
return;
}
v[r][cl]=final_val;
floodFill(v,r, cl+1 , init_val , final_val);
floodFill(v,r+1, cl , init_val , final_val);
floodFill(v,r, cl-1 , init_val , final_val);
floodFill(v,r-1 , cl , init_val , final_val);
}



int main() {
vector<vector<int>> v = {
    {1, 1, 0, 0, 0},
    {1, 1, 0, 1, 1},
    {0, 0, 0, 1, 1},
    {0, 1, 1, 0, 0},
    {0, 1, 0, 0, 0}
};
int r ;
int cl;
cout<<"enter row and column:"<<endl;
cin>>r>>cl;
int init_val = v[r][cl];
int final_val;
cout<<"enter the value:"<<endl;
cin>>final_val;
floodFill(v,r, cl , init_val , final_val); // matrix ,row,column,initial value , final value .

for(auto & row : v) {
for(auto & element : row) {
cout<< element << " " ;
}
cout<<endl;
}
return 0;
}

