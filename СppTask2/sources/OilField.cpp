//
// Created by aleksandr on 18.02.2021.
//

#include "../headers/OilField.h"
#include "../WellType.h"
#include "../headers/exeptions/NoWaterExeption.h"
#include "../headers/exeptions/RunOutResurseExeption.h"
#include "../headers/exeptions/InsufficientResourceExeption.h"
#include "../headers/exeptions/NoValumeExeption.h"
#include "../headers/exeptions/NoBoreholeExeption.h"
#include <algorithm>
#include <iostream>


OilField::OilField(float gasVolume, float voterVolume, float oilVolume) : gasVolume(gasVolume),
                                                                                                  waterVolume(
                                                                                                          voterVolume),
                                                                                                  oilVolume(oilVolume),
                                                                                                  wells(std::vector<Borehole>()) {
    this->totalVolume = waterVolume + gasVolume + oilVolume;
    this->gasPlan = 0;
    this->oilPlan = 0;
    this->waterPlan = 0;
    this->waterCoef = 0.8;
    this->oilCoef = 0.5;
    this->gasCoef = 0.05;
}

OilField::OilField() {
    this->wells = std::vector<Borehole>();
    this->waterVolume = 0;
    this->gasVolume = 0;
    this->oilVolume = 0;
    this->gasPlan = 0;
    this->oilPlan = 0;
    this->waterPlan = 0;
    this->waterCoef = 0.8;
    this->oilCoef = 0.5;
    this->gasCoef = 0.05;
}

std::vector<Borehole> OilField::getWells() {
    return wells;
}

float OilField::getGasVolume() {
    return this->gasVolume;
}

float OilField::getWaterVolume() {
    return this->waterVolume;
}

float OilField::getOilVolume() {
    return this->oilVolume;
}

void OilField::addWell(Borehole borehole) {
    correctVolume(borehole);
    wells.push_back(borehole);
}


void OilField::setPlan(std::string name, float plan) {
    if (wells.empty()) return;
    bool boreholeIsFound = false;
    for (int i = 0; i < wells.size(); i++) {
        if (wells[i].getName() == name) {
            boreholeIsFound = true;
            WellType type = wells[i].getType();
            if (WellType::GAS == type) {
                if (gasVolume >= gasPlan + plan) {
                    gasPlan += plan;
                    wells[i].setPlan(plan);
                } else {
                    try
                    {
                        throw insresex;
                    }
                    catch (InsefficientResourceExeption e)
                    {
                        std::cout << e.what() << '\n';
                    }
                }
            } else if (WellType::OIL == type) {
                if (oilVolume >= oilPlan + plan) {
                    oilPlan += plan;
                    wells[i].setPlan(plan);
                } else {
                    try
                    {
                        throw insresex;
                    }
                    catch (InsefficientResourceExeption e)
                    {
                        std::cout << e.what() << '\n';
                    }
                }
            } else if (WellType::INJECTION == type) {
                if (totalVolume >=  waterCoef * waterVolume + oilCoef * oilVolume + plan + gasPlan * gasCoef) {
                    waterPlan += plan;
                    wells[i].setPlan(plan);
                }
                else{
                    try
                    {
                        throw novex;
                    }
                    catch (NoValumeExeption e)
                    {
                        std::cout << e.what() << '\n';
                    }
                }
            }
            correctVolume( wells[i]);
        }
    }
}

void OilField::removeWell(std::string name) {
    if (wells.empty()) return;
    bool boreholeIsFound = false;
    for (int i = 0; i < wells.size(); i++) {
        if (wells[i].getName() == name) {
            boreholeIsFound = true;
            wells.erase(wells.begin() + i);
            i--;
        }
    }
    if(!boreholeIsFound){
        try
        {
            throw nobex;
        }
        catch (NoBoreholeExeption e)
        {
            std::cout << e.what() << '\n';
        }
    }
}

void OilField::stopWell(std::string name) {
    if (wells.empty()) return;
    bool boreholeIsFound = false;
    for (int i = 0; i < wells.size(); i++) {
        if (wells[i].getName() == name) {
            boreholeIsFound = true;
            wells[i].stop();
        }
    }
    if(!boreholeIsFound){
        try
        {
            throw nobex;
        }
        catch (NoBoreholeExeption e)
        {
            std::cout << e.what() << '\n';
        }
    }
}

void OilField::startWell(std::string name) {
    if (wells.empty()) return;
    bool boreholeIsFound = false;
    for (int i = 0; i < wells.size(); i++) {
        if (wells[i].getName() == name) {
            boreholeIsFound = true;
            if (wells[i].getType() == WellType::OIL) {
                if(waterPlan > 0) {
                    wells[i].start(std::min(waterPlan, wells[i].getPlan()));
                }
                else{
                    try
                    {
                        throw nowaterex;
                    }
                    catch (NoWaterExeption e)
                    {
                        std::cout << e.what() << '\n';
                    }
                }
            }else{
                wells[i].start(wells[i].getPlan());
            }
            correctVolume(wells[i]);
        }
    }
    if(!boreholeIsFound){
        try
        {
            throw nobex;
        }
        catch (NoBoreholeExeption e)
        {
            std::cout << e.what() << '\n';
        }
    }
}

void OilField::correctVolume(Borehole borehole) {
    float gas = 0, oil = 0, water = 0;
    if (WellType::GAS == borehole.getType()) {
        gas = borehole.getVolume();
        borehole.setVolume(0);
        borehole.setPlan(borehole.getPlan() - gas);
        gasPlan -= gas;
    } else if (WellType::OIL == borehole.getType()) {
        oil = borehole.getVolume();
        borehole.setVolume(0);
        borehole.setPlan(borehole.getPlan() - gas);
        oilPlan -= oil;
    } else if (WellType::INJECTION == borehole.getType()) {
        water += borehole.getVolume();;
        borehole.setVolume(0);
        borehole.setPlan(borehole.getPlan() - water);
        waterPlan -= water;
    }
    this->oilVolume -= oil;
    this->gasVolume -= gas;
    this->waterVolume += water;
}


std::vector<Borehole> OilField::selectByName(std::string name) {
    std::vector<Borehole> result;
    for (Borehole borehole : wells) {
        if (borehole.getName() == name) {
            result.push_back(borehole);
        }
    }
    return result;
}

float OilField::getGasPlan() {
    return this->gasPlan;
}

float OilField::getOilPlan() {
    return this->oilPlan;
}


float OilField::getWaterPlan() {
    return this->waterPlan;
}
