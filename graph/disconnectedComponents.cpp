#include<iostream>
#include<list>
#include<vector>
using namespace std;

class Graph  {
list<int> * l ;
int v;
void helper(int i ,vector<bool>&visited) {
visited[i]=true;
cout<<i;
for(auto &it: l[i]) {
if(!visited[it]) {
helper(it , visited);
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

void depth_first_search(void) {
vector<bool>visited(v , false);
for(int i=0 ; i<v ; i++ ) {
if(!visited[i]) {
helper(i , visited);
}}
}
};

int main () {
vector<int>vertices={0,1,2,3,4,5,6,7,8};
Graph g(vertices.size());
g.addEdge(0,3);
g.addEdge(1,2);
g.addEdge(2,4);
g.addEdge(4,5);
g.addEdge(3,6);
g.addEdge(6,7);
g.addEdge(3,7);
g.addEdge(5,8);
g.addEdge(1,8);
g.depth_first_search();
return 0;
}
