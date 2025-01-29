///////////// cycle detection , you can check , how many vertices got into the queue , as those vertices with indegree 0 can be queued , so if cycle exist , the vertices in the cycle have indegree 1 after the completion , they do not get queued . you can check number of element queued like in the code. or run a loop i in the indegree vector and check if there any vertex has non zero indegree or not . ///////////
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

bool isCycle(void) {
vector<int>indegree = Graph::inDegree();
int visitedCount=0;
queue<int>q;
for(int i=0 ;i<indegree.size() ; i++) {
if(indegree[i]==0) {
visitedCount++;
q.push(i);
}
}
while(!q.empty()) {
int vtx = q.front();
for(auto &neigh : l[vtx]) {
indegree[neigh]--;
if(indegree[neigh]==0) {
visitedCount++;
q.push(neigh);
}
}
q.pop();
}
if(visitedCount!=size) {
return true;
}
return false;
}

};
int main() {
int size=6;
Graph g(size ,false);
g.addEdge(0,3);
g.addEdge(3,1);
g.addEdge(4,1);
g.addEdge(4,0);
g.addEdge(5,0);
g.addEdge(5,2);
g.addEdge(2,3);
cout<<g.isCycle();
return 0;
}
