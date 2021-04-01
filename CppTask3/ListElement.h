//
// Created by aleksandr on 31.03.2021.
//

#ifndef CPPTASK3_LISTELEMENT_H
#define CPPTASK3_LISTELEMENT_H

template<typename T>
class ListElement {
private:
    T data;
    ListElement *next;
public:
    ListElement(T data){
        this->data = data;
        this->next = nullptr;
    }
};

#endif //CPPTASK3_LISTELEMENT_H
