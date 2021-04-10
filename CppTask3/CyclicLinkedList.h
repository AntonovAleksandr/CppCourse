
#ifndef CPPTASK3_CYCLICLINKEDLIST_H
#define CPPTASK3_CYCLICLINKEDLIST_H


#include <vector>
#include <string>
#include "ListElement.h"

template<typename T>
class CyclicLinkedList {
private:
    ListElement<T> *m_root;
    int m_size;
public:
    CyclicLinkedList(T* list[]) {
        add(list);
    }

    CyclicLinkedList(std::vector<T> list) {
        add(list);
    }

    CyclicLinkedList(CyclicLinkedList *list) {
        add(list);
    }

    CyclicLinkedList(ListElement<T> root) : m_root(root) {
        add(root);
    }

    CyclicLinkedList() {
        m_root = nullptr;
        m_size = 0;
    }

    void add(std::vector<T> list) {
        if(list.isEmpty()) return;
        for (T element : list){
            add(element);
        }
    }

    void add(T* lest[]) {
        for (T element : lest){
            add(element);
        }
    }

    void add(CyclicLinkedList list) {
        if(list.isEmpty()) return;
        ListElement<T> *target =  list.m_root;
        ListElement<T> *current =  target->next;
        if(current == target){
            add(target);
        } else
        while (current!=target){
            add(current);
            current = current->next;
        }
    }

    void add(T num) {
        ListElement<T> *listElement = new ListElement<T>(num);

        if(isEmpty())
        {
            m_root = listElement;
            m_root->next = m_root;
        }
        else
        {
            ListElement<T> *current = m_root;
            while(current->next != m_root)
                current = current->next;
            current->next = listElement;
            current->next->next = m_root;
        }
        m_size++;
    }

    void remove(T i){
        if(isEmpty()) return;

        if(m_size == 1 && m_root->getData() == i) {
            m_root = nullptr;
            m_size--;
            return;
        }

        ListElement<T> *current = m_root->next;
        ListElement<T> *pre = m_root;

        if(m_root->getData() == i){
            while (current != m_root){
                pre = current;
                current = current->next;
            }
            pre->next = current->next;
            m_root = m_root->next;
            m_size--;
        }
        else {
            while (current != m_root){
                if(current->getData() == i){
                    pre->next = current->next;
                    m_size--;
                    return;
                }
                pre = current;
                current = current->next;
            }
        }
    };

    void removeByIndex(int i){
        if(isEmpty()) return;
        if(i%(m_size + 1) == 0){
            ListElement<T> *current = m_root->next;
            ListElement<T> *pre = m_root;
            while (current != m_root){
                pre = current;
                current = current->next;
            }
            pre->next = current->next;
            m_root = m_root->next;
            m_size--;
            return;
        }

        ListElement<T> *current = m_root;
        for(int j = 0; j < i-1; j++){
            current = current->next;
        }
        current->next = current->next->next;
        m_size--;
    };

    void insertInto(int i, T element){
        ListElement<T> *listElement = new ListElement<T>(element);
        if(isEmpty())
        {
            m_root = listElement;
            m_root->next = m_root;
            return;
        }
        ListElement<T> *current = m_root->next;
        if(i == 0){
            while (current->next != m_root){
                current = current->next;
            }
            listElement->next = current->next;
            current->next = listElement;
            m_root = listElement;

        }
        else {
            for(int j = 0; j < i-1; j++){
                current = current->next;
            }
            listElement->next = current->next;
            current->next = listElement;
        }
    };

    int getIndex(T data){
        if(isEmpty()) return -1;

        int result = 0;
        ListElement<T> *current = m_root;

        if(m_root->next == m_root) {
            if (current->getData() == data) {
                return 0;
            } else return -1;
        }

        while (current->next != m_root){
            if(current->getData() == data){
                return result;
            }
            result++;
            current = current->next;
        }
        return -1;
    };

    T get(int index){
        if(isEmpty()) return T();

        ListElement<T> *current = m_root;
        for(int i = 0; i < index; i++){
            current = current->next;
        }
        return current->getData();
    };

    bool isEmpty(){
        if(m_root == nullptr) return true;
        return false;
    }

    std::string toString(){
        if(isEmpty()) return "[]";

        ListElement<T> *current = m_root->next;
        std::string result = "[" + std::to_string(m_root->getData());
        while (current != m_root){
            result += " " + std::to_string(current->getData());
            current = current->next;
        }
        result += "]";
        return result;
    }

    int getSize(){
        return m_size;
    }

    class Iterator {
        friend class CyclicLinkedList<T>;
    protected:
        ListElement<T>* m_node;
        const CyclicLinkedList* m_list;
    public:
        Iterator() : m_node(nullptr), m_list(nullptr) {
        }
        Iterator(const CyclicLinkedList* list, ListElement<T>* node)
                : m_node(node), m_list(list) {
        }
        T& operator*() { return m_node->value; }
        bool operator!=(const Iterator& lhs) const {
            return *this != lhs;
        }
        bool operator==(const Iterator& lhs) const {
            return m_list == lhs.m_list && m_node == lhs.m_node;
        }
        Iterator next_it() const {
            if (m_node != nullptr)
                return Iterator(m_list, m_node->next);
            return *this;
        }
        Iterator& operator++() {
            if (m_node != nullptr)
                m_node = m_node->next;
            return *this;
        }
    };
};


#endif CPPTASK3_CYCLICLINKEDLIST_H