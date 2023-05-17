#include <iostream>

class OneDimensionalArray {
private:
    int* array;
    int maxSize;
    int currentSize;

public:
    OneDimensionalArray(int size) {
        maxSize = size;
        currentSize = 0;
        array = new int[maxSize];
    }

    ~OneDimensionalArray() {
        delete[] array;
    }

    void addElement(int element) {
        if (currentSize < maxSize) {
            array[currentSize] = element;
            currentSize++;
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const OneDimensionalArray& arr) {
        for (int i = 0; i < arr.currentSize; i++) {
            os << arr.array[i] << " ";
        }
        return os;
    }

    bool operator==(const OneDimensionalArray& arr) const {
        if (currentSize != arr.currentSize) {
            return false;
        }
        for (int i = 0; i < currentSize; i++) {
            if (array[i] != arr.array[i]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    OneDimensionalArray arr1(5);
    arr1.addElement(1);
    arr1.addElement(2);
    arr1.addElement(3);

    OneDimensionalArray arr2(5);
    arr2.addElement(1);
    arr2.addElement(2);
    arr2.addElement(3);

    std::cout << "arr1: " << arr1 << std::endl;
    std::cout << "arr2: " << arr2 << std::endl;

    if (arr1 == arr2) {
        std::cout << "arr1 and arr2 are equal." << std::endl;
    }
    else {
        std::cout << "arr1 and arr2 are not equal." << std::endl;
    }

    return 0;
}
