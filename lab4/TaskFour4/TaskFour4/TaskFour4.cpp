#include <iostream>

using namespace std;

int fibonacci(int N) {
    if (N == 0) {
        return 0;
    } else if (N == 1) {
        return 1;
    } else {
        return fibonacci(N - 1) + fibonacci(N - 2);
    }
}

int main() {
    int N;
    cout << "Enter N: ";
    cin >> N;

    if (N < 0) {
        cout << "N must be non-negative." << endl;
    } else {
        int result = fibonacci(N);
        cout << "The N-th Fibonacci number: " << result << endl;
    }

    return 0;
}
