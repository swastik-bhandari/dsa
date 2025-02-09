// negative cycle detection ///////////////  returns vector<int>{-1} , 
// avoids unecessary looping , if shortest path is already found .//////////// exit the loop if no changes in shortest_path .
// perform relaxation only when u !=MAX_INT ; , 

#include<iostream>
#include<vector>
#include<climits>
#include<stdexcept>
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
if(src>=V) {
throw out_of_range("source index is greater than the size of graph");
}
vector<int>shortest_path(V, INT_MAX);
shortest_path[src]=0;
////////////////////// finding shortest path /////////////////////// sssp using bellman ford algorithm /////////////////
for(int i=1 ; i<=V-1 ; i ++) {
bool updated= false;

for(int u = 0 ; u <V ; u++) {

if(shortest_path[u]==INT_MAX) { // as if u is inifinite , it will not relax it's children , so better to avoid relaxation step for this . also prevents overflow.
continue;
}

for( auto & edge : g[u] ) {
int wt = edge.weight;
int v = edge.value;
if(shortest_path[u] + wt < shortest_path[v]) {
shortest_path[v] = wt + shortest_path[u];
updated=true;
}
}
}
if(!updated) {
break;
}
}
//////////////////// check for negative cycle detection //////////////////////
for(int u=0 ; u<V ; u++) {
if(shortest_path[u] == INT_MAX) continue;
for(auto & edge : g[u]) {
int wt = edge.weight;
int v = edge.value;
if(shortest_path[u] + wt < shortest_path[v]) { 
// if shortest_path changes , that indicades there is a negative cycle . because , the shortest path is meant to be found within V-1 , if it is still updating shortest_path means , there is a cycle.
throw runtime_error(" Negative cycle detection , alert !!! ");
}
}
} 
//////////////////////////
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

int src = 5;
try {
vector<int> ans = bellman_shortest_path(src , g);
for(auto & it : ans) {
cout<<it;
}
}
catch(const out_of_range &e) {
cout<<e.what();
}
catch(const runtime_error &e) {
cout<<e.what();
}
catch(...) {
cout<<"exceptional error";
}
return 0;
}






















