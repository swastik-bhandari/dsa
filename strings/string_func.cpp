#include<iostream>
#include<string>
using namespace std; 
int main ()
{
/*string str;
getline (cin , str);
//length
cout<<str.size()<<endl;
cout<<str.length()<<endl;
cout<<str<<endl;
//clear function
cout<<"clear function"<<endl;
str.clear();
cout<<str;
// compare function
string str1, str2;
getline (cin , str1);
getline (cin , str2);
cout<<str1.compare(str2); */

//str.find(word) // find function returns unsigned value
string str;
str="nincompoop";
//cout<<str.find ("comp");
//cout<<str.find("corn"); 
cout<<(int)str.find("corn"); // -1
return 0;
}
