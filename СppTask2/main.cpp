#include <iostream>
#include "headers/OilFieldManager.h"
#include "headers/wells/GasWell.h"
//Antonov Aleksandr Aleksandrvich
//Нефтяное месторождение. Месторождению принадлежат скважины, скважины бывают трех видов - нефтяные, газовые, нагнетательные (для закачки воды в пласт).
// Месторождение оперерует параметрами: объем газа в месторождении, объем нефти, объем воды. У каждой скважины есть параметр – объем выкаченного
// или закаченного содержимого. Задача заключается в моделировании работы месторождения. Предполагается интерфейс для задания параметров месторождения,
// добавления/удаления скважин, задания параметром каждой скважины, а также включения/выключения ее работы.

int main(int argc, char *argv[]) {
    IBoreholePrinter iBoreholePrinter;
    OilFieldManager oilFieldManager = OilFieldManager(100, 100, 100, iBoreholePrinter);
    oilFieldManager.startSimulation();

    return 0;
}

