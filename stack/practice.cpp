#include<iostream>
#include<stack>
#include<vector>
#include<string>
using namespace std;

bool is_operator(const string& str) {
    return str == "+" || str == "-" || str == "*" || str == "/";
}

int postEval(string arr[] , int size) {
stack<string>s;
int num1 , num2 , num3;
for(int i=0 ; i<size ;i++) {
string str=arr[i];

if(is_operator(str)) {
if(!s.empty())  { 
 num1=stoi(s.top());
s.pop();
}
if(!s.empty())  { 
 num2=stoi(s.top());
s.pop();
}

if(str=="+") {
 num3 = num1+num2;
s.push(to_string(num3));
}
if(str=="-") {
 num3 = num1-num2;
s.push(to_string(num3));
}
if(str=="*") {
 num3 = num1*num2;
s.push(to_string(num3));
}
if(str=="/") {
 num3 = num1/num2;
s.push(to_string(num3));
}
}
else {
s.push(str);
}
}
return stoi(s.top());
}


int main() {
string arr[]={"5","3","4","*","+"};
int n = sizeof(arr) /sizeof(arr[0]);
cout<<postEval(arr ,n);
return 0;
}

