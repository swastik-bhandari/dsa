///////////////// concept
#include<iostream>
#include<list>
#include<vector>
#include<queue>
#include<unordered_set>
using namespace std;

class Graph {
list<int>*l;
int size;
bool helper(int , vector<bool>&, unordered_set<int>& , unordered_set<int>&);
public:
Graph(int size) :size(size) {
l = new list<int>[size];
}

void addEdge(int a,int b) {
l[a].push_back(b);
l[b].push_back(a);
}
void display(void) {
for(int i=0 ; i<size; i++) {
for(auto &it: l[i]) {
cout<<it;
}
}
}
bool checkBipartite(void) {
bool result= true;
vector<bool>visited(size , 0);
unordered_set<int>U;
unordered_set<int>V;
for(int i=0 ; i<size ; i++) {
if(!visited[i]) {
if(!helper( i , visited , U , V) ) {
result = false;
}
}
}
cout<<"printing first set"<<endl;
for(auto &it : U) {
cout<<it<<" ";
}
cout<<endl;
cout<<"printing second set"<<endl;
for(auto &it :V) {
cout<<it<<" ";
}
cout<<endl;
cout<<" 1 = graph is partite , 0 = graph is not partite " <<endl;
cout<<"output : ";
return result;
}
};
//////////////
bool Graph :: helper(int i , vector<bool>&visited , unordered_set<int>&U , unordered_set<int>&V) {
queue<int>q;
U.insert(i);
q.push(i);
visited[i]=true;
while(!q.empty()) {
int parent = q.front();
int checkVertexInU = (U.find(parent)!=U.end());
for(auto & it :l[q.front()]) {
if(!visited[it]) {
visited[it]=true;
q.push(it);
if(checkVertexInU) {
V.insert(it);
}else {
U.insert(it);
}
} //////// visited
else {
bool checkNeighbourInU = U.find(it)!=U.end();
if(!(checkVertexInU ^ checkNeighbourInU)) {
return false;
} 
} ///////////// not visited

} ///////// loop in individual list
q.pop();
}  /////// loop in array of list 
return true;
} /////// function-end
int main() {
Graph g(7);
g.addEdge(0,1);
g.addEdge(1,2);
g.addEdge(2,3);
g.addEdge(0,3);
g.addEdge(4,5);
g.addEdge(5,6);
g.addEdge(6,4);
cout<<g.checkBipartite();
return 0;
}
