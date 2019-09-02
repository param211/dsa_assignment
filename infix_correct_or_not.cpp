#include <iostream>
#include <stack>
using namespace std;
void checkInfix(string str)
{
    stack <char> s;
    s.push('#');
    int counter=0, l= str.length();
    for(int i=0;i<l;i++)
    {
        if(str[i]=='(')
        {
            counter++;
        }
        else if(str[i]==')')
        {
            counter--;
        }
        else if(str[i]=='+'||str[i]=='-'
                ||str[i]=='*'||str[i]=='/'
                ||str[i]=='^')
        {
            s.push(str[i]);
        }
        else if((str[i] >= 'a' && str[i] <= 'z')
                ||(str[i] >= 'A' && str[i] <= 'Z')
                ||str[i]>=0&&str[i]<=9)
        {
            if(s.top()!='#')
            s.pop();
        }
    }
    if(s.top()=='#'&&counter==0)
        {   cout<<"expression is valid";  }
    else
        {   cout<<"expression is invalid"; }
}
int main()
{
    string str;
    cout<<"enter the infix expression: \n";
    getline(cin, str);
    checkInfix(str);
    return 0;
}
