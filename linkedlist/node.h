#ifndef NODE_H
#define NODE_H
namespace mylist {
class node {
private:
int data;
node *next;
node();
~node();
node(int);
friend class list;
};
}
#endif // NODE_H
