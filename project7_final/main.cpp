/*
Will Garlington
CPSC 122, Profect 7
October 18, 2022
Program Description: This program creates and array of desired size
    and fills it with random numbers within the specified limit.
    This array is sorted via bubblesort and then seached for a target int.
    A message will be output stating the success or failure of the search.
    After, the sorted array will be written to an output file.

usage: ./a.out size limit target outFile
*/

#include "project7.h"

int main(int argc, char* argv[])
{
    int size = myAtio(argv[1]), limit = myAtio(argv[2]), target = myAtio(argv[3]);
    int* randArr = arrLoad(size, limit); //array made and filled
    string outFile = argv[4];
    
    //sorting
    bubbleSort(randArr, size);
    //searching
    binSrch(randArr, size, target);
    //sending to outFile
    arrToFile(randArr, size, outFile);

    return 0;
}