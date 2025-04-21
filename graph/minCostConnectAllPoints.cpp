#include<iostream>
#include<vector>
#include<list>
using namespace std;

class Graph {
list<pair<int,int>> * l;
int size;
bool undirected;
public:
Graph(int size , bool undirected ) : size(size) , undirected(undirected){
l = new list<pair<int,int>>[size];
}
~Graph() {
delete[] l;
}

void addEdge(int a , int b , int wt) {
l[a].push_back(make_pair(wt , b));
if(undirected) {
l[b].push_back(make_pair(wt , a));
}
}



};

int main () {

return 0;
}
