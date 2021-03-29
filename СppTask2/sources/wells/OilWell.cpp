//
// Created by aleksandr on 18.02.2021.
//

#include "../../headers/wells/OilWell.h"
#include "../../WellType.h"

OilWell::OilWell(const std::string &name) : Borehole(name) {
    this->wellType = WellType::OIL;
}

OilWell::OilWell(const std::string &name, float volumeOfContent) : Borehole(name, volumeOfContent) {
    this->wellType = WellType::OIL;
}

OilWell::OilWell(const std::string &name, float volumeOfContent, bool workingStatus) : Borehole(name, volumeOfContent,
                                                                                                workingStatus) {
    this->wellType = WellType::OIL;
}
