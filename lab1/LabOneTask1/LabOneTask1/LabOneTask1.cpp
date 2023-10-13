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

    int minSize = min(M, N);
    int* C = new int[minSize];
    int MinimumSize = 0;
    
    for (int i = 0; i < M; i++) {
        bool FindItOrNo = false;
        for (int j = 0; j < N; j++) {
            if (A[i] == B[j]) {
                FindItOrNo = true;
                break;
            }
        }
        if (FindItOrNo) {
            bool ExistorNo = false;
            for (int k = 0; k < MinimumSize; k++) {
                if (A[i] == C[k]) {
                    ExistorNo = true;
                    break;
                }
            }
            if (!ExistorNo) {
                C[MinimumSize] = A[i];
                MinimumSize++;
            }
        }
    }
    
    cout << "Common elements without repetitions: ";
    for (int i = 0; i < MinimumSize; i++) {
        cout << C[i] << " ";
    }
    cout << endl;
    
    delete[] A;
    delete[] B;
    delete[] C;

    return 0;
}
