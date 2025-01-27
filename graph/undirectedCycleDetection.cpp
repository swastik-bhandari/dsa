#include<iostream>
#include<list>
#include<vector>
using namespace std;

class Graph  {
list<int> * l ;
int v;
bool undirected;
bool helper(int i , int parent , vector<bool>& visited);
public:
Graph( int v  , bool undirected ) : v(v) , undirected(undirected) {
l = new list<int>[v];
}
void addEdge(int a , int b) { // storing neighbours index 
l[a].push_back(b);
if(undirected) {
l[b].push_back(a);
}
}
void print(void) {
for(int i=0 ;i<v ; i++ ) {
for(auto neighbour : l[i]) {
cout<<neighbour<<" ";
}
cout<<endl;
}
}
bool undirectedCycleDetection(void) {
vector<bool>visited(v , 0);
for(int i=0 ; i<v ; i++ ) {
if(!visited[i]) {
if(helper( i , -1 , visited)){
return true;
}  // handle the response
}
}
return false;
}
};
bool Graph :: helper(int i , int parent , vector<bool>& visited) {
visited[i]=true;
for(auto &neighbour : l[i]) {
if(!visited[neighbour]) {
if(helper(neighbour , i , visited)) {
return true;
}
} /// visiting 
else {
if(neighbour != parent ) {
return true;
}  /// checking backEdge

} // already visited
}// loop over neighbours 
return false;
} // helper function end
int main () {
Graph g(6 , true);
g.addEdge(0,1);
g.addEdge(1,2);
g.addEdge(2,3);
g.addEdge(2,4);
g.addEdge(4,5);
g.addEdge(5,2);
cout<<g.undirectedCycleDetection();
return 0;
}
