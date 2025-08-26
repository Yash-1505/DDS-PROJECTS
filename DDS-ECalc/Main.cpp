#include <iostream>
using namespace std;

const int N = 100;

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}
bool is_operator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}
int power(int a, int b) {
    int res = 1;
    for (int i = 0; i < b; ++i) res *= a;
    return res;
}

void infix_to_postfix(const char infix[], char postfix[]) {
    char stack[N];
    int top = -1, k = 0;
    for (int i = 0; infix[i]; ++i) {
        char c = infix[i];
        if (c >= '0' && c <= '9') {
            postfix[k++] = c;
        } else if (c == '(') {
            stack[++top] = c;
        } else if (c == ')') {
            while (top >= 0 && stack[top] != '(') postfix[k++] = stack[top--];
            if (top >= 0) top--;
        } else if (is_operator(c)) {
            while (top >= 0 && precedence(stack[top]) >= precedence(c)) postfix[k++] = stack[top--];
            stack[++top] = c;
        }
    }
    while (top >= 0) postfix[k++] = stack[top--];
    postfix[k] = 0;
}

int evaluate_postfix(const char postfix[]) {
    int stack[N], top = -1;
    for (int i = 0; postfix[i]; ++i) {
        char c = postfix[i];
        if (c >= '0' && c <= '9') {
            stack[++top] = c - '0';
        } else if (is_operator(c)) {
            int b = stack[top--], a = stack[top--];
            int res = 0;
            if (c == '+') res = a + b;
            else if (c == '-') res = a - b;
            else if (c == '*') res = a * b;
            else if (c == '/') res = a / b;
            else if (c == '^') res = power(a, b);
            stack[++top] = res;
        }
    }
    return stack[top];
}

int main() {
    cout << "---------------------------\n";
    cout << " Expression Calculator\n";
    cout << "---------------------------\n";
    cout << "Concept: Convert and evaluate math expressions.\n";
    cout << "Stack-based infix-to-postfix conversion.\n";
    cout << "Postfix evaluation.\n";
    cout << "Handles precedence and parentheses.\n";

    char infix[N], postfix[N];
    cout << "\nEnter an infix expression (single-digit numbers): ";
    cin.getline(infix, N);

    char expr[N];
    int j = 0;
    for (int i = 0; infix[i]; ++i)
        if (infix[i] != ' ') expr[j++] = infix[i];
    expr[j] = 0;

    infix_to_postfix(expr, postfix);
    cout << "✅ Postfix Expression: " << postfix << endl;
    cout << "🎯 Evaluated Result: " << evaluate_postfix(postfix) << endl;
    return 0;
}
