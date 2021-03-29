//
// Created by aleksandr on 18.02.2021.
//

#ifndef ___TASK2_OILWELL_H
#define ___TASK2_OILWELL_H


#include "Borehole.h"

class OilWell : public Borehole{
public:
    OilWell(const std::string &name, float volumeOfContent, bool workingStatus);

    OilWell(const std::string &name, float volumeOfContent);
    OilWell(const std::string &name);
};


#endif //___TASK2_OILWELL_H
