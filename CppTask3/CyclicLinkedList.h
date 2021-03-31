//
// Created by aleksandr on 31.03.2021.
//

#ifndef CPPTASK3_CYCLICLINKEDLIST_H
#define CPPTASK3_CYCLICLINKEDLIST_H


#include "ListElement.h"

class CyclicLinkedList {
private:
    ListElement *root;
public:
    CyclicLinkedList(const ListElement &root);
    void add(int num);
    void remove(ListElement element);
    void remove(int i);
    void insertInto(int i, ListElement element);
    ListElement get(int i);

};


#endif //CPPTASK3_CYCLICLINKEDLIST_H
