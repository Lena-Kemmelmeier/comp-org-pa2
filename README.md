# cs219-pa2

# CS 219 Programming Assignment 2

The following files are required to run the program: driver.cpp, assemblyCalculator.cpp, assemblyCalculator.h, Programming-Project-2.txt, makefile (for the assemblySim executable)

To run, first try ./assemblySim Programming-Project-2.txt. If that does not work, run the make clean command, then the make command and try again-- make sure that the txt file is spelled correctly.

The program works by reading the data from Programming-Project-2.txt with ifstream and storing data (operation names and operands) into assemblyCalculator objects. The default value for each flag (N and Z) for an assemblyCalculator object is 0. Each assemblyCalculator object is stored in the calculationsArr (an assemblyCalculator array) for constant-time access later. This is done with the readInstructions() function in the driver, which conveniently returns the number of instructions to run later. Since part 1, I have edited readInstructions() so that it accomodates the fact that the NOT operation only requires one operand.

We run and display the results of each operation with the runOperations() function, which displays instruction names, operand values, and results by iterating through calculationsArr. runOperations() calls the performCurrentOperation(), which runs the appropiate instruction (currentOpertation) on each assemblyCalculator object and returns the result.

Unlike part 1, we are dealing with multiple types of instructions (not just ADD). To make the bitwise operations a bit easier for me to handle, I typecasted the hex values as unsigned integers and just converted them back to hex for when I had to display the results back to the user. The exception to this is the ASR instruction, which handles the operands as being signed.

If there are any issues with my running my program please let me know! My github link is https://github.com/Lena-Kemmelmeier/cs219-pa2 if for any reason that is easier to access.