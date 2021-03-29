//
// Created by aleksandr on 18.02.2021.
//

#include "../../headers/wells/Borehole.h"
#include "../../WellType.h"

#include <utility>

void Borehole::start(float volume) {
    this->workingStatus = true;
    if(plan){
        historyOfVolume+= std::min(volume, plan);
        volumeOfContent+=std::min(volume, plan);
        plan-=std::min(volume, plan);
    }
}

void Borehole::stop() {
    this->workingStatus = false;
}

float Borehole::getVolume() {
    return this->volumeOfContent;
}

Borehole::Borehole(std::string name, float volumeOfContent, bool workingStatus) : name(std::move(name)),
                                                                                  volumeOfContent(
                                                                                          volumeOfContent),
                                                                                  workingStatus(workingStatus) {
    this->plan = 0;
    this->historyOfVolume = 0;
}

Borehole::Borehole(std::string name, float volumeOfContent) : name(std::move(name)),
                                                              volumeOfContent(volumeOfContent) {
    this->workingStatus = false;
    this->historyOfVolume = 0;
    this->plan = 0;
}

Borehole::Borehole(std::string name) : name(std::move(name)) {
    this->workingStatus = false;
    this->volumeOfContent = 0;
    this->historyOfVolume = 0;
    this->plan = 0;
}

void Borehole::setName(std::string name) {
    this->name = name;
}

std::string Borehole::getName() {
    return this->name;
}

WellType Borehole::getType() {
    return this->wellType;
}

bool Borehole::getStatus() {
    return this->workingStatus;
}

void Borehole::setPlan(float plan) {
    if (workingStatus) {
        volumeOfContent += plan;
        historyOfVolume += plan;
    } else {
        this->plan += plan;
    }
}
void Borehole::setVolume(float volume) {
    this->volumeOfContent = volume;
}

float Borehole::getPlan() {
    return plan;
}

std::string Borehole::toString() {
    std::string result = "";
    result+= "\n" + name + " volume of ";
    switch (wellType) {
        case WellType::INJECTION:
            result += "water: ";
            break;
        case WellType::OIL:
            result += "oil: ";
            break;
        case WellType::GAS:
            result += "gas: ";
            break;
    }
    result += std::to_string(volumeOfContent) + " plan: " + std::to_string(plan);

    if (workingStatus)
        result += " now well is working\n";
    else
        result += " now well is stopped\n";

    for (int i = 0; i < static_cast<int>(historyOfVolume/10); i++) {
        result += "[]";
    }
    return result;
}

Borehole::~Borehole() {

}
