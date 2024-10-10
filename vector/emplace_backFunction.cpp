#include<iostream>
#include<vector>
using namespace std;

class number {
int num1;
int num2;
int num3;
public:
number(int x , int y , int z) : num1(x) , num2(y) , num3(z) {}
void display(void)
{
cout<<num1<<num2<<num3<<endl;
}
};
int main ()
{
vector<number>v;
for(int i=0 ; i<4 ; i++)
{
int x;
cin>>x;

v.emplace_back(x , x+2 , x+4); // using emplace_back function you need not to create an object and pass it to vector . compiler does it for you .
}
for(number & n : v)
{
n.display();
}
return 0;
}
