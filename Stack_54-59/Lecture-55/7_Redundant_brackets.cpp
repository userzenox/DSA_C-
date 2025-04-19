#include <bits/stdc++.h>
using namespace std;

bool findRedundantBrackets(string &s)
{
    stack<char> st;

    for (int i = 0; i < s.size(); i++)
    {
        char ch = s[i];

        if (ch == '(' || ch == '/' || ch == '+' || ch == '-' || ch == '*')
        {
            st.push(ch);
        }
        else
        {
            if (ch == ')')
            {
                bool isRedundant = true;
                while (!st.empty() && st.top() != '(')
                {
                    char c = st.top();
                    st.pop();
                    if (c == '/' || c == '+' || c == '-' || c == '*')
                    {
                        isRedundant = false;
                    }
                }
                if (isRedundant)
                {
                    return true;
                }
                if (!st.empty()) st.pop(); // remove the opening bracket
            }
        }
    }
    return false;
}

int main()
{
    string expression;
    cout << "Enter the expression: ";
    cin >> expression;

    if (findRedundantBrackets(expression))
    {
        cout << "Yes, the expression contains redundant brackets." << endl;
    }
    else
    {
        cout << "No, the expression does not contain redundant brackets." << endl;
    }

    return 0;
}
