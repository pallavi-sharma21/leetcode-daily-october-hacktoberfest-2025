#include <bits/stdc++.h>
using namespace std;

bool isValidParentheses(const string &s) {
    stack<char> st; // stack to store opening brackets

    for (char ch : s) {
        // If current character is an opening bracket, push to stack
        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        } else {
            // If stack is empty and we encounter a closing bracket, return false
            if (st.empty()) return false;

            // Check if the top of the stack matches the current closing bracket
            char top = st.top();
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false; // mismatch found
            }

            st.pop(); // valid pair found, pop from stack
        }
    }

    // If stack is empty, all brackets were matched correctly
    return st.empty();
}

int main() {
    string s;
    cout << "Enter parentheses string: ";
    cin >> s;

    if (isValidParentheses(s)) {
        cout << "Valid parentheses" << endl;
    } else {
        cout << "Invalid parentheses" << endl;
    }

    return 0;
}
