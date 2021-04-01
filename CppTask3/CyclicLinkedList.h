//
// Created by aleksandr on 31.03.2021.
//

#ifndef CPPTASK3_CYCLICLINKEDLIST_H
#define CPPTASK3_CYCLICLINKEDLIST_H


#include "ListElement.h"

template<typename T>
class CyclicLinkedList {
private:
    ListElement *root;
public:
    CyclicLinkedList(const ListElement &root) {

    }

    void add(T num) {
        ListElement *listElement = new ListElement(num);
        if(root == nullptr)     //если создаем первый узел
            root = listElement;
        else                 //если узел уже не первый
        {
            ListElement *current = root;
            while(current->next != nullptr)
                current = current->next;
            //предшествующий указывает на последний
            current->next = nd;
        }
    }

    void remove(T i){

    };
    void removeByIndex(int i){

    };
    void insertInto(int i, T element){

    };
    ListElement get(T i){

    };
    ListElement getByIndex(T i){

    };

};