/*
Author: Will Garlington, CPSC 122
Date Submitted: April 24, 2022
*/

#include <iostream>
using namespace std;

#include "calc.h"
#include <cstring>

Calc::Calc(char* argvIn)
{
    stk = new Stack();//Write functions in this order.  Constructor and destructor will be built as the
    //functions it invokes are written
    len = myStrnlen(argvIn);
    inFix = argvIn;
    MakeValueTbl();
    if (CheckTokens() && CheckParens())
    {}
    else
    {
        cout << "checkFailure" << endl;
        exit(EXIT_FAILURE);
    }
    Parse();
    InFixToPostFix();
}

Calc::~Calc()
{
    delete valueTbl;
    delete stk;
    delete inFix;
    delete postFix;
}

bool Calc::CheckTokens()
{
    int i = 0;
    bool check = false;
    while(inFix[i] != '\0')
    {
        if (inFix[i] == '(' || inFix[i] == ')' || inFix[i] == '+' || inFix[i] == '-' || inFix[i] == '*')
        {
            check = true;
        }
        else if (inFix[i] > 46 && inFix[i] < 58)
        {
            check = true;
        }
        else if (inFix[i] > 64 && inFix[i] < 91)
        {
            check = true;
        }
        i++;
    }
    if (check)
    {
        return true;
    }
    return false;
}

void Calc::MakeValueTbl()
{
    valueTbl = new int[26];
    for (int i = 0; i < 26; i++)
    {
        valueTbl[i] = 0;
    }
    valueIdx = 0;
}

void Calc::Parse()
{
    int i = 0; int j = 0; int k = 0;
    char letter = ' ';
    results* valTbl = AddToValueTbl(inFix);
    char* tmp = inFix;
    inFix = new char[len];
    while(tmp[i] != '\0')
    {
        if (tmp[i] == '(' || tmp[i] == ')' || tmp[i] == '+' || tmp[i] == '-' || tmp[i] == '*' || tmp[i] == '/')
        {
            inFix[j] = tmp[i];
            j++; i++;
        }
        if (tmp[i] > 47 && tmp[i] < 58)
        {
            letter = valueIdx + 65;
            inFix[j] = letter;
            valueTbl[valueIdx] = valTbl->items[k];
            valueIdx++;
            k++; j++;
            while (tmp[i] != '(' && tmp[i] != ')' && tmp[i] != '+' && tmp[i] != '-' && tmp[i] != '*' && tmp[i] != '/')
            {
                i++;
            }
        }
    }
}

results* Calc::AddToValueTbl(char* expression)
{
    char* ptr;
    char* str = new char[strlen(expression) + 1]; //redundant?
    strcpy(str, expression);
    int* tokens = new int[26];
    char delimiters[] = " ()+-*/"; //tokens used in arithmetic expressions

    int i = 0;
    ptr = strtok(str,delimiters);
    while (ptr != NULL)
    {
        tokens[i] = atoi(ptr); 
        ptr = strtok(NULL,delimiters);
        i++;
    }
    results* nums = new results;
    nums->len = i;
    nums->items = tokens;
    return nums; 
}

bool Calc::CheckParens()
{
    int i = 0;
    while (inFix[i] != '\0')
    {
        if (inFix[i] == 40)
        {
            stk->Push(i);
        }
        if (inFix[i] == 41)
        {
            if (stk->IsEmpty())
            {
                return false;
            }
            stk->Pop();
        }
        i++;
    }
    if (stk->IsEmpty())
    {
        return true;
    }
    return false;
}

void Calc::DisplayInFix()
{
    int i = 0;
    while(inFix[i] != '\0')
    {
        cout << inFix[i];
        i++;
    }
    cout << endl;
}

void Calc::InFixToPostFix()
{
    int i = 0; int j = 0;
    postFix = new char[myStrnlen(inFix)];
    while (inFix[i] != '\0')
    {
        if (inFix[i] > 64 && inFix[i] < 91)
        {
            postFix[j] = inFix[i];
            j++;
        }
        if (inFix[i] == '+' || inFix[i] == '-' || inFix[i] == '*' || inFix[i] == '/')
            stk->Push(inFix[i]);
        if (inFix[i] == ')')
        {
            postFix[j] = stk->Peek();
            stk->Pop();
            j++;
        }
        i++;
    }
    emptyStk();
}

