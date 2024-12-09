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

}

}

}

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
