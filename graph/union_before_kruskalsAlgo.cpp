#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Graph;
class Triple {
friend class Graph;
int a;
int b;
int c;
public:
Triple(int a ,int b , int c) :a(a) , b(b) , c(c) {}
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

void union_set(void) {
vector<int>parent;
vector<int>rank(size ,1);
for(int i=0 ; i<size ; i++) {
parent.push_back(i);
}

for(auto &e : E ) {
int u = e.a;
int v = e.c;
int p1 = leader(u , parent);
int p2 = leader(v , parent);
int rank1 = rank[p1];
int rank2 = rank[p2];
if(p1!=p2) {
if (rank1 > rank2) {
    parent[p2] = p1;
} else if (rank1 < rank2) {
    parent[p1] = p2;
} else {
    parent[p2] = p1;
    rank[p1]++;
}
}
else {} // cycle condition

}
int q=leader(5 , parent);
int w=leader(4 , parent);
for(int i= 0 ; i<size ; i++) {
cout<<i<<"->"<<parent[i]<<" rank:"<<rank[i]<<endl;
}
}

};

int main() {

Graph g(6);
g.addEdge(0, 1, 1);
g.addEdge(1, 1, 2);
g.addEdge(3, 1, 4);
g.addEdge(4, 1, 5);
g.addEdge(1,1,5);


g.print();
g.union_set();
return 0;
}


