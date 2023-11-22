#include <iostream>
#include <vector>

class CustomStack {
private:
    std::vector<int> data;

public:
    void push(int value) {
        data.push_back(value);
    }

    void pop() {
        if (!data.empty()) {
            data.pop_back();
        } else {
            std::cerr << "Error: Stack underflow" << std::endl;
        }
    }

    void insertAtIndex(int index, int value) {
        if (index >= 0 && index <= data.size()) {
            data.insert(data.begin() + index, value);
        } else {
            std::cerr << "Error: Invalid index" << std::endl;
        }
    }

    int top() {
        if (!data.empty()) {
            return data.back();
        } else {
            std::cerr << "Error: Stack is empty" << std::endl;
            return -1; 
        }
    }

    bool empty() {
        return data.empty();
    }

    void display() {
        std::cout << "Stack: ";
        for (int element : data) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    CustomStack myStack;

    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    myStack.display(); 

    myStack.insertAtIndex(1, 15);
    myStack.display(); 

    myStack.pop();
    myStack.display(); 

    std::cout << "Top element: " << myStack.top() << std::endl; 

    return 0;
}
