#include "lab3T2.h"
#include <iostream>
using namespace std;

int main() {
    LinkedStack stack;

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
