#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <stack>
#include <string.h>

using namespace std;

bool checkOperator(char ch)
{
    if (ch=='+' || ch=='-' || ch=='*' || ch=='/')
        return true;
    else
        return false;
}

int operation(int operandA, int operandB, char op)
{
    int result;
    switch(op)
	{
    case '+':
        result = operandB + operandA;
        break;
    case '-':
        result = operandB - operandA;
        break;
    case '*':
        result = operandB * operandA;
        break;
    case '/':
        result = operandB / operandA;
        break;
    }
    return result;
}


int main()
{
    char exp[1000], buffer[15];
    int i,operandA, operandB, len, j, x;
    stack<int> s;
    cout<<"Enter a Postfix Expression: ( e.g. 23 34 * )\n";
    gets(exp);
    len = strlen(exp);
    j = 0;
    for(i=0; i<len;i++)
	{
        if(exp[i]>='0' && exp[i]<='9')
		{
            buffer[j++] = exp[i];
        }
        else if(exp[i]==' ')
		{
            if(j>0)
			{
                buffer[j] = '\0';
                x = atoi(buffer);
                s.push(x);
                j = 0;
            }
        }
        else if(checkOperator(exp[i]))
		{
            operandA = s.top();
            s.pop();
            operandB = s.top();
            s.pop();
            s.push(operation(operandA, operandB, exp[i]));
        }
    }
    cout<<"Answer = \n"<< s.top();
    return 0;
}
