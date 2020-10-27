//
// Created by expoli on 2020/9/6.
//

#ifndef TEST_DLINKLIST_H
#define TEST_DLINKLIST_H

namespace dlinklist {
#define ElemType int
    typedef struct Dnode {
        ElemType data;
        struct Dnode *prior;
        struct Dnode *next;
    } DLinkList;

    void CreateListF(DLinkList *&L, ElemType a[], int n);

    void CreateListR(DLinkList *&L, ElemType a[], int n);

    bool ListInsert(DLinkList *&L, int i, ElemType e);

    bool ListDelete(DLinkList *&L, int i, ElemType &e);

    void Reverse(DLinkList *&L);
}// namespace dlinklist

#endif//TEST_DLINKLIST_H
