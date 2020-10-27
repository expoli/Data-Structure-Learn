//
// Created by expoli on 2020/10/27.
//

#include "Search_Seq.h"
#include "iostream"

SSTable *InitSSTable(int length) {
    SSTable *ssTable;
    ssTable = (SSTable *) malloc(sizeof(SSTable));
    ssTable->elem = (Elemtype *) malloc(sizeof(Elemtype) * length + 1);
    ssTable->TableLen = length;
    return ssTable;
}

SSTable *InitSSTable(const Elemtype array[], int length) {
    SSTable *ssTable;
    ssTable = (SSTable *) malloc(sizeof(SSTable));
    ssTable->elem = (Elemtype *) malloc(sizeof(Elemtype) * length + 1);
    for (int i = 1; i <= length; ++i) {// 从0开始
        ssTable->elem[i] = array[i - 1];
    }
    ssTable->TableLen = length;
    return ssTable;
}

void DisplayTable(SSTable *ssTable) {
    for (int i = 1; i <= ssTable->TableLen; ++i) {
        std::cout << ssTable->elem[i] << " ";
    }
    std::cout << std::endl;
}

int Search_Seq(SSTable ST, Elemtype key) {
    ST.elem[0] = key;                                   // 哨兵
    int i;                                              // 位置变量
    for (i = ST.TableLen; ST.elem[i] != ST.elem[0]; --i)// 从后向前找
        ;
    return i;// 若表中不存在关键字为key的元素，将查找到i为0时的哨兵，自动退出循环，减少了不必要的判断
}

int Search_Seq(SSTable *ST, Elemtype key) {
    ST->elem[0] = key;                                     // 哨兵
    int i;                                                 // 位置变量
    for (i = ST->TableLen; ST->elem[i] != ST->elem[0]; --i)// 从后向前找
        ;
    return i;// 若表中不存在关键字为key的元素，将查找到i为0时的哨兵，自动退出循环，减少了不必要的判断
}

int Binary_Search(SSTable *ssTable, Elemtype key) {
    int low = 1, high = ssTable->TableLen, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (ssTable->elem[mid] == key) {
            return mid;
        } else if (ssTable->elem[mid] > key) {
            high = mid - 1;
        } else
            low = mid + 1;
    }
    return -1;
}