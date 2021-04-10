//
// Created by aleksandr on 09.04.2021.
//

#ifndef CPPTASK3_LISTMANAGER_H
#define CPPTASK3_LISTMANAGER_H


#include "CyclicLinkedList.h"
template<typename T>
class ListManager {
private:
    CyclicLinkedList<T> cyclicLinkedList;
public:
    ListManager(){
    };
    ListManager(CyclicLinkedList<T> linkedList){
        cyclicLinkedList = linkedList;
    };
    void start(){

    };
    void pfint();

};


#endif //CPPTASK3_LISTMANAGER_H
