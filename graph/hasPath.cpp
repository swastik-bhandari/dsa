/*             //////// using bfs ///////////////////////////////////
#include<iostream>
#include<list>
#include<vector>
#include<queue>
using namespace std;

class Graph  {
list<int> * l ;
int v;
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

/////////////////
bool hasPath(int s , int d) {
cout<<"has path : ";
bool visited[v]={0};
queue<int>q;
q.push(s);
visited[s]=true;
while(!q.empty()) {
if(q.front()==d) {
return true;
}
for(auto &it :l[q.front()]) {
if(!visited[it]) {
q.push(it);
visited[it]=true;
}
}
q.pop();
}
return false;
}
};
int main () {
Graph g(5);
g.addEdge(0,3);
g.addEdge(0,4);
g.addEdge(3,1);
g.addEdge(3,2);
int source = 1;
int destination = 2;
cout<<g.hasPath(source , destination);
return 0;
}
*/

/////////////////// using dfs //////////////////////////////////////////
#include<iostream>
#include<list>
using namespace std;
class Graph {
int size;
list<int>*l;
public:
Graph(int size) : size(size) {
l= new list<int>[size];
}
void push(int x, int y) {
l[x].push_back(y);
l[y].push_back(x);
}
bool helper(int start , int target , bool *v) {
v[start]=true;
if(start==target) {
return true;
}
for(auto &neighbours : l[start]) {
if(!v[neighbours]) {
if(helper(neighbours , target , v)) {
return true;
}}}
return false;
} 
bool hasPath(int start , int target) {
bool v[size]={false};
return helper(start , target , v);
}
};

int main () {
int arr[]={0,1,2,3,4,5};
int size=sizeof(arr)/sizeof(arr[0]);
Graph g(size);

g.push(0,1);

g.push(0,2);

g.push(1,3);

g.push(2,4);

g.push(3,4);

g.push(4,5);

g.push(3,5);

cout<<g.hasPath(2,6);
return 0; 
}
