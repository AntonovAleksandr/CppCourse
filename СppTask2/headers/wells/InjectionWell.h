//
// Created by aleksandr on 18.02.2021.
//

#ifndef ___TASK2_INJECTIONWELL_H
#define ___TASK2_INJECTIONWELL_H


#include "Borehole.h"

class InjectionWell : public Borehole{
public:
    InjectionWell(const std::string &name);
    InjectionWell(const std::string &name, float volumeOfContent);
    InjectionWell(const std::string &name, float volumeOfContent, bool workingStatus);
};


#endif //___TASK2_INJECTIONWELL_H
