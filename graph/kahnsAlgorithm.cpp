///////////// topological sorting and cycle detection by kahn's algorithm ///////////
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
///////// indegree calculation ////////////
vector<int> inDegree (void) {
vector<int>indeg(size , 0);
for(int i=0 ; i<size ; i++) {
for(auto &neigh : l[i]) {
indeg[neigh]++;
}
}
return indeg;
}
///////////////////////

vector<int> topoSortKahnsAlgo(void) {
vector<int>indegree = Graph::inDegree();
vector<int>ans;
queue<int>q;
for(int i=0 ;i<indegree.size() ; i++) {
if(indegree[i]==0) {
q.push(i);
}
}
while(!q.empty()) {
int vtx = q.front();
for(auto &neigh : l[vtx]) {
indegree[neigh]--;
if(indegree[neigh]==0) {
q.push(neigh);
}
}
ans.push_back(q.front());
q.pop();
}
if(ans.size()!=size) {
throw runtime_error("there is a cylcle in this directed graph");
}
return ans;
}
};
int main() {
int size=6;
Graph g(size ,false);
g.addEdge(0,3);
g.addEdge(3,1);
g.addEdge(1,4);
g.addEdge(4,0);
g.addEdge(5,0);
g.addEdge(5,2);
g.addEdge(2,3);
try {
vector<int> topoSorted = g.topoSortKahnsAlgo();
for(auto &it : topoSorted) {
cout<<it<<" ";
}
} catch(runtime_error & e) {
cout<<e.what();
}
catch(...) {
cout<<"error!  , check your code"<<endl;
}
return 0;
}
