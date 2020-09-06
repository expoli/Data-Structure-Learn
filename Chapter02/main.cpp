#include <iostream>
#include "SqList/SqList.h"
#include "LinkList/LinkList.h"
#include "DLinkList/DLinkList.h"

bool delete_same(sqlist::SqList *&L) {
    if (L->length == 0)
        return false;
    int i, j;
    for (i = 0, j = 1; j < L->length; j++)
        if (L->data[i] != L->data[j])
            L->data[++i] = L->data[j];
    L->length = i++;
    return true;
}

int M_Search(ElemType A[], ElemType B[], int n) {
    int i, j, k;
    i = j = k = 0;
    while (i < n && j < n) {
        k++;
        if (A[i] < B[j]) {
            if (k == n)
                return A[i];
            i++;
        } else {
            if (k == n)
                return B[j];
            j++;
        }
    }
    return 0;
}

int M_Search_2(ElemType A[], ElemType B[], int n) {
    int i, j, k, e;
    i = j = k = 0;
    while (k < n) {
        if (A[i] < B[j]) {
            e = A[i];
            i++;
            k++;
        } else {
            e = B[j];
            j++;
            k++;
        }
    }
    return e;
}

int M_Search_3(int A[], int B[], int n) {
    int s1 = 0, d1 = n - 1, s2 = 0, d2 = n - 1, m1, m2;
    while (s1 != d1 || s2 != d2) {
        m1 = (s1 + d1) / 2;
        m2 = (s2 + d2) / 2;
        if (A[m1] == B[m2])
            return A[m1];
        if (A[m1] < B[m2]) {
            if ((s1 + d1) % 2 == 0) {
                s1 = m1;
                d2 = m2;
            } else {
                s1 = m1 + 1;
                d2 = m2;
            }
        } else {
            if ((s2 + d2) % 2 == 0) {
                s2 = m2;
                d1 = m1;
            } else {
                s2 = m2 + 1;
                d1 = m1;
            }
        }
    }
    return A[s1] < B[s2] ? A[s1] : B[s2];
}

int Majaority(int A[], int n) {
    int i, c, count = 1;
    c = A[0];
    for (i = 1; i < n; i++) {
        if (A[i] == c)
            count++;
        else if (count > 0)
            count--;
        else {
            c = A[i];
            count = 1;
        }
    }
    if (count > 0) {
        count = 0;
        for (i = 0; i < n; i++) {
            if (A[i] == c)
                count++;
        }
    }
    if (count > n / 2)
        return c;
    else
        return -1;
}

void Del_X_3(linklist::LinkList *&L, ElemType x) {
    linklist::LinkList *p;
    if (L == NULL)
        return;
    if (L->data == x) {
        p = L;
        L = L->next;
        free(p);
        Del_X_3(L, x);
    } else
        Del_X_3(L->next, x);
}

void Del_X_1(linklist::LinkList *&L, ElemType x) {
    linklist::LinkList *pre, *p;
    pre = L;
    p = L->next;
    while (p != NULL) {
        if (p->data == x) {
            pre->next = p->next;
            free(p);
            p = pre->next;
        } else {
            pre = p;
            p = p->next;
        }
    }
}

void R_Print(linklist::LinkList *L) {
    if (L->next != NULL)
        R_Print(L->next);
    if (L != NULL)
        std::cout << L->data << " ";
}

void Reverse_1(linklist::LinkList *&L) {
    linklist::LinkList *p, *r;
    p = L->next;
    L->next = NULL;
    while (p != NULL) {
        r = p->next;
        p->next = L->next;
        L->next = p;
        p = r;
    }
}

void Reverse_2(linklist::LinkList *&L) {
    linklist::LinkList *pre, *p = L->next, *r = p->next;
    p->next = NULL;
    while (r != NULL) {
        pre = p;
        p = r;
        r = r->next;
        p->next = pre;
    }
    L->next = p;
}

void Reverse_3(linklist::LinkList *&L) {
    linklist::LinkList *p, *q;
    p = L->next;
    L->next = NULL;
    while (p->next != NULL) {
        if (L->next == NULL) {
            q = p->next;
            L->next = p;
            p->next = NULL;
            p = q;
        } else {
            q = p->next;
            p->next = L->next;
            L->next = p;
            p = q;
        }
    }
    p->next = L->next;
    L->next = p;
}

void Sort(linklist::LinkList *&L) {
    linklist::LinkList *pre, *p, *r;
    // 创建只有一个数据结点的表
    p = L->next;
    r = p->next;
    p->next = NULL;
    p = r;
    while (p != NULL) {
        r = p->next;
        pre = L;
        while (pre->next != NULL && pre->next->data < p->data)
            pre = pre->next;
        p->next = pre->next;
        pre->next = p;
        p = r;
    }
}

void RangerDelete(linklist::LinkList *&L, ElemType min, ElemType max) {
    linklist::LinkList *pre, *p;
    pre = L;
    p = L->next;
    while (p != NULL) {
        if (p->data > min && p->data < max) {
            pre->next = p->next;
            free(p);
            p = pre->next;
        } else {
            pre = p;
            p = pre->next;
        }
    }
}

