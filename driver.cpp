// Author: Lena Kemmelmeier
// Purpose: CS 219 PA1 (Summer '23) - hexadecimal addition calculator

#include <fstream>
#include <sstream>
#include "assemblyCalculator.h"

int readOperationOperands(AssemblyCalculator* calcArr, string fileName); // reads in data into calcArr, returns how many lines (instructions) in txt there were
void runOperations(int numCals, AssemblyCalculator* calcArr); //runs the operations for all the calc objects in calcArr, displays outputs to user

int main(int argc, char* argv[]){ // include here that we need to run txt with file

    if (argc > 1){ //user must specifiy a file (here, Programming-Project-1.txt)
        int maxAdditions = 40; // this is just the mac number of operations (arbitrarily large-ish)
        AssemblyCalculator calculationsArr[maxAdditions];
        int numOperations = readOperationOperands(calculationsArr, argv[1]); //numOperations is our 'size' on our array
        runOperations(numOperations, calculationsArr);

        return 0;
    }
    return 1;
}

void runOperations(int numCals, AssemblyCalculator* calcArr){
    bool wasThereOverflow; string operation;
    unsigned int result;

    for (int i = 0; i < numCals; i++){
        operation = calcArr[i].getCurrentOperation();

        // formatted output
        if(operation == "ASR" || operation == "ASRS" || operation == "LSR" || operation == "LSRS" || operation == "LSL" || operation == "LSLS"){
            cout << operation << "   " << hex << showbase << uppercase << calcArr[i].getFirstOperand() << "  " << noshowbase << calcArr[i].getSecondOperand() << ": "<< showbase << calcArr[i].performCurrentOperation() << endl;
        }
        else{
            cout << operation << "   " << hex << showbase << uppercase << calcArr[i].getFirstOperand() << "  " << calcArr[i].getSecondOperand() << ": " << calcArr[i].performCurrentOperation() << endl;
        }

        if (operation.back() == 'S'){ // if the instruction ends in an S, set the flags
            //set the new value of the flags
            result = calcArr[i].performCurrentOperation();

            // get the first bit
            while(result >= 16){
                result = result/16;
            }
            // cout << result << endl;
            
            if(result > 7){
                calcArr[i].setN(1);
            }
            else if(result == 0){
                calcArr[i].setZ(1);
            }
            
        }

        cout << noshowbase << "N: " << calcArr[i].getN() << "   " << "Z: " << calcArr[i].getZ() << endl;
    }
}

int readOperationOperands(AssemblyCalculator* calcArr, string fileName){
    int numOperationsPerform = 0; //will increment as we read in from file - equal to the number of lines/instructions
    string operation; //these values are for the parameterized constructor
    unsigned int oper1, oper2; //these values are for the parameterized constructor

    ifstream file(fileName);

    if (file.is_open() == false){
        throw "could not find the file";
        return numOperationsPerform;
    }

    while((file >> operation)){ // read in the values from txt, make calc objects and store back into array
        if (operation == "NOT" || operation == "NOTS"){
            file >> hex >> oper1;
            calcArr[numOperationsPerform] = AssemblyCalculator(operation, oper1, -1, 0, 0);
        }
        else{
            file >> hex >> oper1 >> hex >> oper2;
            calcArr[numOperationsPerform] = AssemblyCalculator(operation, oper1, oper2, 0, 0);
        } 
        numOperationsPerform++;
    }

    file.close();
    return numOperationsPerform;
}