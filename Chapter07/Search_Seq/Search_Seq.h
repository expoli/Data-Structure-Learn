//
// Created by expoli on 2020/10/27.
//

#ifndef CHAPTER07_SEARCH_SEQ_H
#define CHAPTER07_SEARCH_SEQ_H
#define Elemtype int

typedef struct SSTable {// 查找表的数据结构
    Elemtype *elem;     // 元素储存空间基址，建表时按实际长度分配，0号单元留空
    int TableLen;       // 表的长度
} SSTable;

int Search_Seq(SSTable ST, Elemtype key);// 顺序查找算法
SSTable *InitSSTable(int length);
void DisplayTable(SSTable *ssTable);
SSTable *InitSSTable(const Elemtype array[], int length);
int Search_Seq(SSTable *ST, Elemtype key);
int Binary_Search(SSTable *ssTable, Elemtype key);

#endif//CHAPTER07_SEARCH_SEQ_H
