#include <bits/stdc++.h>
#include <stack>
using namespace std;
int precedence(char c)
{
    if(c == '^')
    return 3;
    else if(c == '*' || c == '/')
    return 2;
    else if(c == '+' || c == '-')
    return 1;
    else
    return -1;
}


string infixToPostfix(string s)
{
    stack<char> st;
    st.push('N');
    int l = s.length();
    string ns;
    for(int i = 0; i < l; i++)
    {
        if((isalnum(s[i])))
        { ns+=s[i]; }

        else if(s[i] == '(')

        { st.push('('); }

        else if(s[i] == ')')
        {
            while(st.top() != 'N' && st.top() != '(')
            {
                char c = st.top();
                st.pop();
               ns += c;
            }
            if(st.top() == '(')
            {
                char c = st.top();
                st.pop();
            }
        }

        else{
            while(st.top() != 'N' && precedence(s[i]) <= precedence(st.top()))
            {
                char c = st.top();
                st.pop();
                ns += c;
            }
            st.push(s[i]);
        }

    }
    while(st.top() != 'N')
    {
        char c = st.top();
        st.pop();
        ns += c;
    }

    return(ns);

}

bool isOperand(char x)
{
   return (isalnum(x));
}

string PostfixToInfix(string exp)
{
    stack<string> s;

    for (int i=0; exp[i]!='\0'; i++)
    {
        if (isOperand(exp[i]))
        {
           string op(1, exp[i]);
           s.push(op);
        }
        else
        {
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
           s.push("(" + op2 + exp[i] + op1 + ")");
        }
    }
    return s.top();
}
string RemoveOuterBrackets(string exp1)
{
    int l=exp1.length();
    exp1[0]=' ';
    exp1[l-1]=' ';
    return(exp1);
}
int main()
{
    string str,str1,str2,str3;
    cout << "\n enter arithmetic expression: ";
    getline(cin,str);
    str1= infixToPostfix(str);
    str2= PostfixToInfix(str1);
    str3= RemoveOuterBrackets(str2);
    cout<<"\n correct expression is : "<<str3;
    return 0;
}
