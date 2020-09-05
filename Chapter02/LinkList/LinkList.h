//
// Created by expoli on 2020/9/4.
//

#ifndef TEST_LINKLIST_H
#define TEST_LINKLIST_H

#define ElemType int

namespace linklist {
    typedef struct LNode {
        ElemType data;
        struct LNode *next;
    } LinkList;

    void CreateListF(LinkList *&L, ElemType a[], int n);

    void CreateListR(LinkList *&L, ElemType a[], int n);

    void InitList(LinkList *&L);

    void DestroyList(LinkList *&L);

    bool ListEmpty(LinkList *L);

    void DispList(LinkList *L);

    bool GetElem(LinkList *L, int i, ElemType &e);

    int LocateElem(LinkList *L, ElemType e);

    bool ListInsret(LinkList *&L, int i, ElemType e);

    bool ListDelete(LinkList *&L, int i, ElemType &e);
}

#endif //TEST_LINKLIST_H


