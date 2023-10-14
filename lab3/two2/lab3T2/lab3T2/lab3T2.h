#pragma once
#include <iostream>

using namespace std;

class DynamicStack {
public:
    int data;
    DynamicStack* next;

    DynamicStack(int value) : data(value), next(nullptr) {}
};

class LinkedStack {
public:
    LinkedStack() : top_(nullptr), size_(0) {}

    void push(int value) {
        DynamicStack* newNode = new DynamicStack(value);
        newNode->next = top_;
        top_ = newNode;
        size_++;
    }

    void pop() {
        if (!isEmpty()) {
            DynamicStack* temp = top_;
            top_ = top_->next;
            delete temp;
            size_--;
        } else {
            cerr << "Stack is empty. Cannot pop." << endl;
        }
    }

    int top() const {
        if (!isEmpty()) {
            return top_->data;
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
    DynamicStack* top_;
    size_t size_;
};