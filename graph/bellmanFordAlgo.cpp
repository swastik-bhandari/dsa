#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Edge {
int value;
int weight;
friend void print(vector<vector<Edge>>&);
friend vector<int> bellman_shortest_path(int , vector<vector<Edge>> &);
public:
Edge(int w, int v) : weight(w) , value(v){} 
};


void print(vector<vector<Edge>>&v) {
for(auto &edges : v) {
for(auto &e : edges) {
cout<<e.weight<<" " <<e.value<<endl;
}}
}

//////////////////////////////// bellman Ford algorithm ///////////////////////////////////////////////
vector<int> bellman_shortest_path(int src , vector<vector<Edge>> &g) {
int V =g.size();
if(V < src) {
return vector<int>{-1};
}
vector<int>shortest_path(V, INT_MAX);
shortest_path[src]=0;
for(int i=0 ; i<V-1 ; i ++) {

for(int u = 0 ; u <V ; u++) {

for( auto & edge : g[u] ) {
int wt = edge.weight;
int v = edge.value;
if(shortest_path[u] + wt < shortest_path[v]) {
shortest_path[v] = wt + shortest_path[u];
}
}
}
}
return shortest_path;
}

int main () {
int size = 5;
vector<vector<Edge>>g;
g.resize(size);
g[0].push_back(Edge(2,1));
g[0].push_back(Edge(4,2));
g[1].push_back(Edge(-4,2));
g[2].push_back(Edge(2,3));
g[3].push_back(Edge(4,4));
g[4].push_back(Edge(-1,1));

int src = 0;
vector<int> ans = bellman_shortest_path(src , g);

for(auto & it : ans) {
cout<<it;
}

return 0;
}






















