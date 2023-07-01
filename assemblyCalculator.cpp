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

// calculating behaviors

// performs the current operation - calls the appropiate behavior
unsigned int AssemblyCalculator::performCurrentOperation(){
    string operation = getCurrentOperation();

    if (operation.back() == 'S'){ // treat operation as being the operation without the S
        operation = operation.substr(0, operation.size()-1);
    }

    if(operation == "ADD"){  
        return performADD();
    }
    if(operation == "AND"){
        return performAND();
    }
    if(operation == "ASR"){
        return performASR();
    }
    if(operation == "LSR"){
        return performLSR();
    }
    if(operation == "LSL"){
        return performLSL();
    }
    if(operation == "NOT"){
        return performNOT();
    }
    if (operation == "ORR"){
        return performORR();
    }
    if (operation == "XOR"){
        return performXOR();
    }
    if (operation == "SUB"){
        return performSUB();
    }
    return 12;
}

unsigned int AssemblyCalculator::performADD(){
    return firstOperand + secondOperand;
}

unsigned int AssemblyCalculator::performAND(){
    return firstOperand & secondOperand;
}

signed int AssemblyCalculator::performASR(){
    signed int shiftThis = firstOperand;
    int numShifts = secondOperand;

    return shiftThis >> numShifts;
}

unsigned int AssemblyCalculator::performLSR(){
    int numShifts = secondOperand;

    return firstOperand >> numShifts;
}

unsigned int AssemblyCalculator::performLSL(){
    int numShifts = secondOperand;

    return firstOperand << numShifts;
}

unsigned int AssemblyCalculator::performNOT(){
    return ~firstOperand;
}

unsigned int AssemblyCalculator::performORR(){
    return firstOperand | secondOperand;
}

unsigned int AssemblyCalculator::performSUB(){
    return firstOperand - secondOperand;
}

unsigned int AssemblyCalculator::performXOR(){
    return firstOperand ^ secondOperand;
}

// checking for overflow with performADD()
bool AssemblyCalculator::isThereOverFlow(){
    bool hasOverflowOccured = false;
    unsigned int sum = performADD();

    // if the sum result is less than either of the two operands (unsigned), then overflow has occured
    if (sum < firstOperand || sum < secondOperand){
        return hasOverflowOccured = true;
    }
    return hasOverflowOccured;
}