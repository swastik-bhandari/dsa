// you can use string , instead of list to print the path

#include<iostream>
#include<list>
#include<vector>
#include<stack>
using namespace std;

class Graph  {
list<int> * l ;
int v;
bool undirected;
void helper(int i , int &dest , vector<bool>&visited , list<int>&path);
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
void printAllPath(int src , int dest) {
vector<bool>visited(v , false);
list<int>path;
helper(src , dest , visited , path);
}
};
void Graph :: helper(int i , int &dest , vector<bool>&visited , list<int>&path) {
visited[i] = true;
path.push_back(i);

if(i == dest) {
for(auto &it : path){
cout<<it;
}
cout<<"\n";
visited[i]=false;
path.pop_back();
return;
}

for(auto &neighbour : l[i] ) {
if(!visited[neighbour]) {
helper(neighbour,dest , visited ,path);
}
}
visited[i]=false;
path.pop_back();
}
int main () {
Graph g(6, false);
g.addEdge(0,3);
g.addEdge(3,1);
g.addEdge(4,1);
g.addEdge(4,0);
g.addEdge(5,0);
g.addEdge(5,2);
g.addEdge(2,3);
g.printAllPath(5 ,1);
return 0;
}
