#ifndef LIST_H
#define LIST_H
#include<iostream>
#include"node.h"
namespace mylist {
class list{
private:
node *head;
node *tail;
int searchRecHelper(int , node *);
bool checkPalindromeRecHelper(node *);
public:
list();
~list();
void push_back(int);
void push_front(int);
void display(void);
void pop_back(void);
void pop_front(void);
int searchItr(int);
int searchRec(int);
void reverse(void);
void removeNthFromBack(int);
node * headObj(void);
bool checkPalindromeRec(void);
};
}
#endif // LIST_H

