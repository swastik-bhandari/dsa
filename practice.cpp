#include<iostream>
#include<vector>
using namespace std;


void heapify(int idx ,int size , int *pq ) {

int parent = idx;
int child1 = parent*2+1;
int child2 = parent*2+2;
int max_idx=parent;
if(child1<size && pq[max_idx]<pq[child1]) {
max_idx = child1;
}
if(child2<size && pq[max_idx]<pq[child2]) {
max_idx = child2;
}
if(max_idx !=parent) {
swap(pq[parent] , pq[max_idx]);
heapify(max_idx ,size , pq);
}
}

void heapSort(int *arr ,int size) {
int n = size -1;
for(int i= (n+1)/2 -1 ; i>=0 ; i-- ) {
heapify(i , size , arr);
}

for(int i=n ; i>0 ; i--) {
swap(arr[0] , arr[i]);
heapify(0,i,arr);
}
}

int main() {
int arr[5]={4,3,6,1,2};
heapSort(arr , 5);
for(int i=0 ; i<5 ; i++) {
cout<<arr[i];
}
return 0;
}
