//
// Created by aleksandr on 27.03.2021.
//

#ifndef ___TASK2_NOVALUMEEXEPTION_H
#define ___TASK2_NOVALUMEEXEPTION_H
class NoValumeExeption{
public:
    virtual std::string what() const throw()
    {
        return "No volume for water!\n";

    }
} novex;
#endif //___TASK2_NOVALUMEEXEPTION_H
