#include<iostream>
#include<list>
#include<vector>
using namespace std;

class Graph {
int v;
list<pair<int , int >> *l;
public:
Graph(int v) : v(v) {
l= new list<pair<int , int >>[v];
}
void addEdge(pair<int ,int>p1 , pair<int , int>p2) {
l[p1.first].push_back(p2);
l[p2.first].push_back(p1);
}
void print(void) {
for(int i=0 ; i<v ; i++ ) {
for( auto it : l[i]) {
cout<<it.first<<" "<<it.second<<"        ";
}
cout<<endl;
}
}
};

int main () {
Graph g(5);
g.addEdge(pair<int , int>(0,1) , pair<int , int>(1,1));
g.addEdge(pair<int , int>(1,5) , pair<int , int>(2,5));
g.addEdge(pair<int , int>(2,2) , pair<int , int>(3,2));
g.addEdge(pair<int , int>(2,3) , pair<int , int>(4,3));
g.print();
return 0;
}