bool Search_1st_Common(linklist::LinkList *LA, linklist::LinkList *LB, linklist::LinkList *&e) {
    linklist::LinkList *longlist = LA->next, *shortlist = LB->next;
    int len1 = 0, len2 = 0, dist = 0;
    while (longlist != NULL) {
        longlist = longlist->next;
        len1++;
    }
    while (shortlist != NULL) {
        shortlist = shortlist->next;
        len2++;
    }
    if (len1 < len2) {
        shortlist = LA->next;
        longlist = LB->next;
        dist = len2 - len1;
    } else {
        shortlist = LB->next;
        longlist = LA->next;
        dist = len1 - len2;
    }
    while (dist--)
        longlist = longlist->next;
    while (shortlist != NULL && longlist != NULL) {
        if (shortlist == longlist) {
            e = shortlist;
            return true;
        } else {
            longlist = longlist->next;
            shortlist = shortlist->next;
        }
    }
    e = NULL;
    return false;
}

void Min_Delete(linklist::LinkList *&head) {
    linklist::LinkList *p, *pre, *u;
    while (head->next != NULL) {
        pre = head;
        p = pre->next;
        while (p->next != NULL) {
            if (pre->next->data > p->next->data)
                pre = p;
            p = p->next;
        }
        std::cout << pre->next->data << " ";
        u = pre->next;
        pre->next = u->next;
        free(u);
    }
    free(head);
}

void DisCreate_1(linklist::LinkList *&A, linklist::LinkList *&B) {
    linklist::LinkList *la, *lb, *p;
    int i = 1;
    la = A;
    lb = B;
    p = A->next;
    while (p != NULL) {
        if (i % 2 == 0) {
            lb->next = p;
            lb = p;
            p = p->next;
            i++;
        } else {
            la->next = p;
            la = p;
            p = p->next;
            i++;
        }
    }
    la->next = NULL;
    lb->next = NULL;
}

void Delete_Same_1(linklist::LinkList *&L) {
    linklist::LinkList *p, *q;
    p = L->next;
    if (p == NULL)
        return;
    q = p->next;
    while (q != NULL) {
        if (p->data == q->data) {
            p->next = q->next;
            std::cout << "free" << q->data << std::endl;
            free(q);
        } else {
            p = p->next;
        }
        q = p->next;
    }
}

void Delete_Same_2(linklist::LinkList *&L) {
    linklist::LinkList *pre, *p, *q;
    pre = L;
    p = L->next;
    while (p != NULL) {
        if (pre->data == p->data)
            p = p->next;
        else if (pre->next != p) {
            q = pre->next;
            pre->next = q->next;
            free(q);
        } else {
            p = p->next;
            pre = pre->next;
        }
    }
}

void MergeList(linklist::LinkList *&LA, linklist::LinkList *&LB) {
    linklist::LinkList *pa, *pb, *q;
    pa = LA->next;
    pb = LB->next;
    LA->next = NULL;
    while (pa != NULL && pb != NULL) {
        if (pa->data < pb->data) {
            q = pa->next;
            pa->next = LA->next;
            LA->next = pa;
            pa = q;
        } else {
            q = pb->next;
            pb->next = LA->next;
            LA->next = pb;
            pb = q;
        }
    }
    while (pa != NULL) {
        q = pa->next;
        pa->next = LA->next;
        LA->next = pa;
        pa = q;
    }
    while (pb != NULL) {
        q = pb->next;
        pb->next = LA->next;
        LA->next = pb;
        pb = q;
    }
    free(LB);
}

void Get_Common(linklist::LinkList *LA, linklist::LinkList *LB, linklist::LinkList *&LC) {
    LC = (linklist::LinkList *) malloc(sizeof(linklist::LinkList));
    linklist::LinkList *la, *lb, *s, *r;
    la = LA->next;
    lb = LB->next;
    r = LC;
    while (la->next != NULL && lb->next != NULL) {
        if (la->data < lb->data)
            la = la->next;
        else if (lb->data < la->data)
            lb = lb->next;
        if (la->data == lb->data) {
            s = (linklist::LinkList *) malloc(sizeof(linklist::LinkList));
            s->data = la->data;
            r->next = s;
            r = s;
            la = la->next;
            lb = lb->next;
        }
    }
    r->next = NULL;
}


int main() {
    std::cout << "Hello, World!" << std::endl;

    ElemType a[] = {7, 10, 10, 21, 30, 42, 42, 42, 51, 71};
    ElemType b[] = {7, 10, 10, 21, 30, 42, 42, 42, 51, 70};
    linklist::LinkList *LA;
    linklist::LinkList *LB;
    linklist::LinkList *LC;
    linklist::CreateListR(LA, a, 10);
    linklist::CreateListR(LB, b, 10);
    linklist::DispList(LA);
    Get_Common(LA, LB, LC);
    linklist::DispList(LC);
//    linklist::DispList(LB);
//    Delete_Same_2(LB);
//    linklist::DispList(LB);
    int temp;
    if (linklist::GetElem_Bottom_K(LC, 20, temp))
        std::cout << temp << std::endl;
//    DisCreate_1(L, LB);
//    linklist::DispList(L);
//    linklist::DispList(LB);
//    R_Print(L);
//    Del_X_3(L,1);
//    Del_X_1(L, 1);
//    DispList(L);

//    delete_same(L);
//    DispList(L);

//    ElemType a[] = {11, 13, 15, 17, 19};
//    ElemType b[] = {2, 4, 6, 8, 20};
//    int n = 5;
//    std::cout << M_Search(a, b, n) << std::endl;
//    std::cout << M_Search_2(a, b, n) << std::endl;
//    std::cout << M_Search_3(a, b, n) << std::endl;
//    std::cout << Majaority(a, 6) << std::endl;
    return 0;
}
