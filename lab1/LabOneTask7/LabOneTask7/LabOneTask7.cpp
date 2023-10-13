#include <iostream>

bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int* removePrimes(int* array, int& size) {
    int newSize = 0;
    
    for (int i = 0; i < size; i++) {
        if (!isPrime(array[i])) {
            newSize++;
        }
    }
    
    int* newArray = new int[newSize];
    int newIndex = 0;
    
    for (int i = 0; i < size; i++) {
        if (!isPrime(array[i])) {
            newArray[newIndex] = array[i];
            newIndex++;
        }
    }
    
    delete[] array;
    
    size = newSize;

    return newArray;
}

int main() {
    int size;
    std::cout << "Enter the size of the array: ";
    std::cin >> size;

    int* myArray = new int[size];

    std::cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++) {
        std::cin >> myArray[i];
    }

    myArray = removePrimes(myArray, size);

    std::cout << "Array after removing prime numbers: ";
    for (int i = 0; i < size; i++) {
        std::cout << myArray[i] << " ";
    }
    std::cout << std::endl;
    
    delete[] myArray;

    return 0;
}
