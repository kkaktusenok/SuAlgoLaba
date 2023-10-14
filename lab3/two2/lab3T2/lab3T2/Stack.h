#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

template <typename T>
class DynamicStack
{
public:
    T data;
    DynamicStack* next;

    DynamicStack(T value) : data(value), next(nullptr)
    {
    }
};

template <typename T>
class LinkedStack
{
public:
    LinkedStack() : top_(nullptr), size_(0)
    {
    }

    void push(T value)
    {
        DynamicStack<T>* newNode = new DynamicStack<T>(value);
        newNode->next = top_;
        top_ = newNode;
        size_++;
    }

    void pop()
    {
        if (!isEmpty())
        {
            DynamicStack<T>* temp = top_;
            top_ = top_->next;
            delete temp;
            size_--;
        }
        else
        {
            cerr << "Stack is empty. Cannot pop." << endl;
        }
    }

    T top() const
    {
        if (!isEmpty())
        {
            return top_->data;
        }
        throw out_of_range("Stack is empty");
    }

    bool isEmpty() const
    {
        return size_ == 0;
    }

    size_t size() const
    {
        return size_;
    }

private:
    DynamicStack<T>* top_;
    size_t size_;
};

#endif
