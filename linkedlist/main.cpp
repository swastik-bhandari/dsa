#include"list.h"
using namespace mylist;
int main ()
{

list l;
//l.push_front(3);
//l.push_front();
l.push_back(3);
l.push_back(2);
l.push_back(1);
l.push_back(4);
//l.pop_back();
//l.pop_back();
//l.pop_front();
//l.display();
//std::cout<<l.searchItr(4);
//std::cout<<l.searchRec(5);
//l.reverse();
//l.display();
//l.removeNthFromBack(2);
//l.display();
//std::cout<<l.checkPalindrome();
//l.makeCircular();
//l.removeCircle();
//l.display();
l.sort();
l.display();
return 0;
}
