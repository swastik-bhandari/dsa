#include<iostream>
#include<list>
#include<vector>
#include<queue>
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
int MST_using_prims(void) {
if(size<2) {
return 0;
}
priority_queue< pair<int, int> , vector<pair<int ,int>> , customComparator> pq;
vector<bool>visited(size, false);
int sum=0;
pq.push(make_pair(0,0));
///////////////////
while(!pq.empty()) {
int wt = pq.top().first;
int u = pq.top().second;
pq.pop();
if(visited[u]) continue;
visited[u]=true;
sum += wt;
for(auto & e : l[u]) {
if(!visited[e.second]) {
pq.push(e);
}
}
}
return sum;
}
};

int main() {
Graph g(5);
g.addEdge(0,10,1);
g.addEdge(1,40,3);
g.addEdge(3,50,2);
g.addEdge(0,30,3);
g.addEdge(0,15,2);
cout<<g.MST_using_prims();
return 0;
}
