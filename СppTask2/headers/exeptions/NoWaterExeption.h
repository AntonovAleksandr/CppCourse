//
// Created by aleksandr on 25.03.2021.
//

#ifndef ___TASK2_NOWATEREXEPTION_H
#define ___TASK2_NOWATEREXEPTION_H

class NoWaterExeption{

public:
    virtual std::string what() const throw()
    {
        return "We need mo water!\n";
    }
} nowaterex;

#endif //___TASK2_NOWATEREXEPTION_H
