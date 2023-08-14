/*
Will Garlington
CPSC 122, Project 5
Purpose: this program takes a file of text and outputs
a file with each line sorted by alphabetical order
using an array of strings and bubblesort.
use: ./a.out inFileName outFileName
*/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void bubbleSort(string arr[], int numLines);
void sink(string arr[], int bottom);
void shift(string arr[], int cur);
int makeUnarr(string arr[], string file);
void makeSrtarr(string arr[], string file, int length);
void fileOpen(fstream&, string, char);

int main(int argc, char* argv[])
{
    string array[100];
    string inFile = argv[1], outFile = argv[2];
    int length = makeUnarr(array, inFile);
    bubbleSort(array, length);
    makeSrtarr(array, outFile, length);

    return 0;
}

/*
Function: sorts string array via bubble sort, calls sink function
inputs: string array, length of array
returns: none
*/
void bubbleSort(string arr[], int length){
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
void sink(string arr[], int bottom)
{
    int i = 0;
    while(i < bottom)
    {
        if (arr[i].compare(arr[i+1]) > 0)
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
void shift(string arr[], int cur)
{
    int nxt = cur + 1;
    string tmp = arr[cur];
    arr[cur] = arr[nxt];
    arr[nxt] = tmp;
}

/*
Function: takes txt from input file into array
one line at a time
Inputs: empty array, input fileName
Returns: length of array as integer
*/
int makeUnarr(string arr[], string file)
{
    fstream inFile;
    int length = 0;
    fileOpen(inFile, file, 'r');
    while(getline(inFile, arr[length]))
    {
        length++;
    }
    inFile.close();
    return length;
}

/*
Function: puts the sorted array into an output file
Inputs: sorted array, output fileName, length of array
Returns: none
*/
void makeSrtarr(string arr[], string file, int length)
{
    fstream outFile;
    fileOpen(outFile, file, 'w');
    for (int i = 0; i < length; i++)
    {
        outFile << arr[i] << endl;
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