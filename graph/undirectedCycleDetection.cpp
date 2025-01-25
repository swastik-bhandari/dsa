#include<iostream>
#include<list>
#include<vector>
using namespace std;

class Graph  {
list<int> * l ;
int v;

bool helper(int i , vector<bool>&visited) {
int toVisit =0;
int neighbours=0;
int alreadyVisitedVertices;
visited[i]=true;
for(auto &it : l[i]) {
neighbours++;
if(!visited[it]) {
toVisit++;
 if( helper(it , visited)) {
 return true;
 }
}
}
alreadyVisitedVertices = neighbours - toVisit;
if(alreadyVisitedVertices ==2) {
return true;
}
return false;
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

bool cycleDetection(void) {
vector<bool>visited(v , false);
for(int i=0 ;i<v ; i++) {
bool x = helper(i,visited);
if(x) {
return true;
}
}
return flase;
}
};

int main () {
Graph g(6);
g.addEdge(0,1);
g.addEdge(1,2);
g.addEdge(2,3);
g.addEdge(2,4);
g.addEdge(4,5);
g.addEdge(5,2);
cout<<g.cycleDetection();
return 0;
}
