#include <bits/stdc++.h>
#include <stack>
using namespace std;
string PostfixToInfix(string exp)
{
    stack<string> s;

    for (int i=0; exp[i]!='\0'; i++)
    {	// If operand than push to stack in a string
        if (isOperand(exp[i]))
        {
           string op(1, exp[i]);
           s.push(op);
        }
		// else pop top 2 nodes from stack, push "node1" + operator + "node2" 
        else
        {
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
           s.push("(" + op2 + exp[i] + op1 + ")");
        }
    }
	// Now only top node left in string which is the required infix
    return s.top();
}

int main()
{
    string str,str1;
    cout << "\n enter expression: ";
    getline(cin,str);
    str1= PostfixToInfix(str);
    cout<<"\n correct expression is : "<<str1;
    return 0;
}
