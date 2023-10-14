#pragma once

#include <iostream>
using namespace std;

#ifndef FIXED_CAPACITY_STACK_H
#define FIXED_CAPACITY_STACK_H

template <typename T>
class FixedCapacityStack {
public:
    FixedCapacityStack() : size_(0) {
        for (int i = 0; i < MAX_SIZE; ++i) {
            stack_[i] = T();
        }
    }

    void push(T value) {
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

    T top() const {
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
    static const int MAX_SIZE = 100;
    T stack_[MAX_SIZE];
    size_t size_;
};

#endif