void Calc::DisplayPostFix()
{
    int i = 0;
    while (postFix[i] != '\0')
    {
        cout << postFix[i];
        i++;
    }
    cout << endl;
}

int Calc::Evaluate()
{
    bool cont = true;
    int i = 0, answer = 0;
    int var1 = 0, var2 = 0;
    //testing();                            //////// WHEN USING MANY #'s ex. 1+2+3+4+5 : ONLY USES LAST TWO VARS THEN QUITS
                                            //////// TRY USING SECOND stack FOR ANSWER PUSHES?
    while (postFix[i] != '\0')
    {
        if (postFix[i] > 64 && postFix[i] < 91)
            stk->Push(postFix[i]);
        if (postFix[i] == '+')
        {
            if (stk->IsEmpty())
            {
                cout << "checkFailure - '+'" << endl;
                exit(EXIT_FAILURE);
            }
            if (isalpha(stk->Peek()))
            {
                var2 = valueTbl[stk->Peek() - 65]; stk->Pop();
                var1 = valueTbl[stk->Peek() - 65]; stk->Pop();
                answer = var1 + var2;
            }
            else
            {
                var2 = stk->Peek(); stk->Pop();
                var1 = stk->Peek(); stk->Pop();
                answer = var1 + var2;
            }
            stk->Push(answer);
        }
        if (postFix[i] == '-')
        {
            if (stk->IsEmpty())
            {
                cout << "checkFailure - '-'" << endl;
                exit(EXIT_FAILURE);
            }
            if (isalpha(stk->Peek()))
            {
                var2 = valueTbl[stk->Peek() - 65]; stk->Pop();
                var1 = valueTbl[stk->Peek() - 65]; stk->Pop();
                answer = var1 - var2;
            }
            else
            {
                var2 = stk->Peek(); stk->Pop();
                var1 = stk->Peek(); stk->Pop();
                answer = var1 - var2;
            }
            stk->Push(answer);
        }
        if (postFix[i] == '*')
        {
            if (stk->IsEmpty())
            {
                cout << "checkFailure - *" << endl;
                exit(EXIT_FAILURE);
            }
            if (isalpha(stk->Peek()))
            {
                var2 = valueTbl[stk->Peek() - 65]; stk->Pop();
                var1 = valueTbl[stk->Peek() - 65]; stk->Pop();
                answer = var2 * var1;
            }
            else
            {
                var2 = stk->Peek(); stk->Pop();
                var1 = stk->Peek(); stk->Pop();
                answer = var1 * var2;
            }
            stk->Push(answer);
        }
        if (postFix[i] == '/')
        {
            if (stk->IsEmpty())
            {
                cout << "checkFailure - /" << endl;
                exit(EXIT_FAILURE);
            }
            if (isalpha(stk->Peek()))
            {
                var2 = valueTbl[stk->Peek() - 65]; stk->Pop();
                var1 = valueTbl[stk->Peek() - 65]; stk->Pop();
                answer = var2 / var1;
            }
            else
            {
                var2 = stk->Peek(); stk->Pop();
                var1 = stk->Peek(); stk->Pop();
                answer = var1 / var2;
            }
            stk->Push(answer);
        }
        i++; cont = true;
    }
    return answer;
}

int Calc::myStrnlen(char str[])
{
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}

void Calc::emptyStk()
{
    bool i = true;
    if (stk->IsEmpty())
        i = false;
    while (i)
    {
        stk->Pop();
        if (stk->IsEmpty())
            i = false;
    }
}

void Calc::testing()
{
    cout << "this is inside" << endl;


    if (stk->IsEmpty())
    {
        cout << "its fucking empty" << endl;
    }
    else
    {
        cout << "mission failed" << endl;
    }
    int test = 69;
    stk->Push(test);
    cout << stk->Peek() << "#" << endl;


    // valueTbl[valueIdx] = 6969;
    // valueIdx++;
    // for (int i = 0; i < 26; i++)
    // {
    //     cout << valueTbl[i] << endl;
    // }

}
