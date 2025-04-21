#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

class customComparator {
public:
bool operator () (pair<int,int>p1 , pair<int,int>p2 ) {
return p1 >p2;
}
};

class Graph {
int size;
list<pair<int,int>>*l;
bool undirected;

public:
Graph(int size , bool undirected) {
this->undirected = undirected;
this->size = size;
l = new list<pair<int,int>>[size];
}
~Graph() {
delete[] l;
}
void addEdge(int u , int wt , int v) {
l[u].push_back(make_pair(wt,v));
if(undirected) {
l[v].push_back(make_pair(wt,u));
}
}


int primsAlgo(int src) {
vector<bool>mst(size , false);
priority_queue<pair<int,int> , vector<pair<int,int>> , customComparator>pq;
int sum=0;
pq.push(make_pair(0,src));

while(!pq.empty()) {
int u= pq.top().second;
int u_wt= pq.top().first;
if(!mst[u]) {
mst[u]=true;
sum+=u_wt;
for(auto & neigh : l[u]) {
int v = neigh.second;
int v_wt = neigh.first;

if(!mst[v]) {
pq.push(make_pair(v_wt,v));
}
}
}
pq.pop();
}
return sum;
}
};
int main() {
Graph g(4, true);
g.addEdge(0,10,1);
g.addEdge(1,40,3);
g.addEdge(3,50,2);
g.addEdge(0,30,3);
g.addEdge(0,15,2);
cout<<g.primsAlgo(0);
return 0;
}

