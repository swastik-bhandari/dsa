#include<iostream>
#include<list>
#include<vector>
#include<queue>
#include<tuple>
#include<climits>
using namespace std;

class customComparator {
public:
customComparator() {} 
bool operator() (pair<int , int>& a , pair<int , int> &b) {
return a.first > b.first;
}
};




class Graph {
list<pair<int ,int>> *l;
int size;
bool is_undirected;
public:
Graph(int size ,bool is_undirected=true):size(size) , is_undirected(is_undirected) {
l= new list<pair<int,int>>[size];
}
~Graph() {
delete[] l;
l=nullptr;
}
///////////// adding edges ////////////////
void addEdge(int u , int wt , int v) {
l[u].push_back(make_pair(wt , v));
if(is_undirected) {
l[v].push_back(make_pair(wt, u));
}
}
///////////////////
////////// printing /////////
void print(void) {
for(int i=0 ; i<size ; i++) {
for(auto & it : l[i]) {
cout<<"wt:"<<it.first<<" edge:"<<it.second<<endl;
}
cout<<endl;
}
}
///////////////////////
///////////////////////// MST using prims Algorithm , sum of wts of MST .
vector<tuple<int,int,int>> MST_using_prims(void) {
if(size<2) {
throw runtime_error("no edges in connected graph");
}
priority_queue< pair<int, int> , vector<pair<int ,int>> , customComparator> pq;
vector<bool>visited(size, false);
vector<tuple<int,int,int>>mst;
vector<int>parent(size,-1);
vector<int>min_wt(size,INT_MAX);
pq.push(make_pair(0,0));
min_wt[0]=0;
///////////////////
while(!pq.empty()) {
int wt = pq.top().first;
int u = pq.top().second;
pq.pop();
if(visited[u]) continue;
visited[u]=true;
for(auto & e : l[u]) {
int v_wt = e.first;
int v = e.second;
if(!visited[v] && v_wt < min_wt[v]) {
parent[v]=u;
min_wt[v]=v_wt;
pq.push(e);
}
}
}
for(int i=0 ; i<size ; i++) {
int u= parent[i];
int v = i;
int weight = min_wt[i];
mst.push_back(make_tuple(u, weight , v));
}

return mst;
}
};

int main() {
Graph g(4);
g.addEdge(0,10,1);
g.addEdge(1,40,3);
g.addEdge(3,50,2);
g.addEdge(0,30,3);
g.addEdge(0,15,2);
vector<tuple<int,int,int>>mst = g.MST_using_prims();
 for (auto& edge : mst) {
        cout << "(u,v)=(" << get<0>(edge) << "," << get<2>(edge) << ") wt:" << get<1>(edge) << endl;
    }
return 0;
}
