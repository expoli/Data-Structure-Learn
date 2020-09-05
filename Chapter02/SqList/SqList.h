//
// Created by expoli on 2020/9/4.
//

#ifndef TEST_SQLIST_H
#define TEST_SQLIST_H

#define ElemType int
#define MAXSIZE 30

#endif //TEST_SQLIST_H

struct SqlList {
    int data[30];
    int length;
};

void CreateList(SqlList *&L, const ElemType a[], int n);

void DestoryList(SqlList *&L);

bool ListEmpty(SqlList *L);

int ListLength(SqlList *L);

void DispList(SqlList *L);

bool GetElem(SqlList *L, int i, ElemType &e);

int LocateElem(SqlList *L, ElemType e);

bool ListInsert(SqlList *&L, int i, ElemType e);

void ListInster(SqlList *&L, ElemType e);

bool ListDelete(SqlList *&L, int i, ElemType e);

