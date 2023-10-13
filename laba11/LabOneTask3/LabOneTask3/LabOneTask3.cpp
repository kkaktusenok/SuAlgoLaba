#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int M, N;

    cout << "Enter array A size : ";
    cin >> M;

    cout << "Enter array B size : ";
    cin >> N;

    int* A = new int[M];
    int* B = new int[N];

    cout << "Enter numbers for A array : " << endl;
    for (int i = 0; i < M; i++) {
        cin >> A[i];
    }

    cout << "Enter numbers for B array : " << endl;
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }

    int* C = new int[M + N];
    int newSize = 0;

    for (int i = 0; i < M; i++) {
        if (find(B, B + N, A[i]) == B + N) {
            bool alreadyInC = false;
            for (int k = 0; k < newSize; k++) {
                if (A[i] == C[k]) {
                    alreadyInC = true;
                    break;
                }
            }
            if (!alreadyInC) {
                C[newSize] = A[i];
                newSize++;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        if (find(A, A + M, B[i]) == A + M) {
            bool alreadyInC = false;
            for (int k = 0; k < newSize; k++) {
                if (B[i] == C[k]) {
                    alreadyInC = true;
                    break;
                }
            }
            if (!alreadyInC) {
                C[newSize] = B[i];
                newSize++;
            }
        }
    }

    cout << "Elements in A and B that are not common without repetitions: ";
    for (int i = 0; i < newSize; i++) {
        cout << C[i] << " ";
    }
    cout << endl;

    delete[] A;
    delete[] B;
    delete[] C;

    return 0;
}
