#include<iostream>
#include<list>
#include<vector>
using namespace std;
template<typename T>
class Triples {
friend class Graph;
T num1;
T num2;
T weight;
public:
Triples(int a , int b, int c) :num1(a) , num2(b) , weight(c) {}
};
class Graph {
vector<Triples<int>>v;
public:
Graph() { }
void addEdge(int a , int b , int wt) {
v.push_back(Triples<int>(a , b, wt));
}
void display(void) {
for(auto &it : v) {
cout<<it.num1<<" "<<it.num2<<" "<<it.weight<<endl;
}
}
};
int main () {
Graph g;	
g.addEdge(0,1,8);
g.addEdge(1,2,3);
g.addEdge(2,3,4);
g.addEdge(3,1,2);
g.display();
return 0;
}
