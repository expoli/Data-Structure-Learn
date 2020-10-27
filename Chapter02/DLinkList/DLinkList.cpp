//
// Created by expoli on 2020/9/6.
//
#include "DLinkList.h"
#include <iostream>

namespace dlinklist {
    void CreateListF(DLinkList *&L, ElemType a[], int n) {
        DLinkList *s;
        int i;
        L = (DLinkList *) malloc(sizeof(DLinkList));
        L->prior = L->next = NULL;
        for (i = 0; i < n; i++) {
            s = (DLinkList *) malloc(sizeof(DLinkList));
            s->data = a[i];
            s->next = L->next;
            s->prior = L;
            if (L->next != NULL)
                L->next->prior = s;
            L->next = s;
        }
    }

    void CreateListR(DLinkList *&L, ElemType a[], int n) {
        DLinkList *s, *r;
        int i = 0;
        L = (DLinkList *) malloc(sizeof(DLinkList));
        L->next = L->prior = NULL;
        r = L;
        for (i = 0; i < n; i++) {
            s = (DLinkList *) malloc(sizeof(DLinkList));
            s->data = a[i];
            s->prior = r;
            r->next = s;
            r = s;
        }
        r->next = NULL;
    }

    bool ListInsert(DLinkList *&L, int i, ElemType e) {
        DLinkList *p, *s;
        int j = 0;
        i--;
        p = L->next;
        while (j < i && p != NULL) {
            j++;
            p = p->next;
        }
        if (p == NULL)
            return false;
        else {
            s = (DLinkList *) malloc(sizeof(DLinkList));
            s->data = e;
            s->next = p->next;
            s->prior = p;
            if (p->next != NULL)
                p->next->prior = s;
            p->next = s;
            return true;
        }
    }

    bool ListDelete(DLinkList *&L, int i, ElemType &e) {
        DLinkList *p = L, *q;
        int j = 0;
        i--;
        while (j < i && p != NULL) {
            j++;
            p = p->next;
        }
        if (p == NULL)
            return false;
        else {
            q = p->next;
            e = q->data;
            p->next = q->next;
            if (p->next != NULL)
                p->next->prior = p;
            free(q);
            return true;
        }
    }

    // 头插法逆置链表
    void Reverse(DLinkList *&L) {
        DLinkList *p = L->next, *q;
        L->next = NULL;
        L->prior = NULL;
        while (p != NULL) {
            q = p->next;
            p->next = L->next;
            if (p->next != NULL)
                p->next->prior = p;
            p->prior = L;
            L->next = p;
            p = q;
        }
    }

}// namespace dlinklist