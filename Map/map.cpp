#include<iostream>
#include<map>
using namespace std ;
int main ()
{
map<int , string> m; // creating a map 
// map <int , string> m={{1,"swastik"} , {2 , "shubham"} , {3 , "ridhi"} , { 2 , "sidhi"} };
m[1]="swastik";  // insert in map 
m[2]="shubham";
m[3]="ridhi";
m[2]="sidhi";
cout<<m[2]<<endl; // access value using key
cout<<m.count(3)<<endl; // 1 if key exists , 0 if key doesnt exist
for(auto it : m) {
cout<<it.first<<it.second<<endl;
}
return 0;
}
