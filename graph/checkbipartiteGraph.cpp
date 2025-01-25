#include<iostream>
#include<list>
#include<vector>
#include<queue>
#include<unordered_set>
using namespace std;

class Graph {
list<int>*l;
int size;
bool helper( int , vector<bool> & , vector<int>&);
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
vector<bool>visited(size , 0);
vector<int>color(size , -1);
for(int i=0 ; i<size ; i++) {
if(!visited[i]) {
if(!helper( i , visited , color
) ) {
return false;
}
}
}
return true;
}
};

bool Graph :: helper(int i , vector<bool>&visited , vector<int>&color) {
queue<int>q;
color[i]=1;
q.push(i);
visited[i]=true;
while(!q.empty()) {
int parent = q.front();
int vertexColor = color[parent];
for(auto & it :l[q.front()]) {
if(!visited[it]) {
visited[it]=true;
q.push(it);
if(vertexColor == 1) {
color[it]=0;
}else {
color[it]=1;
}
} //////// visited

else {
bool neighbourColor = color[it];
if(neighbourColor == vertexColor) {
return false;
}
} ///////////// not visited

} ///////// loop in individual list
q.pop();
}  /////// loop in array of list 
return true;
} /////// function-end
int main() {
Graph g(6);
g.addEdge(0,1);
g.addEdge(1,2);
g.addEdge(2,3);
g.addEdge(0,3);
g.addEdge(4,5);
cout<< g.checkBipartite();
return 0;
}
