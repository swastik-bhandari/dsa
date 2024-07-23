#ifndef LIST_H
#define LIST_H
#include<iostream>
#include"node.h"
namespace mylist {
class list{
private:
node *head;
node *tail;
public:
list();
~list();
void push_back(int);
void push_front(int);
void display(void);
void pop_back(void);
void pop_front(void);
};
}
#endif // LIST_H

