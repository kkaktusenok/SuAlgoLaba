#include <iostream>

void splitArray(const int* staticArray, int size, int*& positiveArray, int& positiveSize,
                int*& negativeArray, int& negativeSize, int*& zeroArray, int& zeroSize) {

    int positiveCount = 0, negativeCount = 0, zeroCount = 0;

    for (int i = 0; i < size; i++) {
        if (staticArray[i] > 0) {
            positiveCount++;
        } else if (staticArray[i] < 0) {
            negativeCount++;
        } else {
            zeroCount++;
        }
    }
    
    positiveArray = new int[positiveCount];
    negativeArray = new int[negativeCount];
    zeroArray = new int[zeroCount];
    
    int positiveIndex = 0, negativeIndex = 0, zeroIndex = 0;
    
    for (int i = 0; i < size; i++) {
        if (staticArray[i] > 0) {
            positiveArray[positiveIndex] = staticArray[i];
            positiveIndex++;
        } else if (staticArray[i] < 0) {
            negativeArray[negativeIndex] = staticArray[i];
            negativeIndex++;
        } else {
            zeroArray[zeroIndex] = staticArray[i];
            zeroIndex++;
        }
    }
    
    positiveSize = positiveCount;
    negativeSize = negativeCount;
    zeroSize = zeroCount;
}

int main() {
    int staticArray[] = {3, -2, 0, 5, -1, 0, 7};
    int size = sizeof(staticArray) / sizeof(staticArray[0]);

    int* positiveArray = nullptr;
    int positiveSize = 0;

    int* negativeArray = nullptr;
    int negativeSize = 0;

    int* zeroArray = nullptr;
    int zeroSize = 0;

    splitArray(staticArray, size, positiveArray, positiveSize, negativeArray, negativeSize, zeroArray, zeroSize);
    
    std::cout << "Positive elements: ";
    for (int i = 0; i < positiveSize; i++) {
        std::cout << positiveArray[i] << " ";
    }
    std::cout << std::endl;
    
    std::cout << "Negative elements: ";
    for (int i = 0; i < negativeSize; i++) {
        std::cout << negativeArray[i] << " ";
    }
    std::cout << std::endl;
    
    std::cout << "Zero elements: ";
    for (int i = 0; i < zeroSize; i++) {
        std::cout << zeroArray[i] << " ";
    }
    std::cout << std::endl;
    
    delete[] positiveArray;
    delete[] negativeArray;
    delete[] zeroArray;

    return 0;
}
