#include<iostream>
#include<list>
#include<vector>
#include<stack>
using namespace std;

class Graph  {
list<int> * l ;
int v;
bool undirected;
void helper(int i , vector<bool>&visited , stack<int>&s);
public:
Graph( int v  , bool undirected) : v(v) , undirected(undirected) {
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
cout<<i<<": ";
for(auto it : l[i]) {
cout<<it<<" ";
}
cout<<endl;
}
}
void topologicalSortDFS(void) {
vector<bool>visited(v , false);
stack<int>s;
for(int i=0 ; i<v ; i++) {
if(!visited[i]) {
helper( i , visited , s); // 
}
}
while(!s.empty()) {
cout<<s.top();
s.pop();
}
}
};

void Graph::helper(int i , vector<bool>&visited ,stack<int>&s) {
visited[i]=true;

for(auto &neighbour : l[i]) {
if(!visited[neighbour]) {
helper( neighbour , visited , s);
}
}
s.push(i);
}
int main () {
Graph g(6 , false);
g.addEdge(5,0);
g.addEdge(4,0);
g.addEdge(0,3);
g.addEdge(5,2);
g.addEdge(2,3);
g.addEdge(4,1);
g.addEdge(3,1);
g.topologicalSortDFS();
return 0;
}
