//
// Created by aleksandr on 25.02.2021.
//

#include <iostream>
#include "../../headers/printers/OilFieldPrinter.h"
#include "../../headers/printers/IBoreholePrinter.h"

void OilFieldPrinter::print(OilField oilField) {
    std::cout << "Summ water volume: " << oilField.getWaterVolume() << "\nSumm oil volume: "
              << oilField.getOilVolume() << "\nSumm gas volume: " << oilField.getGasVolume() << std::endl;
    std::cout << "Water plan: " << oilField.getWaterPlan() << "\nOil plan:  "
              << oilField.getOilPlan() << "\nGas plan: " << oilField.getGasPlan() << std::endl;
    if(!oilField.getWells().empty()) {
        for (Borehole borehole : oilField.getWells()) {
            m_iBoreholePrinter.print(borehole);
        }
    }
}

OilFieldPrinter::OilFieldPrinter(IBoreholePrinter iBoreholePrinter) {
    this->m_iBoreholePrinter = iBoreholePrinter;
}

OilFieldPrinter::OilFieldPrinter() {}
