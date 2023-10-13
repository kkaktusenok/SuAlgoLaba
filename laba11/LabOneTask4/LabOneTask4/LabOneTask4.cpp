#include <iostream>

void appendBlock(int* &array, int &size, const int* block, int blockSize) {
    
    int newSize = size + blockSize;


    int* newArray = new int[newSize];
    
    for (int i = 0; i < size; i++) {
        newArray[i] = array[i];
    }
    
    for (int i = 0; i < blockSize; i++) {
        newArray[size + i] = block[i];
    }
    
    delete[] array;
    
    array = newArray;
    
    size = newSize;
}

int main() {
    int* myArray = nullptr;
    int arraySize = 0;

    int block[] = {1, 2, 3, 4, 5};

    int blockSize = sizeof(block) / sizeof(block[0]);

    appendBlock(myArray, arraySize, block, blockSize);


    for (int i = 0; i < arraySize; i++) {
        std::cout << myArray[i] << " ";
    }
    std::cout << std::endl;


    delete[] myArray;

    return 0;
}
