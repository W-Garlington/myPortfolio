/*
Will Garlington
CPSC 121. April 14, 2022
PA 8 Assignment: Decoder
Function: This program will take a text file and encrypt the file using vectors.
There are two types of encryption availible, one in each function.
The function encrypt1 uses pairs of chars to replace input chars, the function encrypt2
uses four 6x6 vectors to encrypt the input using the four square method.
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

///This function uses a character replacement method to encrypt the message
void encrypt1();

///this function uses a foursquare method to encrypt the message
///this function has a limited range of characters that can be encrypted
///any ### symbols indicate a failure to properly encrypt
void encrypt2();

///this function decrypts encrypted files from the encrypt1 function
void decrypt1();

///this function decrypts the foursquare encryption from function encrypt2
void decrypt2();

///these functions are overloaded to accept char vectors and cout contents to terminal
void printVec(vector<vector<char>> inVec);
void printVec(vector<char> inVec);
