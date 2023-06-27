// Author: Lena Kemmelmeier
// Purpose: CS 219 PA1 (Summer '23) - hexadecimal addition calculator

#ifndef ASSEMBLY_CALCULATOR
#define ASSEMBLY_CALCULATOR

#include <iostream>
#include <string>
using namespace std;

class AssemblyCalculator{
    private:
        string currentOperation;
        unsigned int firstOperand, secondOperand;
        bool N, Z;

    public:
        //constructors
        AssemblyCalculator(); //default
        AssemblyCalculator(string newOper, unsigned int newOperand1, unsigned int newOperand2, bool newN, bool newZ); //parameterized
        AssemblyCalculator(const AssemblyCalculator& oldCalc); //copy
    
        // getters + setters
        void setFirstOperand(unsigned int newOperand1);
        void setSecondOperand(unsigned int newOperand2);
        unsigned int getFirstOperand() const;
        unsigned int getSecondOperand() const;

        void setCurrentOperation(string newOper);
        string getCurrentOperation() const;

        void setZ(bool newZ);
        bool getZ() const;
        void setN(bool newN);
        bool getN() const;

        // calculating behaviors . . . more to come
        unsigned int performCurrentOperation(); // performs the current operation, ex: calls getSum() and returns answer

        // void changeFlagsAcc();
        unsigned int calculateSum();
        bool isThereOverFlow();

};

#endif