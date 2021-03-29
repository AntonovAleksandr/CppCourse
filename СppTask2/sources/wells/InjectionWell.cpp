//
// Created by aleksandr on 18.02.2021.
//

#include "../../headers/wells/InjectionWell.h"
#include "../../WellType.h"

InjectionWell::InjectionWell(const std::string &name) : Borehole(name) {
    this->wellType = WellType::INJECTION;
}

InjectionWell::InjectionWell(const std::string &name, float volumeOfContent) : Borehole(name, volumeOfContent) {
    this->wellType = WellType::INJECTION;
}

InjectionWell::InjectionWell(const std::string &name, float volumeOfContent, bool workingStatus) : Borehole(name,
                                                                                                            volumeOfContent,
                                                                                                            workingStatus) {
    this->wellType = WellType::INJECTION;
}
