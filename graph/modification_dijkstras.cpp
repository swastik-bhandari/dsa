// it is also based on lazy dijkstras , reducing the decrease key overhead . just adding to queue not deleting dublicates . 
// don't use it . 

#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

class Edge {
int value;
int weight;
friend class Graph;
friend class customComparator;
public:
Edge(int value , int weight) :value(value) , weight(weight) { }
};

class Graph {
vector<vector<Edge>>g;
int size;
bool is_undirected;
public:
Graph(int size, bool is_undirected):size(size) , is_undirected(is_undirected) {
g.resize(size);
}
void addEdge(int u , int v , int wt) {
g[u].push_back(Edge(v,wt));
if(is_undirected) {
g[v].push_back(Edge(u,wt));
}
}

void print(void) {
for(auto &it : g){
for(auto &edge : it) {
cout<<edge.value<<edge.weight<<endl;
}
}
}

vector<int> shortestPath(int src);
};
///////////////////////// custom comparator ///////////////////////////////////
class customComparator {
int a; 
int b;
public:
customComparator() {}
bool operator () (pair<int, int>&p1 ,pair<int,int>&p2) {
return p1.first > p2.first;
}
};

////////////////// *************************** /////////////////////////////////////////////
vector<int> Graph :: shortestPath(int src) {
priority_queue<pair<int ,int> ,vector<pair<int,int>> , customComparator> pq;
vector<int>shortest_path(size , INT_MAX);
shortest_path[src]=0;
pq.push(make_pair(0,src)); /////////////first = dist from src , second = v

while(!pq.empty()) {

int u = pq.top().second;
int d = pq.top().first;

pq.pop();

if(d!=shortest_path[u]) { /// optional , improve efficiency . 
continue;
}

for(auto & e : g[u]) {
int v = e.value;
int wt = e.weight;
if( (shortest_path[u] + wt) < shortest_path[v] ) {
shortest_path[v] = shortest_path[u] + wt;
pq.push(make_pair(shortest_path[v] , v));
}
}
}
return shortest_path;
}

int main() {
Graph g(4, false);
g.addEdge(0, 1, 10);
g.addEdge(0, 2, 5);
g.addEdge(1, 2, -8);
g.addEdge(2, 3, 3);

int src = 0;
vector<int> v = g.shortestPath(src);
for(auto &it : v) {
cout<<it;
}

return 0;
}
