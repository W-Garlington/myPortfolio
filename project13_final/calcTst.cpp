/*
Author: Will Garlington, CPSC 122
Date Submitted: April 24, 2022
*/

#include <iostream>
using namespace std;

#include "calc.h"

int main(int argc, char* argv[])
{
    Calc* C = new Calc(argv[1]);
    C->DisplayInFix();
    C->DisplayPostFix();
    cout << C->Evaluate() << endl;
    //C->testing();
    cout << "Hello World" << endl;

    delete C;
    return 0;
}
