#include<iostream>
#include<queue>
using namespace std;
// if custom comparator is not used , comparision is done on the basis of first element in case of priority_queue for pairs . 

struct customComparator {
bool operator () ( pair<string , int > p1 , pair<string , int > p2) {
return p1.second >  p2.second;
}
};

int main () {
priority_queue<pair<string , int > ,vector<pair<string , int >> , customComparator> pq ;
pq.push(make_pair("swastik" , 3));
pq.push(make_pair("hari" , 1));
pq.push(make_pair("sita" , 2));
while(!pq.empty()) {
cout<<pq.top().first<<endl;
pq.pop();
}
return 0;
}
