cmake_minimum_required(VERSION 3.17)
project(___Task2)

set(CMAKE_CXX_STANDARD 14)

add_executable(___Task2 main.cpp sources/OilField.cpp headers/OilField.h sources/wells/Borehole.cpp headers/wells/Borehole.h sources/wells/OilWell.cpp headers/wells/OilWell.h sources/wells/GasWell.cpp headers/wells/GasWell.h sources/wells/InjectionWell.cpp headers/wells/InjectionWell.h sources/printers/OilFieldPrinter.cpp headers/printers/OilFieldPrinter.h sources/printers/IBoreholePrinter.cpp headers/printers/IBoreholePrinter.h sources/OilFieldManager.cpp headers/OilFieldManager.h WellType.h headers/exeptions/RunOutResurseExeption.h headers/exeptions/NoWaterExeption.h headers/exeptions/InsufficientResourceExeption.h headers/exeptions/NoValumeExeption.h)