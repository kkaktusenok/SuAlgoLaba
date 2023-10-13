#include <iostream>

void removeBlock(int* &array, int &size, int startIndex, int blockSize) {
    if (startIndex < 0 || startIndex >= size || blockSize <= 0) {
        std::cout << "Invalid input parameters for removeBlock." << std::endl;
        return;
    }

    int newSize = size - blockSize
    
    int* newArray = new int[newSize];
    
    for (int i = 0; i < startIndex; i++) {
        newArray[i] = array[i];
    }
    
    for (int i = startIndex + blockSize; i < size; i++) {
        newArray[i - blockSize] = array[i];
    }
    
    delete[] array;
    
    array = newArray;
    
    size = newSize;
}

int main() {
    int* myArray = new int[10];
    int arraySize = 10;
    
    for (int i = 0; i < arraySize; i++) {
        myArray[i] = i;
    }

    int startIndex = 3;
    int blockSize = 4;

    removeBlock(myArray, arraySize, startIndex, blockSize);
    
    for (int i = 0; i < arraySize; i++) {
        std::cout << myArray[i] << " ";
    }
    std::cout << std::endl;
    
    delete[] myArray;

    return 0;
}
