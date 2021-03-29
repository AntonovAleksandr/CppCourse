//
// Created by aleksandr on 18.02.2021.
//

#ifndef ___TASK2_BOREHOLE_H
#define ___TASK2_BOREHOLE_H

//#ifndef ___TASK2_OILFIELD_H
//#define ___TASK2_OILFIELD_H
//#endif
#include <string>
#include "../../WellType.h"

class Borehole {
protected:
    std::string name;
    WellType wellType;
    float volumeOfContent;
    float historyOfVolume;
    float plan;
    bool workingStatus;
public:
    Borehole(std::string name);
    virtual ~Borehole();
    Borehole(std::string name, float volumeOfContent);
    Borehole(std::string name, float volumeOfContent, bool workingStatus);

    void start(float volume);
    void stop();
    void setName(std::string name);
    void setPlan(float plan);
    void setVolume(float  volume);
    bool getStatus();
    float getVolume();
    float getPlan();
    WellType getType();
    std::string getName();
    std::string toString();
};


#endif //___TASK2_BOREHOLE_H
