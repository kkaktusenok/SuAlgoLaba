#include <iostream>

using namespace std;

void printReversedSequence(int N) {
    if (N == 0) {
        return;
    } else {
        int x;
        cin >> x;
        printReversedSequence(N - 1);
        cout << x << " ";
    }
}

int main() {
    int N;
    cout << "Enter count of N elements: ";
    cin >> N;
    
    cout << "Enter N numbers";
    printReversedSequence(N);
    
    return 0;
}
