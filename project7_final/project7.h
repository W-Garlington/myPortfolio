/*
Will Garlington
CPSC 122, Project 7
*/

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h> // for rand
#include <time.h> // for time
#include <cstdlib> //for abs()

using namespace std;

void bubbleSort(int* arr, int length);
void sink(int arr[], int bottom);
void shift(int arr[], int cur);
int binSrch(int* arr, int size, int target);
int* arrLoad(int size, int limit);
int* arrMake(int size);
void arrToFile(int* arr, int size, string fileName);
void fileOpen(fstream&, string, char);
int myAtio(char str[]);
int power(int base, int exp);
int myStrnlen(char str[]);


