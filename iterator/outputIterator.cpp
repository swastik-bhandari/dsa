#include<iterator>
#include<iostream>
#include<vector>
using namespace std;
int main ()
{
vector<int>v={1,2,3,4,5};
ostream_iterator<int> it1(cout);
istream_iterator<int> it2(cin);
istream_iterator<int> end_of_stream;
copy(it2 , end_of_stream , back_inserter(v));
copy(v.begin() , v.end() , it1);
cout<<endl;
return 0;
}
