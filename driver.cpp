// Author: Lena Kemmelmeier
// Purpose: CS 219 PA1 (Summer '23) - assembly simulator

#include <fstream>
#include "assemblyCalculator.h"

int readInstructions(AssemblyCalculator* calcArr, string fileName); // reads in data into calcArr, returns how many instructions total
void runOperations(int numCals, AssemblyCalculator* calcArr); //runs the operations for all the calc objects in calcArr, displays outputs to user

int main(int argc, char* argv[]){ // requires a file argument

    if (argc > 1){ //user must specifiy a file (here, Programming-Project-2.txt)
        int maxAdditions = 40; // this is just the max num of operations (arbitrarily large)
        AssemblyCalculator calculationsArr[maxAdditions];
        int numOperations = readInstructions(calculationsArr, argv[1]); //numOperations is the 'size' of our array
        runOperations(numOperations, calculationsArr);

        return 0;
    }
    return 1;
}

void runOperations(int numCals, AssemblyCalculator* calcArr){
    string operation;
    unsigned int result;

    for (int i = 0; i < numCals; i++){
        operation = calcArr[i].getCurrentOperation();
        result = calcArr[i].performCurrentOperation();

        // formatted output
        if(operation == "ASR" || operation == "ASRS" || operation == "LSR" || operation == "LSRS" || operation == "LSL" || operation == "LSLS"){
            cout << operation << "   " << hex << showbase << uppercase << calcArr[i].getFirstOperand() << "  " << noshowbase << calcArr[i].getSecondOperand() << ": "<< showbase << result << endl;
        }
        else if(operation == "NOT" || operation == "NOTS"){
            cout << operation << "   " << hex << showbase << uppercase << calcArr[i].getFirstOperand() << ": " << result << endl;
        }
        else{
            cout << operation << "   " << hex << showbase << uppercase << calcArr[i].getFirstOperand() << "  " << calcArr[i].getSecondOperand() << ": " << result << endl;
        }

        // if the instruction ends in an S, set the flags
        if (operation.back() == 'S'){

            // get the MSB
            while(result >= 16){
                result = result/16;
            }
            
            // set the N flag if the MSB is 1
            if(result > 7){
                calcArr[i].setN(1);
            }
            // set the Z flag if result is 0
            else if(result == 0){
                calcArr[i].setZ(1);
            }
            
        }

        // display flag values
        cout << noshowbase << "N: " << calcArr[i].getN() << "   " << "Z: " << calcArr[i].getZ() << endl;
    }
}

int readInstructions(AssemblyCalculator* calcArr, string fileName){
    int numOperationsPerform = 0; //will increment as we read in from file - equal to the number of lines/instructions
    string operation; //these values are for the parameterized constructor
    unsigned int oper1, oper2; //these values are for the parameterized constructor

    ifstream file(fileName);

    if (file.is_open() == false){
        throw "could not find the file";
        return numOperationsPerform;
    }

    while((file >> operation)){ // read in the values from txt, make calc objects and store back into array
        if (operation == "NOT" || operation == "NOTS"){ // NOT and NOTS only require one operand
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