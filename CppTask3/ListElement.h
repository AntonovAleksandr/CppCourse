//
// Created by aleksandr on 31.03.2021.
//

#ifndef CPPTASK3_LISTELEMENT_H
#define CPPTASK3_LISTELEMENT_H

template<typename T>
class ListElement {
private:
    T m_data;

public:
    ListElement *next;
    ListElement(T data){
        this->m_data = data;
        this->next = nullptr;
    }
    T getData(){
        return m_data;
    }
};

#endif //CPPTASK3_LISTELEMENT_H
