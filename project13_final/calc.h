/*
Name: Will Garlington
Class: CPSC 122, Section 1
Proffessor: Dr. De Palma
Date Submitted: April 24, 2022 
Description: Part 2 of Calculator Assignment 
To Compile: make
To Execute: ./calc "(121+12)"
*/

#ifndef CALC
#define CALC

#include "stack2.h"

struct results
{
      int* items;
      int len;
};

class Calc 
{ 
      public: 
      /* 
      pre: argvIn is a pointer to the C-String entered at the command line
      post: 
            functions invoked:
                  CheckTokens
                  MakeValueTbl
                  Parse
                  CheckParens
                  InFixToPostFix

            if a boolean function returns false, a relevant error is displayed. Execution
            is halted with this function: exit(EXIT_FAILURE) 
      */
      Calc(char* argvIn);

      /* 
      pre: an instance of Cals exists 
      post: dynamically declared memory is returned to the stack 
      */
      ~Calc();

      /*
      pre: instance of Calc exists 
      post: constructed infix expression is displayed
      */
      void DisplayInFix();

      /*
      pre: instance of Calc exists
      post: postfix exression displayed
      */
      void DisplayPostFix();

      /*
      pre: instance of Calc exists
      post: value of expression input at the command line is computed and returned.
            technique is that described in class.
      */
      int Evaluate();






      void testing();







      private:
      /*
      Note: Use C-string functions, like isalpha, isupper, isdigit 
            Use charcter notation rather than ascii values, e.g., '(' rather than 40
      pre:  invoked from constructor 
      post: returns true if each character in argv[1] is:
                  either: one of the four arithmetic operators
                  or: an upper case alphabetic character
                  or: a character digit (0..9)
                  or: a left or right parenthsis
            returns false otherwise	
      */
      bool  CheckTokens();

      /*
      pre:  invoked from constructor 
      post: 26 position valueTbl is dyanically allocated and filled with zeroes  
            valueIdx is set to 0
      */
      void MakeValueTbl(); 
  
      /*
      pre:  invoked from constructor 
      post: 1. space for inFix expression is dynamically allocated 
	      2. inFix is a copy of argv[1] except:
                  Beginning with 'A', upper case alphabetic characters are substituted for digit 
	            strings. Numbers corresponding to digit strikngs are stored in valueTbl. 
	            valueIdx is appropriately incremented..	  
      */
      void Parse();

      results* AddToValueTbl(char* expression);

      /* 
      pre:  invoked from Parse 
      post: Returns the index of the final digit in a digit string.  See Parse, above. 
      */ 
      int FindLast(int cur);
  
      /* 
      pre:  invoked from constructor
      post: Using the stack technique discussed in class, returns true 
            if parentheses are balanced, false otherwise
      */
      bool CheckParens();
      /*
      pre: instance of Calc exists.  All tokens are legal and parens are balanced.
      post: postFix points to a dynamically declared array holding the postfix version
            of the the input infix expression.
      */
      void InFixToPostFix();
  
      /*
      pre: null terminated char string exists
      post: returns length of string
      */
      int myStrnlen(char str[]);

      /*
      pre: stk exisits
      post: stk is empty
      */
      void emptyStk();


      char*  inFix;     //null-terminated string that holds infix expression 
      char*  postFix;   //null-terminated string that holds postfix expression 
      int*  valueTbl;   //pointer to an array holding variable and expression values 
      int valueIdx;    //index of the next available position in valueTbl
      int len;        //length of argv1
      Stack* stk;
};
#endif 
