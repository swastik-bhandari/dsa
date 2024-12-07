#include<iostream>
#include<list>
#include<vector>
using namespace std;

class Graph  {
private:
list<int> * l ;
int v;
void helper(int i ,bool *visited) {
cout<<i; 
for(auto &it :l[i]) {
if(!visited[it]){
visited[it]=true;
helper(it , visited);
}
}	
}
public:
Graph( int v ) : v(v) {
l = new list<int>[v];
}
void addEdge(int a , int b) { // storing neighbours index 
l[a].push_back(b);
l[b].push_back(a);
}
void print(void) {
for(int i=0 ;i<v ; i++ ) {
for(auto it : l[i]) {
cout<<it<<" ";
}
cout<<endl;
}
}
void depth_first_search(void) {
bool visited[v]={0};
visited[0]=true;
helper(0 , visited);
}
};

int main () {
vector<int>vertices={1,6,4,3,9};
Graph g(vertices.size());
g.addEdge(0,1);
g.addEdge(1,2);
g.addEdge(2,3);
g.addEdge(2,4);
g.depth_first_search();
return 0;
}
