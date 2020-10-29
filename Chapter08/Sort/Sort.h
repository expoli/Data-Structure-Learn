//
// Created by expoli on 2020/10/28.
//

#ifndef CHAPTER08_SORT_H
#define CHAPTER08_SORT_H

typedef int ElemType;

typedef int KeyType;//定义关键字类型
typedef int InfoType;

typedef struct RecType//记录类型
{
    KeyType key;  //关键字项
    InfoType data;//其他数据项,类型为InfoType
} RecType;        //排序的记录类型定义

#define MAXE 20//线性表中最多元素个数
#define MAXR 10//基数的最大取值
#define MAXD 8//关键字位数的最大取值
typedef struct node {
    char data[MAXD];//记录的关键字定义的字符串
    struct node *next;
} RecType1;//单链表中每个节点的类型

void InsertSort(ElemType A[], int n);

void ShellSort(RecType R[], int n);

void Print(RecType R[],int n);

#endif//CHAPTER08_SORT_H
