#include<iostream>
#include<vector>
using namespace std;


void heapify(vector<int>&v ,int n ,  int p) {
int c1=p*2+1;
int c2=p*2+2;
int maxIdx=p;
if(c1 < n && v[c1]>v[maxIdx]) {
maxIdx=c1;
}
if(c2 < n && v[c2]>v[maxIdx]) {
maxIdx=c2;
}
if(p!=maxIdx) {
swap(v[p] , v[maxIdx]);
heapify(v , n , maxIdx);
}
}
void heapSort( vector<int>&v) {
int n =v.size();
for(int i=n/2-1 ; i>=0 ; i-- ){
heapify( v, n ,i);
}
for(int i=n-1 ; i>=0 ; i--) {
swap(v[0] , v[i]);
heapify(v , i , 0);
}
}

int main() {
vector<int>v={1,4,2,5,3};
heapSort(v);
for(int it : v ) {
cout<<it<<" ";
}
return 0;
}
