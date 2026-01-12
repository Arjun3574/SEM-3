#include <iostream>
#include <stack>
#include <cctype>   // for isdigit()

using namespace std;

int evaluatePostfix(string exp) {
    stack<int> st;

    for (size_t i = 0; i < exp.length(); i++) {
        char c = exp[i];

        if (isdigit(c)) {
            st.push(c - '0');   // convert char digit to int
        } else {
            int a = st.top(); st.pop();
            int b = st.top(); st.pop();

            switch (c) {
                case '+': st.push(b + a); break;
                case '-': st.push(b - a); break;
                case '*': st.push(b * a); break;
                case '/': st.push(b / a); break;
                default:
                    cout << "Invalid operator: " << c << endl;
                    return -1;
            }
        }
    }
    return st.top();
}

int main() {
    string post;
    cout << "Enter postfix expression: ";
    cin >> post;

    cout << "Result = " << evaluatePostfix(post) << endl;
    return 0;
}
