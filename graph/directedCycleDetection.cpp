#include<iostream>
#include<list>
#include<vector>
using namespace std;

class Graph  {
list<int> * l ;
int v;
bool helper(int i , vector<bool>&visited , vector<bool>&recursiveTrack) {
visited[i]=true;
recursiveTrack[i]=true;
for(auto &it : l[i]) {
if(!visited[it]) {
return helper( it , visited , recursiveTrack);
}  //// visited
else {
if(recursiveTrack[it]) {
return true;
}
} //// notVisited
} //// loop in neighbours
recursiveTrack[i]=false;
return false;
}
public:
Graph( int v ) : v(v) {
l = new list<int>[v];
}
~Graph() {
delete[] l;
}

void addEdge(int a , int b) { // storing neighbours index 
l[a].push_back(b);
}
void print(void) {
for(int i=0 ;i<v ; i++ ) {
for(auto it : l[i]) {
cout<<it<<" ";
}
cout<<endl;
}
}
bool directedCycleDetection(void) {
vector<bool>visited(v , false);
vector<bool>recursiveTrack(v , false);
for(int i =0 ; i<v  ;i++ ) {
if(!visited[i]) {
if(helper(i , visited , recursiveTrack) ) {
return true;
}
} /// check visited or not
}  /// looping over all elements
return false;
}
}; /// class -end

int main () {
Graph g(6);
g.addEdge(0,1);
g.addEdge(1,2);
g.addEdge(2,3);
g.addEdge(3,1);
g.addEdge(4,5);
g.addEdge(4,0);
cout<<g.directedCycleDetection();
return 0;
}
