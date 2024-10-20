#include<iostream>
#include<queue>
using namespace std;
/*
class student {
public:
string name;
int rollno;
friend class customcompare ;
student() {
rollno=-1;
}
student(string name , int rollno ) : name (name ) , rollno(rollno) {}
};

class customcompare {
public:
bool operator () ( student s1 , student s2) {
return s1.rollno<s2.rollno;
}
};

int main () {
priority_queue<student ,vector<student> , customcompare> pq;
pq.push(student("swastik" , 8));
pq.push(student("sita" , 3));
pq.push(student("hari" , 10));
while(!pq.empty()) {
cout<<pq.top().name<<endl;
pq.pop();
}
return 0;
}
*/
class student {
string name;
int marks;
public:
friend int main () ;
student(string name="" , int marks=-1) : name(name) , marks(marks) {};

bool operator < ( student s ) const{
return this->marks < s.marks;
}

};

int main () {
priority_queue<student> pq ;
pq.push(student("swastik" , 97));
pq.push(student("shubham" , 88));
pq.push(student("hamal" , 100));

while(!pq.empty()) {
cout<<pq.top().name <<" " <<pq.top().marks<<endl;
pq.pop();
}



return 0;
}













 
