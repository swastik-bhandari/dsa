#include<string.h>
#include<iostream>
using namespace std;
bool  palindrome (char * , int );
int main ()
{
char word[50];
cin.getline(word,50);
int n =strlen(word);
if (palindrome(word, n ))
{
cout<<"palindrome";
}
else
{
cout<<"not palindrome";
}
return 0;
}
bool palindrome (char *word , int n )
{
int s=0 ; 
int e= n-1;
while (s<e)
{
if (word[s]!=word[e])
{
return false;
}
s++;
e--;
}
return true;
}
