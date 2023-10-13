#include <iostream>

using namespace std;

const int MAX_SIZE = 100;

class DynamicStack {
public:
    DynamicStack() : size_(0) {
        for (int i = 0; i < MAX_SIZE; ++i) {
            stack_[i] = 0;
        }
    }

    void push(int value) {
        if (size_ < MAX_SIZE) {
            stack_[size_] = value;
            size_++;
        } else {
            cerr << "Stack is full. Cannot push more elements." << endl;
        }
    }

    void pop() {
        if (!isEmpty()) {
            size_--;
        } else {
            cerr << "Stack is empty. Cannot pop." << endl;
        }
    }

    int top() const{
        if (!isEmpty()) {
            return stack_[size_ - 1];
        }
        throw out_of_range("Stack is empty");
    }

    bool isEmpty() const {
        return size_ == 0;
    }

    size_t size() const {
        return size_;
    }

private:
    int stack_[MAX_SIZE];
    size_t size_;
};

int main() {
    DynamicStack stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    stack.push(6);
    stack.push(7);
    stack.push(8);

    int sizeOfStack = stack.size();

    for (int i = 0; i < sizeOfStack; i++) {
        cout << stack.top() << endl;
        stack.pop();
    }

    return 0;
}
