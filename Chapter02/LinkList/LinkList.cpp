//
// Created by expoli on 2020/9/4.
//

#include "LinkList.h"
#include <iostream>

namespace linklist {
    // 头插法
    void CreateListF(LinkList *&L, ElemType a[], int n) {
        LinkList *s;
        int i;
        L = (LinkList *) malloc(sizeof(LinkList));
        L->next = NULL;
        for (i = 0; i < n; i++) {
            s = (LinkList *) malloc(sizeof(LinkList));
            s->data = a[i];
            s->next = L->next;
            L->next = s;
        }
    }

    // 尾插法
    void CreateListR(LinkList *&L, ElemType a[], int n) {
        LinkList *s, *r;
        int i;
        L = (LinkList *) malloc(sizeof(LinkList));
        r = L;
        for (i = 0; i < n; i++) {
            s = (LinkList *) malloc(sizeof(LinkList));
            s->data = a[i];
            r->next = s;
            r = s;
        }
        r->next = NULL;
    }

    //
    void InitList(LinkList *&L) {
        L = (LinkList *) malloc(sizeof(LinkList));
        L->next = NULL;
    }

    //
    void DestroyList(LinkList *&L) {
        LinkList *pre, *p;
        pre = L;
        p = L->next;
        while (p != NULL) {
            free(pre);
            pre = p;
            p = pre->next;
        }
        free(pre);
    }

    //
    bool ListEmpty(LinkList *L) {
        int n = 0;
        LinkList *p;
        p = L;
        while (p->next != NULL) {
            p = p->next;
            n++;
        }
        return n;
    }

    //
    void DispList(LinkList *L) {
        LinkList *p;
        p = L->next;
        while (p != NULL) {
            std::cout << p->data << " ";
            p = p->next;
        }
        std::cout << std::endl;
    }

    // 获取结点I的值
    bool GetElem(LinkList *L, int i, ElemType &e) {
        LinkList *p;
        p = L->next;
        int j = 0;
        while (j < i && p != NULL) {
            j++;
            p = p->next;
        }
        if (p == NULL)
            return false;
        else {
            e = p->data;
            return true;
        }
    }

    // 获取倒数第K个结点的值
    bool GetElem_Bottom_K(LinkList *L, int k, ElemType &e) {
        LinkList *p, *q;
        p = q = L->next;
        int i = 0;
        while (p != NULL && i < k) {
            p = p->next;
            i++;
        }
        if (p == NULL)
            return false;
        else {
            while (p != NULL) {
                p = p->next;
                q = q->next;
            }
            e = q->data;
            return true;
        }
    }

    //
    int LocateElem(LinkList *L, ElemType e) {
        LinkList *p;
        p = L->next;
        int i = 0;
        while (p != NULL) {
            if (p->data == e)
                break;
            else {
                i++;
                p = p->next;
            }
        }
        if (p == NULL)
            return 0;
        else
            return i + 1;
    }

    //
    bool ListInsret(LinkList *&L, int i, ElemType e) {
        int j = 0;
        i--;
        LinkList *p = L->next, *s;
        while (p != NULL && j < i) {
            p = p->next;
            j++;
        }
        if (p == NULL)
            return false;
        else {
            s = (LinkList *) malloc(sizeof(LinkList));
            s->data = e;
            s->next = p->next;
            p->next = s;
            return true;
        }
    }

    //
    bool ListDelete(LinkList *&L, int i, ElemType &e) {
        LinkList *p, *q;
        p = L->next;
        int j = 0;
        i--;
        while (p != NULL && j < i) {
            p = p->next;
            j++;
        }
        if (p == NULL)
            return false;
        else {
            q = p->next;
            if (q == NULL)
                return false;
            e = q->data;
            p->next = p->next->next;
            free(q);
            return true;
        }
    }
}// namespace linklist
