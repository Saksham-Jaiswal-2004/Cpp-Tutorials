#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

bool isOperator(char c) 
{
    return c == '+' || c == '*' || c == '/';
}

bool isValidExpression(const string &expr) 
{
    stack<char> st;
    char prev = 0;

    for (char c : expr) 
    {
        if (c == ' ') continue;

        if (!(isalpha(c) || isOperator(c) || c == '(' || c == ')'))
            return false;

        if (c == '(') st.push(c);
        else if (c == ')') 
        {
            if (st.empty()) return false;
            st.pop();
        }

        // invalid patterns
        if (isOperator(c) && (prev == 0 || isOperator(prev) || prev == '('))
            return false;
        if (isalpha(c) && isalpha(prev))
            return false;
        if (c == '(' && isalpha(prev))
            return false;
        if (isalpha(c) && prev == ')')
            return false;

        prev = c;
    }

    return st.empty() && !isOperator(prev);
}

// Simplify expression by removing unnecessary parentheses
string simplifyExpression(const string &expr) 
{
    string result;
    stack<char> st;
    for (char c : expr) 
    {
        if (c == ' ') continue;
        if (c == ')') 
        {
            string temp;
            while (!st.empty() && st.top() != '(') 
            {
                temp = st.top() + temp;
                st.pop();
            }
            if (!st.empty() && st.top() == '(')
                st.pop();
            // remove redundant brackets
            if (temp.size() == 1 || temp.find_first_of("+-*/") == string::npos)
                st.push(temp[0]);
            else 
            {
                for (char t : temp) st.push(t);
            }
        } else st.push(c);
    }
    while (!st.empty()) 
    {
        result = st.top() + result;
        st.pop();
    }
    return result;
}

int main() 
{
    string expr;
    cout << "Enter expression: ";
    getline(cin, expr);

    if (!isValidExpression(expr))
    {
        cout << "Invalid Expression\n";
        return 0;
    }

    string simplified = simplifyExpression(expr);
    cout << "Valid\nSimplified Expression: " << simplified << endl;

    return 0;
}