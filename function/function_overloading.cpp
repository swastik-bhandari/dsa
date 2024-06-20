#include<iostream>
using namespace std;
void sum (float){
cout<<"float";
}
void sum(double){
cout<<"double";
}
int main ()
{
sum(3.0f); //float
sum(3.0); //double
return 0;
}
