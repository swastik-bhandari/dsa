///////////// indegree ///////////
#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

class Graph {
list<int> *l;
int size;
bool isUndirected;
public:
Graph(int size , bool isUndirected) : size(size) , isUndirected(isUndirected) {
l = new list<int>[size];
}
~Graph() {
delete[] l;
l = nullptr;
}
void addEdge(int vtx1 , int vtx2) {
l[vtx1].push_back(vtx2);
if(isUndirected) {
l[vtx2].push_back(vtx1);
}
}
void print(void) {
for(int i=0 ; i<size ;i++) {
for(auto &neigh : l[i]) {
cout<<neigh<<" " ;
}
cout<<endl;
}
}
vector<int> inDegree (void) {
vector<int>indeg(size , 0);
for(int i=0 ; i<size ; i++) {
for(auto &neigh : l[i]) {
indeg[neigh]++;
}
}
return indeg;
}
};
int main() {
Graph g(6 ,false);
g.addEdge(0,3);
g.addEdge(3,1);
g.addEdge(4,1);
g.addEdge(4,0);
g.addEdge(5,0);
g.addEdge(5,2);
g.addEdge(2,3);
vector<int> v = g.inDegree();
for(auto &it  : v) {
cout<<it;
}
return 0;
}
