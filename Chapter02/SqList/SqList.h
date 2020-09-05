//
// Created by expoli on 2020/9/4.
//

#ifndef TEST_SQLIST_H
#define TEST_SQLIST_H

#define ElemType int
#define MAXSIZE 30

namespace sqlist {

    typedef struct SqList {
        int data[MAXSIZE];
        int length;
    } SqList;

    void CreateList(SqList *&L, const ElemType a[], int n);

    void DestoryList(SqList *&L);

    bool ListEmpty(SqList *L);

    int ListLength(SqList *L);

    void DispList(SqList *L);

    bool GetElem(SqList *L, int i, ElemType &e);

    int LocateElem(SqList *L, ElemType e);

    bool ListInsert(SqList *&L, int i, ElemType e);

    void ListInster(SqList *&L, ElemType e);

    bool ListDelete(SqList *&L, int i, ElemType e);
}

#endif //TEST_SQLIST_H

