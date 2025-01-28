#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Graph {
vector<vector<int>>prerequicites;
int size;
bool helper( int src , vector<bool>&visited , vector<bool>&rec , stack<int>&s) {
visited[src]=true;
rec[src]=true;
for(int i=0 ; i<prerequicites.size() ; i++ ) {
int u = prerequicites[i][1];
int v = prerequicites[i][0];

if(src == u) {
if(!visited[v]) {
bool returnValue = helper(v , visited , rec ,s);
if(!returnValue) {
return false;
}
} ///////// not visited block
else {
if(rec[v]){
return false;
} // block that checks for loops
} // already visited block 

} // block that find pairs 

} // loop in the vector that stores edge in the form of vector
s.push(src);
rec[src]=false;
return true;
} // helper function -end

public:
Graph(int size) :size(size) {  }
~Graph() { }
///////////////// adding edges ////////////////
void addEdge(int a , int b) {
prerequicites.push_back(vector<int>{a,b});
}
////////// printing the graph in the form of edgelist /////////////////
void print(void) {
for(int i =0  ; i<prerequicites.size() ; i++) {
for(auto &it : prerequicites[i]) {
cout<<it<<" ";
}
cout<<endl;
}
}

/////////// scheduleI function ////////////////
int * scheduleI(void) {
vector<bool>visited(size , false);
vector<bool>rec(size ,false);
stack<int>s ;
int * arr=new int[size];
for(int i=0 ; i<size ; i++){
if(!visited[i]) {
bool returnValue = helper( i , visited , rec , s); ////// uncompleted
if(!returnValue) {
return arr;
}
}
}
int stackSize = s.size();
for(int i=0 ; i<stackSize ; i++) {
arr[i]=s.top();
s.pop();
}
return arr;
}
};

/////////// main //////////////
int main() {
int size =4;
Graph g(size);
g.addEdge(1,0);
g.addEdge(2,1);
g.addEdge(3,2);
int * array = g.scheduleI();
for(int i=0 ; i<size ; i++ ) {
cout<<array[i];
}
return 0;
}
