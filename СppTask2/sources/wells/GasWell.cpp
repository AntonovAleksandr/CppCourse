//
// Created by aleksandr on 18.02.2021.
//

#include "../../headers/wells/GasWell.h"
#include "../../WellType.h"

GasWell::GasWell(const std::string &name) : Borehole(name) {
    this->wellType = WellType::GAS;
}

GasWell::GasWell(const std::string &name, float volumeOfContent) : Borehole(name, volumeOfContent) {
    this->wellType = WellType::GAS;
}

GasWell::GasWell(const std::string &name, float volumeOfContent, bool workingStatus) : Borehole(name, volumeOfContent,
                                                                                                workingStatus) {
    this->wellType = WellType::GAS;
}
