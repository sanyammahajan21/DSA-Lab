#include <iostream>
#include <stack>
#include <string>

bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int applyOperator(char op, int operand1, int operand2) {
    switch (op) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            if (operand2 != 0) {
                return operand1 / operand2;
            } else {
                std::cerr << "Error: Division by zero!" << std::endl;
                exit(1);
            }
        default:
            std::cerr << "Error: Invalid operator!" << std::endl;
            exit(1);
    }
}

int evaluatePostfix(const std::string& postfixExpression) {
    std::stack<int> operandStack;

    for (char ch : postfixExpression) {
        if (isdigit(ch)) {
            operandStack.push(ch - '0'); 
        } else if (isOperator(ch)) {
            
            int operand2 = operandStack.top();
            operandStack.pop();

            int operand1 = operandStack.top();
            operandStack.pop();

            int result = applyOperator(ch, operand1, operand2);
            operandStack.push(result);
        }
    }

    if (!operandStack.empty()) {
        return operandStack.top();
    } else {
        std::cerr << "Error: Invalid postfix expression!" << std::endl;
        exit(1);
    }
}

int main() {
    std::string postfixExpression;

    
    std::cout << "Enter a postfix expression: ";
    std::getline(std::cin, postfixExpression);
   
    int result = evaluatePostfix(postfixExpression);

    std::cout << "Result: " << result << std::endl;

    return 0;
}
