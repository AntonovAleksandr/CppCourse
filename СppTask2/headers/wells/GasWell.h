//
// Created by aleksandr on 18.02.2021.
//

#ifndef ___TASK2_GASWELL_H
#define ___TASK2_GASWELL_H


#include "Borehole.h"

class GasWell : public Borehole {
public:
    GasWell(const std::string &name);
    GasWell(const std::string &name, float volumeOfContent, bool workingStatus);
    GasWell(const std::string &name, float volumeOfContent);
};


#endif //___TASK2_GASWELL_H
