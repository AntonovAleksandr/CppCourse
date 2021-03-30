//
// Created by aleksandr on 30.03.2021.
//

#ifndef ___TASK2_NOBOREHOLEEXEPTION_H
#define ___TASK2_NOBOREHOLEEXEPTION_H
class NoBoreholeExeption{
public:
    virtual std::string what() const throw()
    {
        return "Borehole not found!\n";

    }
} nobex;
#endif //___TASK2_NOBOREHOLEEXEPTION_H
