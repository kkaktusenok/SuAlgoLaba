#include <iostream>

void insertBlock(int* &array, int &size, const int* block, int blockSize, int index) {
    
    if (index < 0 || index > size) {
        std::cout << "Invalid index for insertion." << std::endl;
        return;
    }

    int newSize = size + blockSize;
    
    int* newArray = new int[newSize];
    
    for (int i = 0; i < index; i++) {
        newArray[i] = array[i];
    }
    
    for (int i = 0; i < blockSize; i++) {
        newArray[index + i] = block[i];
    }
    
    for (int i = index; i < size; i++) {
        newArray[index + blockSize + i] = array[i];
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

    int insertIndex = 2;

    insertBlock(myArray, arraySize, block, blockSize, insertIndex);
    
    for (int i = 0; i < arraySize; i++) {
        std::cout << myArray[i] << " ";
    }
    std::cout << std::endl;
    
    delete[] myArray;

    return 0;
}
