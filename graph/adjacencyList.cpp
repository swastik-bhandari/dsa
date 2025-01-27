#include<iostream>
#include<list>
#include<vector>
using namespace std;

class Graph  {
list<int> * l ;
int v;
bool undirected;
public:
Graph( int v  , bool undirected) : v(v) , undirected(undirected) {
l = new list<int>[v];
}
void addEdge(int a , int b) { // storing neighbours index 
l[a].push_back(b);
if(undirected) {
l[b].push_back(a);
}
}
void print(void) {
for(int i=0 ;i<v ; i++ ) {
for(auto it : l[i]) {
cout<<it<<" ";
}
cout<<endl;
}
}
};

int main () {
vector<int>vertices={1,6,4,3,9};
Graph g(vertices.size() , false);
g.addEdge(0,1);
g.addEdge(1,2);
g.addEdge(2,3);
g.addEdge(2,4);
g.print();
return 0;
}
