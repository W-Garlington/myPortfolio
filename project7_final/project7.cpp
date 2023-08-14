/*
Will Garlington
CPSC 122, Project 7
*/

#include "project7.h"

/*
Function: sorts int array via bubble sort, calls sink function
inputs: int array, length of array
returns: none
*/
void bubbleSort(int arr[], int length){
    int pass = 0, bottom = length - 1;
    while(pass < length - 1)
    {
        sink(arr, bottom);
        bottom--;
        pass++;
    }
}

/*
Function: runs one "pass" of bubblesort on array
Inputs: array of interest, bottom of where to stop comparisons
Returns: none
*/
void sink(int arr[], int bottom)
{
    int i = 0;
    while(i < bottom)
    {
        if (arr[i] > arr[i+1])
        {
            shift(arr, i);
        }
        i++;
    }
}


/*
Function: switches information an array index with the index "above" it
Inputs: array with info, index of info to be switched
Returns: none
*/
void shift(int arr[], int cur)
{
    int nxt = cur + 1;
    int tmp = arr[cur];
    arr[cur] = arr[nxt];
    arr[nxt] = tmp;
}


/*
Function: searches an array of ints using binary search.
    outputs message upon finding or not finding target
Inputs: int* of array, size of array, target integer
Returns: index of target if found, or -1 if not found
*/
int binSrch(int* arr, int size, int target)
{
    int top = 0, bottom = size - 1;

    while(top <= bottom)
    {
        int idx = (top + bottom)/2;
        if (arr[idx] == target)
        {
            cout << "Integer '" << target << "' found" << endl;
            return idx;
        }
        if (target < arr[idx])
        {
            bottom = idx - 1;
        }
        else
        {
            top = idx + 1;
        }
    }
    cout << "Integer '" << target << "' not found" << endl;
    return -1;
}

/*
Function: fills and array with random numbers less than a specified limit.
    this function also creates the array by calling arrMake().
Inputs: size of array desired, limit of random numbers
Returns: int* pointing to pointer that points to array
*/
int* arrLoad(int size, int limit)
{
    srand(time(NULL));
    int* arr = arrMake(size);
    int i = 0;
    while(i < size)
    {
        arr[i] = rand() % limit + 1;
        i++;
    }
    return arr;
}

/*
Funtion: dynamically creates an array with each value equal
    to its index #, creates pointer to array
Inputs: size of array desired
Returns: int* pointing to array
*/
int* arrMake(int size)
{
    int* newArr = new int[size];
    for (int i = 0; i < size; i++)
    {
        newArr[i] = i;
    }
    return newArr;
}

/*
Function: creates and fills fileName with contents of arr
Inputs: array of ints, size of array, fileName as string
Returns: none
*/
void arrToFile(int* arr, int size, string fileName)
{
    fstream outFile; 
    int i = 0, line = 0; 
    fileOpen(outFile, fileName, 'w');

    while (i < size)
    {
        outFile << arr[i] << " ";
        if (arr[i] < 10) //adds space to even out text distribution in output file
        {
            outFile << " ";
        }
        line++;
        i++;
        if (line % 15 == 0)
        {
            outFile << endl;
        }
    }
    outFile.close();
}

/*
Function: opens file in read or wwrite mode depending on input
Inputs: fstream obj, string of fileName, character of mode ('w', 'r')
Returns: none
*/
void fileOpen(fstream& file, string name, char mode)
{
 string fileType;

 if (mode == 'r')
  fileType = "input";
 if (mode == 'w')
  fileType = "output";

 if (mode == 'r')
  file.open(name, ios::in);  //available thorugh fstream
 else
  if (mode == 'w')
   file.open(name, ios::out);  //available through fstream;

 if (file.fail()) //error condition 
 {
  cout << "Error opening " << fileType << " file" << endl; 
  exit(EXIT_FAILURE);
 }
}

/*
Function: returns integer value of cstring
Input: cstring
Returns: int value of input
*/
int myAtio(char str[])
{
    int numLen = myStrnlen(str);
    int numPower = myStrnlen(str) - 1; //starting exponent value
    int digit, value = 0;

    for (int i = 0; i < numLen; i++)
    {
        digit = str[i] - 48;
        value = digit * power(10, numPower) + value;
        numPower--;
    }
    return value;
}

/*
Function: finds value of base to power of exponent
Input: int base, int exponent
Returns: value of base^exp
*/
int power(int base, int exp)
{
 int value = 1;

 for (int i = 0; i < exp; i++)
    value = value * base;
 return value;
}

/*
Function: finds length of cstring
Input: cstring
Returns: int value of length
*/
int myStrnlen(char str[])
{
    int i = 0;

    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}