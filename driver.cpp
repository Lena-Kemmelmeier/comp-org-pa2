// Author: Lena Kemmelmeier
// Purpose: CS 219 PA1 (Summer '23) - hexadecimal addition calculator

#include <fstream>
#include "assemblyCalculator.h"

int readOperationOperands(AssemblyCalculator* calcArr, string fileName); // reads in data into calcArr, returns how many lines (instructions) in txt there were
void runOperations(int numCals, AssemblyCalculator* calcArr); //runs the operations for all the calc objects in calcArr, displays outputs to user

int main(int argc, char* argv[]){ // include here that we need to run txt with file

    if (argc > 1){ //user must specifiy a file (here, Programming-Project-1.txt)
        int maxAdditions = 40; // this is just the mac number of operations (arbitrarily large-ish)
        AssemblyCalculator calculationsArr[maxAdditions];
        int numOperations = readOperationOperands(calculationsArr, argv[1]); //numOperations is our 'size' on our array
        runOperations(numOperations, calculationsArr);
    }
    else{
        return 1;
    }
    return 0;
}

void runOperations(int numCals, AssemblyCalculator* calcArr){
    bool wasThereOverflow; string overflowYesNo;
    unsigned int result;

    for (int i = 0; i < numCals; i++){
        // wasThereOverflow = calcArr[i].isThereOverFlow();

        // if (wasThereOverflow == true){
        //     overflowYesNo = "YES";
        // }
        // else{
        //     overflowYesNo = "NO";
        // }

        cout << calcArr[i].getCurrentOperation() << "   " << hex << showbase << uppercase << calcArr[i].getFirstOperand() << "  " << calcArr[i].getSecondOperand() << ": " << calcArr[i].performCurrentOperation() << endl;
        // cout << "Overflow:  " << overflowYesNo << endl;

        if ((calcArr[i].getCurrentOperation()).back() == 'S'){ // if the instruction ends in an S, set the flags
            //set the new value of the flags
            result = calcArr[i].performCurrentOperation();

            // get the first bit
            while(result >= 16){
                result = result/16;
            }
            // cout << result << endl;

            unsigned int test = 0;
            
            if(result > 7){
                // cout << "this result is negative!" << endl;
                calcArr[i].setN(1);
            }
            else if(calcArr[i].performCurrentOperation() > test){
                calcArr[i].setZ(1);
            }
            
        }

        cout << noshowbase << "N: " << calcArr[i].getN() << "   " << "Z: " << calcArr->getZ() << endl;
    }
}

int readOperationOperands(AssemblyCalculator* calcArr, string fileName){
    int numOperationsPerform = 0; //will increment as we read in from file - equal to the number of lines/instructions
    string operationToPerform; //these values are for the parameterized constructor
    unsigned int oper1, oper2; //these values are for the parameterized constructor

    ifstream file(fileName);

    if (file.is_open() == false){
        throw "could not find the file";
        return numOperationsPerform;
    }

    while(file >> operationToPerform >> hex >> oper1 >> hex >> oper2){ // read in the values from txt, make calc objects and store back into array
    // temp code here
        if ((operationToPerform == "ADDS") || (operationToPerform == "ADD")){
            calcArr[numOperationsPerform] = AssemblyCalculator(operationToPerform, oper1, oper2, 0, 0);
            numOperationsPerform++;
        }
    }
    file.close();
    return numOperationsPerform;
}