// in this question , i use pair for storing index of row and maximum number of soldier . you can use custom class too . thats your choice.
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

void countSoldier(vector<pair<int, int>>&v , vector<vector<bool>>&matrix) {
for(int i=0 ; i<matrix.size() ; i++) {
int temp=0;
for( bool it : matrix[i]){
if(!it){
break;
}
temp++;
}
v.push_back(make_pair(i , temp));
}
}

struct customComparator {
bool operator() ( pair<int , int>p1 , pair<int , int>p2) const {
if(p1.second==p2.second) {
return p1.first >p2.first;
}
return p1.second > p2.second;
}
};

void weakestSoldier(vector<vector<bool>>&matrix , int k ) {

vector<pair<int , int>>v;
countSoldier(v, matrix);

priority_queue<pair<int , int> ,vector<pair<int , int>> , customComparator> pq(v.begin() , v.end());

for(int i=0 ; i<k ; i++)
{
cout<< pq.top().first <<endl;
pq.pop();
}
}

int main () {
vector<vector<bool>>matrix;
int rows =4;
int cols =4;
matrix.push_back({1,0,0,0});
matrix.push_back({1,1,1,1});
matrix.push_back({1,0,0,0});
matrix.push_back({1,0,0,0});
int k=2;
weakestSoldier(matrix ,k);
return 0;
}
