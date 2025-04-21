/*. Heapify(or heapify down) in Pop (Removal) Operation
When removing the root element (which is the min/max element in a heap):

The last element is moved to the root.
Heapify (downward percolation) is applied to restore the heap property.
👉 Time Complexity: 
𝑂
(
log
⁡
𝑛
)
O(logn)
👉 Used in: pop() operation (removing the top element)

2. Heapify in Heap Construction
If an array is given, heapify is applied bottom-up to convert it into a valid heap.
This is used in Heap Sort and in std::make_heap().
👉 Time Complexity: 
𝑂
(
𝑛
)
O(n)
👉 Used in: Building a heap from an array

*/
/////////////// *******************************/////////////////////////////////////////////////
/* for push operation , we have to move upwards , so we use heapify-up for upward percolation */
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Heap {
private:
vector<int> v;
public:

void push( int x ) { ///////// you can also create a new function heapify-up and using recursion , you can shift up the key to it's correct position .
v.push_back(x);
int n=v.size()-1;
while(n>0) {
int i=(n-1)/2;

if(v[i]>v[n]) {
break;
}
swap(v[i] , v[n]);
n=i;
}
}

int top(void) {
if(v.empty()) {
return -1;
}
return v[0];
}

bool empty(void) {
return(v.empty());
}

void heapify(int p) {

int maxIdx=p;
int c1=p*2+1;
int c2=p*2+2;
if(c1<v.size() && v[maxIdx] < v[c1]) {
maxIdx=c1;
}
if(c2<v.size() && v[maxIdx] < v[c2] ) {
maxIdx=c2;
}
if(p!=maxIdx) {
swap(v[maxIdx] , v[p]);
heapify(maxIdx);
}
}

void pop(void) {
swap(v[0] , v[v.size()-1]);
v.pop_back();
heapify(0);
}

/////////////// decrease key operation /////////////////  new key should be less than the current key in the index . else return false . use heapify-down(heapify) in max heap and heapfy-up in min heap . 
bool decreaseKey(int key , int idx) {
if(key > pq[idx]) {
return false;
}
pq[idx]=key;
heapify(idx);
return true;
}
};

int main () {
Heap hp ; 
hp.push(50);
hp.push(100);
hp.push(30);
cout<<hp.top()<<endl;
cout<<hp.empty()<<endl;
hp.pop();
cout<<hp.top()<<endl;
return 0;
}


