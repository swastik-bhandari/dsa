#include"list.h"
using namespace mylist;
int main ()
{

list l;
l.push_front(4);
l.push_front(3);
l.push_front(2);
l.push_back(5);
l.push_back(6);
l.pop_back();
l.pop_back();
l.pop_front();
l.display();
return 0;
}
