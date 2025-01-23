#include<iostream>
#include<list>
#include<vector>
using namespace std;

class Graph {
vector<vector<int>> v;
int size;
public:
Graph( int size):size(size) {
for(int i=0 ; i<size ; i++ ) {
v.push_back(vector<int>(size , 0));
}
}
void addEdge(int a ,int b, int weight) {
v[a][b]=weight;
v[b][a]=weight;
}
void display(void) {
for(auto &it : v) {
for(auto &jt : it) {
cout<<jt<<" ";
}
cout<<endl;
}
}
};

int main () {
vector<int>vertices={1,6,4,3,4};
Graph g(vertices.size());
g.addEdge(0,1,8);
g.addEdge(1,2,3);
g.addEdge(2,3,4);
g.addEdge(3,1,2);
g.display();
return 0;
}
