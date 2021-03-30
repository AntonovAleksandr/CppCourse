//
// Created by aleksandr on 28.02.2021.
//

#include <iostream>
#include "../headers/OilFieldManager.h"
#include "../headers/wells/OilWell.h"
#include "../headers/wells/InjectionWell.h"
#include "../headers/wells/GasWell.h"
#include "../headers/printers/OilFieldPrinter.h"

void OilFieldManager::startManagement() {
    std::string answer, name;
    float plan = 0;
    std::cout << "Enter the name of borehole to set plan: ";
    std::cin >> name;
    std::cout << "Enter the plan: ";
    std::cin >> plan;
    oilField_.setPlan(name, plan);
    std::vector<Borehole> result = oilField_.selectByName(name);
    iBoreholePrinter.print(result);
}

void OilFieldManager::addNewWells() {
    bool isUnCorrect = false;
    std::string answer, name;
    int type = 0;
    std::cout << "Enter the name of new borehole: ";
    std::cin >> name;
    do {
        std::cout << "Enter the wellType of new borehole (1-Oil well  2-Injection well 3-Gas well): ";
        std::cin >> type;
        switch (type) {
            case 1: {
                this->oilField_.addWell(OilWell(name));
                break;
            }
            case 2: {
                this->oilField_.addWell(InjectionWell(name));
                break;
            }
            case 3: {
                this->oilField_.addWell(GasWell(name));
                break;
            }
            default: {
                isUnCorrect = true;
                break;
            }
        }
    } while (isUnCorrect);
}

void OilFieldManager::removeWells() {
    std::string answer, name;
    int id = -1;
    std::cout << "Enter the name of removing borehole: ";
    std::cin >> name;
    std::vector<Borehole> result = oilField_.selectByName(name);
    iBoreholePrinter.print(result);
    std::cout << "Enter the id: ";
    std::cin >> id;
    if (!result.empty() && result.size() > id && id > -1) {
        result.erase(result.cbegin() + id);
    }
}

void OilFieldManager::stopWells() {
    std::string answer, name;
    std::cout << "Enter the name of borehole to stop it: ";
    std::cin >> name;
    std::vector<Borehole> result = oilField_.selectByName(name);
    iBoreholePrinter.print(result);
    oilField_.stopWell(name);
}

void OilFieldManager::startWells() {
    std::string answer, name;
    std::cout << "Enter the name of borehole to start it: ";
    std::cin >> name;
    std::vector<Borehole> result = oilField_.selectByName(name);
    iBoreholePrinter.print(result);
    oilField_.startWell(name);
}

void OilFieldManager::printAllWells() {
    oilFieldPrinter.print(oilField_);
}

OilFieldManager::OilFieldManager(IBoreholePrinter iBoreholePrinter) {
    this->oilField_ = OilField();
    this->oilFieldPrinter = OilFieldPrinter(iBoreholePrinter);
    this->iBoreholePrinter = iBoreholePrinter;
}

OilFieldManager::OilFieldManager(float gas, float oil, float water, IBoreholePrinter iBoreholePrinter) {
    this->oilField_ = OilField(gas, oil, water);
    this->oilFieldPrinter = OilFieldPrinter(iBoreholePrinter);
    this->iBoreholePrinter = iBoreholePrinter;
}

void OilFieldManager::startSimulation() {
    bool isTheEnd = false;
    int i;
    while (!isTheEnd) {
        showMenu();
        std::cin >> i;
        switch (i) {
            case 1:
                printAllWells();
                break;
            case 2:
                startWells();
                break;
            case 3:
                stopWells();
                break;
            case 4:
                addNewWells();
                break;
            case 5:
                removeWells();
                break;
            case 6:
                startManagement();
                break;
            case 7:
                isTheEnd = true;
                break;
        }
    }
}

void OilFieldManager::showMenu() {
    std::cout << "Choose an operation: 1 - Show wells   : 2 - Start wells : 3 - Stop wells\n"
                 "                     4 - Add new well : 5 - Remove well : 6 - Set plan\n"
                 "                                      : 7 - End of simulation\n" << std::endl;
}

OilFieldManager::OilFieldManager(OilField oilField, IBoreholePrinter iBoreholePrinter1) {
    this->oilField_ = oilField;
    this->iBoreholePrinter = iBoreholePrinter1;
    this->oilFieldPrinter = OilFieldPrinter(iBoreholePrinter1);
}
