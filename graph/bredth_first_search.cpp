#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

class Graph {
int size ;
list<int>* l;
public:
Graph (int size) :size(size) {
l=new list<int>[size];
}
void addEdge (int x, int y) {
l[x].push_front(y);
}
void display (void) {
for(int i=0 ;i<size ;i++){
for(auto &it : l[i]) {
cout<<it;
}
cout<<endl;
}
}
void breadth_first_search(void ) {
bool visited[size]={0};
queue<int>q;
q.push(0);
visited[0]=true;
while(!q.empty()) {
int temp=q.front();
for(auto &it : l[temp]) {
if(!visited[it]){
visited[it]=true;
q.push(it);
}
}
cout<<q.front();
q.pop();
}
}
};
int main () {
int l[]={12,34,11,32,22};
int size=sizeof(l)/sizeof(l[0]);
Graph g(size);
g.addEdge(0,1);
g.addEdge(1,0);
g.addEdge(1,3);
g.addEdge(3,1);
g.addEdge(2,1);
g.addEdge(1,2);
g.addEdge(2,3);
g.addEdge(3,2);
g.addEdge(2,4);
g.addEdge(4,2);
g.breadth_first_search();
return 0;
}
