// Author: Lena Kemmelmeier
// Purpose: CS 219 PA1 (Summer '23) - hexadecimal addition calculator

#include "assemblyCalculator.h"

AssemblyCalculator::AssemblyCalculator(){ //sets default values
    firstOperand = 12;
    secondOperand = 12;
    currentOperation = "DEFAULT";
    N = 0;
    Z = 0;
}

AssemblyCalculator::AssemblyCalculator(string newOper, unsigned int newOperand1, unsigned int newOperand2, bool newN, bool newZ){
    currentOperation = newOper;
    firstOperand = newOperand1;
    secondOperand = newOperand2;
    Z = newZ;
    N  = newN;
}

AssemblyCalculator::AssemblyCalculator(const AssemblyCalculator& oldCalc){
    currentOperation = oldCalc.currentOperation;
    firstOperand = oldCalc.firstOperand;
    secondOperand = oldCalc.secondOperand;
    N = oldCalc.N;
    Z = oldCalc.Z;
}

// getters + setters
void AssemblyCalculator::setFirstOperand(const unsigned int newOperand1){
    firstOperand = newOperand1;
}

void AssemblyCalculator::setSecondOperand(const unsigned int newOperand2){
    secondOperand = newOperand2;
}

unsigned int AssemblyCalculator::getFirstOperand() const{
    return firstOperand;
}

unsigned int AssemblyCalculator::getSecondOperand() const{
    return secondOperand;
}

void AssemblyCalculator::setCurrentOperation(const string newOper){
    currentOperation = newOper;
}

string AssemblyCalculator::getCurrentOperation() const{
    return currentOperation;
}

void AssemblyCalculator::setZ(const bool newZ){
    Z = newZ;
}

bool AssemblyCalculator::getZ() const{
    return Z;
}

void AssemblyCalculator::setN(const bool newN){
    N = newN;
}

bool AssemblyCalculator::getN() const{
    return N;
}

// calculating behaviors . . . more to come

// performs the current operation - calls the appropiate instruction
unsigned int AssemblyCalculator::performCurrentOperation(){
    // unsigned int answer;
    string operation = getCurrentOperation();

    // Z and N are always set to 0 initally
    setN(0);
    setZ(0);

    if(operation == "ADD" || operation == "ADDS"){  
        return calculateSum();
    }
    else if(operation == "ASR" || operation == "ASRS"){
        return performASR();
    }
    else if(operation == "LSR" || operation == "LSRS"){ // call other instruction behaviors
        return performLSR();
    }
    else{
        return 12;
    }


}

// calculate the sum
unsigned int AssemblyCalculator::calculateSum(){
    return (firstOperand + secondOperand);
}

// perform arithmetic shift right
signed int AssemblyCalculator::performASR(){
    signed int shiftThis = firstOperand;
    int numShifts = secondOperand;
    signed int result = (shiftThis >> numShifts);

    return result;
}

unsigned int AssemblyCalculator::performLSR(){
    int numShifts = secondOperand;
    unsigned int result = (firstOperand >> numShifts);

    return result;
}

// checking for overflow with calculateSum()
bool AssemblyCalculator::isThereOverFlow(){
    bool hasOverflowOccured = false;
    unsigned int sum = calculateSum();

    // if the sum result is less than either of the two operands (unsigned), then overflow has occured
    if (sum < firstOperand || sum < secondOperand){
        return hasOverflowOccured = true;
    }
    return hasOverflowOccured;
}