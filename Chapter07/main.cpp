#include "Search_Seq/Search_Seq.h"
#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    int n = 10;
    Elemtype array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    SSTable *ssTable;
    ssTable = InitSSTable(array, n);

    DisplayTable(ssTable);
    std::cout<<Search_Seq(ssTable,7);

    std::cout<<Binary_Search(ssTable,7);

    return 0;
}
