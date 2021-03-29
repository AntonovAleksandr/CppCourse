//
// Created by aleksandr on 28.02.2021.
//

#ifndef ___TASK2_OILFIELDMANAGER_H
#define ___TASK2_OILFIELDMANAGER_H
#include "OilField.h"
#include "printers/IBoreholePrinter.h"
#include "printers/OilFieldPrinter.h"

class OilFieldManager {
private:
    OilField oilField_;
    IBoreholePrinter iBoreholePrinter;
    OilFieldPrinter oilFieldPrinter;


    std::vector<Borehole> selectByName(std::string name);
    void printAllWells();
    void addNewWells();
    void removeWells();
    void stopWells();
    void startWells();
    void showMenu();
    void startManagement();


public:
    OilFieldManager(IBoreholePrinter iBoreholePrinter1);
    OilFieldManager(OilField oilField, IBoreholePrinter iBoreholePrinter1);
    OilFieldManager(float gas, float oil, float water, IBoreholePrinter iBoreholePrinter);
    void startSimulation();
};


#endif //___TASK2_OILFIELDMANAGER_H
