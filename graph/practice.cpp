#include<iostream>
#include<list>
#include<vector>
using namespace std;

class Graph  {
list<int> * l ;
int v;
void helper(int i , vector<bool>&visited) {
cout<<i;
for(auto &it :l[i]) {
if(!visited[it]) {
visited[it]=true;
helper(it  , visited);
}
}
}
public:
Graph( int v ) : v(v) {
l = new list<int>[v];
}
void addEdge(int a , int b) { // storing neighbours index 
l[a].push_back(b);
l[b].push_back(a);
}
void print(void) {
for(int i=0 ;i<v ; i++ ) {
for(auto it : l[i]) {
cout<<it<<" ";
}
cout<<endl;
}
}
void componentTraversal(void ) {
vector<bool>visited(v , false);
for(int i=0 ; i<v ; i++) {
if(!visited[i]) {
visited[i]=true;
helper(i , visited);
}
}
}
};

int main () {
vector<int>vertices={1,6,4,3,9};
Graph g(8);
g.addEdge(0,1);
g.addEdge(0,3);
g.addEdge(2,7);
g.addEdge(2,4);
g.addEdge(5,7);
g.addEdge(5,4);
g.componentTraversal();
return 0;
}
