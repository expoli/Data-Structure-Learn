//
// Created by expoli on 2020/9/4.
//

#ifndef TEST_LINKLIST_H
#define TEST_LINKLIST_H

#define ElemType int

#endif //TEST_LINKLIST_H

typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LinkList;

void CreateListF(LinkList *&L, ElemType a[], int n);