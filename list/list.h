#ifndef LIST_H
#define LIST_H

#include "listnode.h"

template<typename T>
class List
{
public:
    List();

private:
    int _size = 0;
    ListNode<T> *_header = nullptr;
    ListNode<T> *_trailer = nullptr;


};

#endif // LIST_H
