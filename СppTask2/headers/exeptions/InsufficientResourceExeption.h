//
// Created by aleksandr on 25.03.2021.
//

#ifndef ___TASK2_INSUFFICIENTRESOURCEEXEPTION_H
#define ___TASK2_INSUFFICIENTRESOURCEEXEPTION_H


class InsefficientResourceExeption{
public:
    virtual std::string what() const throw()
    {
        return "insufficient resource!\n";

    }
} insresex;
#endif //___TASK2_INSUFFICIENTRESOURCEEXEPTION_H
