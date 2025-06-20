#include <bits/stdc++.h>
using namespace std;

// Function to get precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Function to perform arithmetic operation
double applyOp(double a, double b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': 
            if (b == 0) throw runtime_error("Division by zero");
            return a / b;
    }
    return 0;
}

// Function to check if character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to convert infix expression to postfix
string infixToPostfix(string infix) {
    stack<char> operators;
    string postfix = "";
    
    for (char c : infix) {
        if (c == ' ') continue; // Skip spaces
        // If operand (number), add to output
        if (isdigit(c) || c == '.') {
            postfix += c;
        }
        // If opening parenthesis, push to stack
        else if (c == '(') {
            operators.push(c);
        }
        // If closing parenthesis, pop until matching '('
        else if (c == ')') {
            while (!operators.empty() && operators.top() != '(') {
                postfix += ' ';
                postfix += operators.top();
                operators.pop();
            }
            if (!operators.empty()) operators.pop(); // Remove '('
        }
        // If operator, pop higher/equal precedence operators
        else if (isOperator(c)) {
            postfix += ' ';
            while (!operators.empty() && operators.top() != '(' &&
                   precedence(operators.top()) >= precedence(c)) {
                postfix += operators.top();
                operators.pop();
            }
            operators.push(c);
        }
    }
    
    // Pop remaining operators
    while (!operators.empty()) {
        postfix += ' ';
        postfix += operators.top();
        operators.pop();
    }
    
    return postfix;
}

// Function to evaluate postfix expression
double evaluatePostfix(string postfix) {
    stack<double> values;
    string num = "";
    
    for (char c : postfix) {
        if (c == ' ') {
            if (!num.empty()) {
                values.push(stod(num));
                num = "";
            }
            continue;
        }
        if (isdigit(c) || c == '.') {
            num += c;
        }
        else if (isOperator(c)) {
            if (!num.empty()) {
                values.push(stod(num));
                num = "";
            }
            if (values.size() < 2) throw runtime_error("Invalid expression");
            double b = values.top(); values.pop();
            double a = values.top(); values.pop();
            values.push(applyOp(a, b, c));
        }
    }
    
    if (!num.empty()) values.push(stod(num));
    if (values.size() != 1) throw runtime_error("Invalid expression");
    
    return values.top();
}

// Function to evaluate infix expression
double evaluateInfix(string infix) {
    try {
        string postfix = infixToPostfix(infix);
        return evaluatePostfix(postfix);
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
        return NAN;
    }
}

int main() {
    // Test cases
    string expressions[] = {
        "3 + 5 * ( 2 - 8 )",
        "10 + 2 * 6",
        "100 * 2 + 12",
        "100 * ( 2 + 12 ) / 14"
    };
    
    for (const string& expr : expressions) {
        cout << "Expression: " << expr << endl;
        cout << "Postfix: " << infixToPostfix(expr) << endl;
        cout << "Result: " << evaluateInfix(expr) << endl;
        cout << "------------------------" << endl;
    }
    
    return 0;
}