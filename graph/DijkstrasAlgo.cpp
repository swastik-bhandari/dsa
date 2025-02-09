//////////////////// In academic terms, the standard Dijkstra's algorithm uses a priority queue with decrease-key,  /////////////////////
/////// in this code , i have used lazy method . 
/*Standard Dijkstra's Algorithm: In the traditional version, when you find a shorter path to a node, you need to update its priority in the priority queue. This "decrease key" operation can be expensive, depending on how the priority queue is implemented.

Lazy Approach: Lazy Dijkstra's avoids this by simply inserting the new, shorter distance into the queue. This means there might be multiple entries for the same node in the queue, but that's okay.

How it Handles Duplicates: When the algorithm pulls a node from the priority queue, it checks if the distance associated with that entry is still the shortest known distance to that node. If it is, the node is processed as usual. If it's not (meaning a shorter path has been found since that entry was added), the algorithm simply discards that entry and moves on to the next one in the queue.

In essence, Lazy Dijkstra's trades more entries in the priority queue for fewer expensive update operations.
*/

// to implement the standard dijkstra's algo , you need to find in the head whether it already exists or not  and if exists , delete it and then push .
// ie , 
/* 
bool exists = pq.find(pair<shortest_distance[v] , v>);
if(exists) {
pq.remove(pair<shortest_distance[v] , v>) ; // priority_queue does not support decrease key and increase key . so create your own heap .
}
shortest_path[v] = shortest_path[u] + wt;
pq.push(make_pair(shortest_path[v] , v));
}
*/
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
vector<bool>processed(size, false); /////////////// processed means , poped out of priority queue . 
vector<int>shortest_path(size , INT_MAX);
shortest_path[src]=0;
pq.push(make_pair(0,src)); /////////////first = dist from src , second = v

while(!pq.empty()) {

int u = pq.top().second;
int d = pq.top().first;

pq.pop();
if(processed[u]) { continue; }
processed[u] = true;

for(auto & e : g[u]) {
int v = e.value;
int wt = e.weight;
if(wt <0) {
return vector<int> {-1};
}
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
//# Add edges using the addEdge method
g.addEdge(0, 1, 10);
g.addEdge(0, 2, 5);
g.addEdge(1, 2, -8);
g.addEdge(2,3,3);
int src = 0;
vector<int> v = g.shortestPath(src);
for(auto &it : v) {
cout<<it;
}

return 0;
}
