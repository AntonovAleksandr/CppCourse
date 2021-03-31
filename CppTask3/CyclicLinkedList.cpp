//
// Created by aleksandr on 31.03.2021.
//

#include <clocale>
#include "CyclicLinkedList.h"

CyclicLinkedList::CyclicLinkedList(const ListElement &root) : root(nullptr) {
}

void CyclicLinkedList::add(int num) {
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
