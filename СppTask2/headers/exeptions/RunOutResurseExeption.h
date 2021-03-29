//
// Created by aleksandr on 25.03.2021.
//

#ifndef ___TASK2_RUNOUTRESURSEEXEPTION_H
#define ___TASK2_RUNOUTRESURSEEXEPTION_H


#include <iostream>

class RunOutResurseExeption{
public:
    virtual std::string what() const throw()
    {
//        switch (wellType) {
//            case WellType::OIL:
//                return "The oil has run out!";
//            case WellType::GAS:
//                return "The gas has run out!";
//            default:
                return "The resurse has run out!\n";

    }
} runoutresex;
#endif //___TASK2_RUNOUTRESURSEEXEPTION_H
