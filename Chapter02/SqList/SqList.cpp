//
// Created by expoli on 2020/9/4.
//

#include <iostream>
#include "SqList.h"

// 建立顺序表
void CreateList(SqlList *&L, const ElemType a[], int n) {
    int i;
    L = (SqlList *) malloc(sizeof(SqlList));
    for (i = 0; i < n; i++)
        L->data[i] = a[i];
    L->length = n;
}

void InitList(SqlList *&L) {
    L = (SqlList *) malloc(sizeof(SqlList));
    L->length = 0;
}

void DestoryList(SqlList *&L) {
    free(L);
}

bool ListEmpty(SqlList *L) {
    return (L->length == 0);
}

int ListLength(SqlList *L) {
    return L->length;
}

void DispList(SqlList *L) {
    int i;
    if (ListEmpty(L))
        return;
    for (i = 0; i < L->length; i++)
        std::cout << L->data[i] << " ";
    printf("\n");
}

bool GetElem(SqlList *L, int i, ElemType &e) {
    if (i < 1 || i > L->length)
        return false;
    e = L->data[i - 1];
    return true;
}

int LocateElem(SqlList *L, ElemType e) {
    int i = 0;
    while (i < L->length && L->data[i] != e)
        i++;
    if (i > L->length)
        return 0;
    else
        return i + 1;
}

bool ListInsert(SqlList *&L, int i, ElemType e) {
    int j;
    if (i < 1 || i > L->length)
        return false;
    i--;
    for (j = L->length; j > i; j--)
        L->data[j] = L->data[j - 1];
    L->data[i] = e;
    L->length++;
    return true;
}

bool ListDelete(SqlList *&L, int i, ElemType e) {
    int j;
    if (i < 1 || i > L->length)
        return false;
    i--;
    e = L->data[i];
    for (j = i; j < L->length - 1; j++)
        L->data[j] = L->data[j + 1];
    L->length--;
    return true;
}

// 顺序表插入
void ListInsert(SqlList *&L, ElemType e) {
    int i = 0, j;
    while (i < L->length && L->data[i] < e)
        i++;
    for (j = L->length; j > i; j--)
        L->data[j] = L->data[j - 1];
    L->data[i] = e;
    L->length++;
}

// 顺序表二路归并
void UnionList(SqlList *LA, SqlList *LB, SqlList *&LC) {
    LC = (SqlList *) malloc(sizeof(SqlList));
    int i = 0, j = 0, k = 0;
    while (i < LA->length && j < LB->length) {
        if (LA->data[i] < LB->data[j]) {
            LC->data[k] = LA->data[i];
            i++;
            k++;
        } else {
            LC->data[k] = LB->data[j];
            j++;
            k++;
        }
    }
    while (i < LA->length) {
        LC->data[k] = LA->data[i];
        k++;
        i++;
    }
    while (j < LB->length) {
        LC->data[k] = LA->data[j];
        k++;
        j++;
    }
    LC->length = k;
}
