#include <algorithm>
#include <iostream>

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

    int* C = new int[M];
    int NewSize = 0;

    for (int i = 0; i < M; i++) {
        bool found = false;
        for (int j = 0; j < N; j++) {
            if (A[i] == B[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            bool ExistOrNo = false;
            for (int k = 0; k < NewSize; k++) {
                if (A[i] == C[k]) {
                    ExistOrNo = true;
                    break;
                }
            }
            if (!ExistOrNo) {
                C[NewSize] = A[i];
                NewSize++;
            }
        }
    }

    cout << "Elements in A not present in B without repetitions: ";
    for (int i = 0; i < NewSize; i++) {
        cout << C[i] << " ";
    }
    cout << endl;

    delete[] A;
    delete[] B;
    delete[] C;

    return 0;
}
