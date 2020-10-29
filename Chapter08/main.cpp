#include "Sort/Sort.h"
#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;

    RecType A[10];
    KeyType key[10] = {503, 87, 512, 61, 908, 170, 897, 275, 653, 462};
    for (int i = 0; i < 10; i++) {
        A[i].key = key[i];
    }
    ShellSort(A, 10);

    return 0;
}
