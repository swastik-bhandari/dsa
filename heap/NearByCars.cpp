#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Car {
public:
int idx;
int distSq;
Car() : idx(-1) , distSq(-1) {}
Car(int idx , int distSq) : idx(idx) , distSq(distSq) {}

bool operator < (Car c) const{
return this->distSq>c.distSq;
}

};

/*
void nearbyCars(vector<pair<int, int >> &v , int k ) {
priority_queue<Car>pq;
int temp;
int idx=0;
for(pair<int,int> it : v) {
temp=it.first*it.first + it.second*it.second; 
pq.push(Car(idx , temp));     //time-Complexity: O(logn)  ,loop is running n times , so  total time-complexity: O(nlogn)
idx++;
}
for(int i=0 ; i<k ; i++) {                      // O(klogn)
cout<<pq.top().idx<<" "<<pq.top().distSq<<endl;
pq.pop();
}
} */

// optimized way 
void nearbyCars(vector<pair<int , int>> &v , int k ) {
vector<Car>cars;
int dt;
int idx=0;
for(pair<int , int> it : v) {    // O(n)
dt= it.first*it.first + it.second*it.second;
cars.push_back(Car(idx , dt));
idx++;
}
priority_queue<Car>pq(cars.begin() , cars.end()); // O(n)
for(int i=0 ; i<k ; i++) {
cout<<pq.top().idx<<" " <<pq.top().distSq<<endl;
pq.pop();
} 
}

int main () {
vector<pair<int , int>> v;
v.push_back(make_pair(3,3));
v.push_back(make_pair(5,-1));
v.push_back(make_pair(-2,4));
int k=3;
nearbyCars(v,k);
return 0;
}
