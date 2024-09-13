# Computer Organization Assignment 2

Required Files: driver.cpp, assemblyCalculator.cpp, assemblyCalculator.h, Programming-Project-2.txt, makefile (for the assemblySim executable)


Main Overview: To run, first try ./assemblySim Programming-Project-2.txt. If that does not work, run the make clean command, then the make command and try again-- make sure that the txt file is spelled correctly.

The program works by reading the data from Programming-Project-2.txt with ifstream and storing data (operation names and operands) into assemblyCalculator objects. The default value for each flag (N and Z) for an assemblyCalculator object is 0. Each assemblyCalculator object is stored in the calculationsArr (an assemblyCalculator array) for constant-time access later. This is done with the readInstructions() function in the driver, which conveniently returns the number of instructions to run later. Since part 1, I have edited readInstructions() so that it accomodates the fact that the NOT operation only requires one operand.

We run and display the results of each operation with the runOperations() function, which displays instruction names, operand values, and results by iterating through calculationsArr. runOperations() calls the performCurrentOperation(), which runs the appropiate instruction (currentOpertation) on each assemblyCalculator object and returns the result.

Unlike part 1, we are dealing with multiple types of instructions (not just ADD). To make the bitwise operations a bit easier for me to handle, I typecasted the hex values as unsigned integers and just converted them back to hex for when I had to display the results back to the user. The exception to this is the ASR instruction, which handles the operands as being signed.



Command Breakdown (methods in assemblyCalculator.cpp):

performADD: adds operand1 and operand2 (unsigned) in a bitwise fashion (if either or both of bits are 1, resulting bit is 1; otherwise resulting bit is 0 -- also has carry) with +, returns sum (unsigned)

performAND: 'ands' operand1 and operand2 (unsigned) in a bitwise fashion (if both of the bits are 1, resulting but is 1; otherwise resulting bit is 0) with &, return result (unsigned)

performASR: arithmetically shifts operand 1 (signed) over right n times (operand2, int) (each bit is shifted to right by 1 and LSB bit is tossed out, MSB is filled w/ previous MSB) with >>, returns result (signed)

performLSR: logically shifts operand 1 (signed) over right n times (operand2, int) (each bit is shifted to right by 1 and LSB bit is tossed out, MSB is filled w/ 0) with >>, returns result (unsigned)

performLSL: logically shifts operand 1 (signed) over left n times (operand2, int) (each bit is shifted to left by 1 and MSB bit is tossed out, LSB is filled w/ 0) with <<, returns result (unsigned)

performNOT: 'nots' operand1 (unsigned) in a bitwise fashion (if a bit 0 is, then the resulting bit is 1, and vice versa) with ~, returns result (unsigned)

performORR: performs a bitwie OR oepration on operand1 and operand2 (unsigned) (if either of a certain bit or both are 1, then the resulting bit is 1) with |, returns result (unsigned)

performSUB: subtracts operand2 from operand1 (unsigned) in a bitwise fashion (just the reverse of adding) with -, returns result (unsigned)

performXOR: performs a bitwie XOR oepration on operand1 and operand2 (unsigned) (if either of a certain bit are 1 (exclusively one), then the resulting bit is 1) with ^, returns result (unsigned)



Changing N and Z flags (implemented in driver):

If the result (in hex) of an operation has an MSB greater than 7 (8-0), then it is negative and the N flag is set. If the result is equal to 0, then the result in zero and the Z flag is set. The N and Z flags are attributes of assemblyCalculator, and are accessible via getters and setters. N and Z flags are 0 by default for each instance of assemblyCalculator.
