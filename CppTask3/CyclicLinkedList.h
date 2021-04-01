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
    CyclicLinkedList(T[] list) {
        add(list);
    }

    CyclicLinkedList(std::vector<T> list) {
        add(list);
    }

    CyclicLinkedList(CyclicLinkedList list) {
        add(list);
    }

    CyclicLinkedList(const ListElement &root) {
        add(root);
    }

    CyclicLinkedList() {
        root = nullptr;
    }

    void add(std::vector<T> list) {
        if(list.isEmpty()) return;
        for (T element : list){
            add(element);
        }
    }

    void add(T[] list) {
        if(list.isEmpty()) return;
        for (T element : list){
            add(element);
        }
    }

    void add(CyclicLinkedList list) {
        if(list.isEmpty()) return;
        ListElement *target =  list.root;
        ListElement *current =  target->next;
        if(current == target){
            add(target);
        } else
        while (current!=target){
            add(current);
            current = current->next;
        }
    }

    //completed
    void add(T num) {
        ListElement *listElement = new ListElement(num);

        if(isEmpty())
        {
            root = listElement;
            root.next = root;
        }
        else
        {
            ListElement *current = root;
            while(current->next != root)
                current = current->next;
            current->next = listElement;
        }
    }

    //completed
    void remove(T i){
        if(isEmpty()) return;

        ListElement *current = root;
        while (current->next != root){
            if(current.data == i){
                return current;
            }
            current = current->next;
        }

    };

    //completed
    void removeByIndex(int i){

        if(isEmpty()) return;

        ListElement *current = root;
        for(int j = 0; j < i-1; j++){
            current = current->next;
        }
        ListElement *removeElement = current->next;
        current->next = removeElement->next;
    };

    //completed
    void insertInto(int i, T element){
        ListElement *listElement = new ListElement(num);
        if(isEmpty())
        {
            root = listElement;
            root.next = root;
        }
        else
        {
            ListElement *current = root;
            for(int j = 0; j < i; j++){

                current = current->next;
            }
            listElement->next = current->next;
            current->next = listElement;
        }
    };

//Un completed
    int getIndex(T data){
        if(isEmpty()) return;

        ListElement *current = root;
        if(root->next == root) {
            if (current.data == data) {
                return 0;
            } else return -1;
        }

        while (current->next != root){

            current = current->next;
        }

    };


    ListElement get(int target){
        if(isEmpty()) return;

        ListElement *current = root;
        for(int i = 0; i < target; i++){
            current = current->next;
        }
        return current;
    };

    bool isEmpty(){
        if(root == nullptr) return true;
        return false;
    }

};