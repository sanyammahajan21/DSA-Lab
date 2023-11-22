#include <iostream>
#include <queue>

int main() {
    
    std::queue<int> myQueue;

    myQueue.push(10);
    myQueue.push(20);
    myQueue.push(30);

    std::cout << "Front element: " << myQueue.front() << std::endl;
    std::cout << "Back element: " << myQueue.back() << std::endl;

    myQueue.pop();

    std::cout << "Front element after dequeue: " << myQueue.front() << std::endl;
    std::cout << "Back element after dequeue: " << myQueue.back() << std::endl;
    
    std::cout << "Is the queue empty? " << (myQueue.empty() ? "Yes" : "No") << std::endl;

    return 0;
}
