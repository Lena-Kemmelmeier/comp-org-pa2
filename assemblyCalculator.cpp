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
void AssemblyCalculator::setFirstOperand(unsigned int newOperand1){
    firstOperand = newOperand1;
}

void AssemblyCalculator::setSecondOperand(unsigned int newOperand2){
    secondOperand = newOperand2;
}

unsigned int AssemblyCalculator::getFirstOperand() const{
    return firstOperand;
}

unsigned int AssemblyCalculator::getSecondOperand() const{
    return secondOperand;
}

void AssemblyCalculator::setCurrentOperation(string newOper){
    currentOperation = newOper;
}

string AssemblyCalculator::getCurrentOperation() const{
    return currentOperation;
}

void AssemblyCalculator::setZ(bool newZ){
    Z = newZ;
}

bool AssemblyCalculator::getZ() const{
    return Z;
}

void AssemblyCalculator::setN(bool newN){
    N = newN;
}

bool AssemblyCalculator::getN() const{
    return N;
}

// calculating behaviors . . . more to come

// performs the current operation - calls the appropiate instruction
unsigned int AssemblyCalculator::performCurrentOperation(){
    unsigned int answer;

    // make sure Z and N are always set to 0 initally
    setN(0);
    setZ(0);

    if((getCurrentOperation() == "ADD") || (getCurrentOperation() == "ADDS")){  
        return (answer = calculateSum());
    }
    else{ // call other instruction behaviors
        return answer;
    }


}

// calculate the sum
unsigned int AssemblyCalculator::calculateSum(){
    return (firstOperand + secondOperand);
}

// // change flags accordingly
// void AssemblyCalculator::changeFlagsAcc(){
//     if (currentOperation.back() == 'S'){ //if the instruction ends with an S

//     }
// }

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