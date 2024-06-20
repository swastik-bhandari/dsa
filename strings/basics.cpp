#include<iostream>
using namespace std ;
int main ()
{
char ch[]={'h','e','l','l','o','\0'};
// char ch[]={'h','e','l','l','o'}; //garbage at the end due to absence of null character
// char ch[5]={'h','e','l','l','o'};//garbage at the end due to absence of null character
// char ch[]="hello";
cout<<sizeof(ch);
cout<<ch;
return 0;
}
