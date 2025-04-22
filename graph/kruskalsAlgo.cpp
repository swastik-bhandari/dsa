#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Graph;
class Triple {
friend class customComparator;
friend class Graph;
public:
int a;
int b;
int c;
public:
Triple() : a(0) , b(0) , c(0) {}
Triple(int a ,int b , int c) :a(a) , b(b) , c(c) {}
};

class customComparator {

public:
bool operator() (Triple t1 , Triple t2) {
return t1.b > t2.b;
}
};

class Graph {
vector<Triple>E;
int size;
public:
Graph(int size ) :size(size) { }

void addEdge(int x , int wt , int y) {
E.emplace_back(x,wt,y);
}
void print(void) {
for(auto &it : E) {
cout<<it.a<<it.b<<it.c<<endl;
}
}

int leader(int x , vector<int>&parent) {

if(parent[x]!=x) {
int p = leader(parent[x] , parent);
parent[x] =p; // path compression
return p;
}
return x;
}

Graph MST(void) {
Graph t(size);
vector<int>parent;
vector<int>rank(size ,1);
for(int i=0 ; i<size ; i++) {
parent.push_back(i);
}
priority_queue<Triple,vector<Triple>,customComparator>pq(E.begin() , E.end() , customComparator());
while(!pq.empty()) {
int u = pq.top().a;
int v = pq.top().c;
int wt = pq.top().b;
int p1 = leader(u , parent);
int p2 = leader(v , parent);
int rank1 = rank[p1];
int rank2 = rank[p2];
if(p1!=p2) {
t.addEdge(u , wt , v);
if (rank1 > rank2) {
    parent[p2] = p1;
} else if (rank1 < rank2) {
    parent[p1] = p2;
} else {
    parent[p2] = p1;
    rank[p1]++;
}
}
pq.pop();
}

return t;
}

};

int main() {

Graph g(12);
g.addEdge(0, 4, 1);  // edge from 0 to 1 with weight 4
g.addEdge(0, 4, 2);  // edge from 0 to 2 with weight 4
g.addEdge(1, 2, 2);
g.addEdge(1, 3, 5);
g.addEdge(2, 3, 5);
g.addEdge(2, 4, 11);
g.addEdge(3, 5, 1);
g.addEdge(4, 5, 7);
Graph t = g.MST();
t.print();
return 0;
}


