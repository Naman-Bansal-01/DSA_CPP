#include <iostream>
using namespace std;

// Node class
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Stack class using Linked List
class Stack {
private:
    Node* topNode;  // Pointer to the top of the stack

public:
    Stack() {
        topNode = nullptr;
    }

    // Push operation
    void push(int val) {
        Node* newNode = new Node(val);
        newNode->next = topNode;
        topNode = newNode;
    }

    // Pop operation
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow" << endl;
            return;
        }
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
    }

    // Top operation
    int top() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1; // or throw exception
        }
        return topNode->data;
    }

    // isEmpty operation
    bool isEmpty() {
        return topNode == nullptr;
    }

    // Display stack contents
    void display() {
        Node* temp = topNode;
        cout << "Stack (top to bottom): ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// Main function
int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    s.display();  // Output: 30 20 10

    cout << "Top element: " << s.top() << endl; // Output: 30

    s.pop();
    s.display();  // Output: 20 10

    return 0;
}
