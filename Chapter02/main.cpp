#include "DLinkList/DLinkList.h"
#include "LinkList/LinkList.h"
#include "SqList/SqList.h"
#include <iostream>

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

void Del_X_1(linklist::LinkList *&L, ElemType x) {
    linklist::LinkList *pre, *p;
    pre = L;
    p = L->next;
    while (p != nullptr) {
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

void Del_X_2(linklist::LinkList *&L, ElemType x) {
    linklist::LinkList *p;
    if (L->next == nullptr)
        return;
    if (L->next->data == x) {
        p = L->next;
        L->next = p->next;
        free(p);
        Del_X_2(L, x);
    }
    Del_X_2(L->next, x);
}

void Del_X_3(linklist::LinkList *&L, ElemType x) {
    linklist::LinkList *p;
    if (L == nullptr)
        return;
    if (L->data == x) {
        p = L;
        L = L->next;
        free(p);
        Del_X_3(L, x);
    } else
        Del_X_3(L->next, x);
}

// 当单链表带头节点时，L应为头指针
// R_Print(LA->next);
void R_Print(linklist::LinkList *L) {
    if (L->next != nullptr)
        R_Print(L->next);
    std::cout << L->data << " ";
}

// 当单链表带头节点时，L应为头指针
// R_Print(LA->next);
void R_Print_1(linklist::LinkList *L) {
    if (L == nullptr)
        return;
    R_Print_1(L->next);
    std::cout << L->data << " ";
}

void Reverse_1(linklist::LinkList *&L) {
    linklist::LinkList *p, *r;
    p = L->next;
    L->next = nullptr;
    while (p != nullptr) {
        r = p->next;
        p->next = L->next;
        L->next = p;
        p = r;
    }
}

void Reverse_2(linklist::LinkList *&L) {
    linklist::LinkList *pre, *p = L->next, *r = p->next;
    p->next = nullptr;
    while (r != nullptr) {
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
    L->next = nullptr;
    while (p->next != nullptr) {
        q = p->next;
        p->next = L->next;
        L->next = p;
        p = q;
    }
    p->next = L->next;
    L->next = p;
}

void Sort(linklist::LinkList *&L) {
    linklist::LinkList *pre, *p, *r;
    // 创建只有一个数据结点的表
    p = L->next;
    r = p->next;
    p->next = nullptr;
    p = r;
    while (p != nullptr) {
        r = p->next;
        pre = L;
        while (pre->next != nullptr && pre->next->data < p->data)
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
    while (p != nullptr) {
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

// 获取两个链表的公共结点
bool Get_First_Common_Node(linklist::LinkList *LA, linklist::LinkList *LB, linklist::LinkList *&e) {
    linklist::LinkList *longlist = LA->next, *shortlist = LB->next;
    int len1 = 0, len2 = 0, dist = 0;
    while (longlist != nullptr) {
        longlist = longlist->next;
        len1++;
    }
    while (shortlist != nullptr) {
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
    while (shortlist != nullptr && longlist != nullptr) {
        if (shortlist == longlist) {
            e = shortlist;
            return true;
        } else {
            longlist = longlist->next;
            shortlist = shortlist->next;
        }
    }
    e = nullptr;
    return false;
}

bool Get_First_Common_Node_1(linklist::LinkList *LA, linklist::LinkList *LB, linklist::LinkList *&e) {
    Reverse_1(LA);
    Reverse_1(LB);
    linklist::LinkList *pa = LA->next, *pb = LB->next;
    while (pa == pb) {
        pa = LA->next;
        pb = LB->next;
        e = pa;
    }
}

void Min_Delete(linklist::LinkList *&head) {
    linklist::LinkList *p, *pre, *u;
    while (head->next != nullptr) {
        pre = head;
        p = pre->next;
        while (p->next != nullptr) {
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
    while (p != nullptr) {
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
    la->next = nullptr;
    lb->next = nullptr;
}

void Delete_Same_1(linklist::LinkList *&L) {
    linklist::LinkList *p, *q;
    p = L->next;
    if (p == nullptr)
        return;
    q = p->next;
    while (q != nullptr) {
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
    while (p != nullptr) {
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
    LA->next = nullptr;
    while (pa != nullptr && pb != nullptr) {
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
    while (pa != nullptr) {
        q = pa->next;
        pa->next = LA->next;
        LA->next = pa;
        pa = q;
    }
    while (pb != nullptr) {
        q = pb->next;
        pb->next = LA->next;
        LA->next = pb;
        pb = q;
    }
    free(LB);
}

// 获取两个有序单链表中大小相等的元素
void Get_Common_ElemType(linklist::LinkList *LA, linklist::LinkList *LB, linklist::LinkList *&LC) {
    LC = (linklist::LinkList *) malloc(sizeof(linklist::LinkList));
    linklist::LinkList *la, *lb, *s, *r;
    la = LA->next;
    lb = LB->next;
    r = LC;
    while (la->next != nullptr && lb->next != nullptr) {
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
    r->next = nullptr;
}

bool Pattern(linklist::LinkList *LA, linklist::LinkList *LB) {
    linklist::LinkList *la = LA->next;
    linklist::LinkList *pre = la;
    linklist::LinkList *lb = LB->next;
    while (la && lb) {
        if (la->next == lb->next) {
            la = la->next;
            lb = lb->next;
        } else {
            la = pre->next;
            pre = la;
            lb = LB;
        }
    }
    if (la == nullptr)
        return false;
    else
        return true;
}

int main() {
    std::cout << "Hello, World!" << std::endl;

    ElemType a[] = {7, 10, 10, 21, 30, 42, 42, 42, 51, 71};
    ElemType b[] = {7, 10, 10, 21, 30, 42, 42, 42, 51, 70};
    linklist::LinkList *LA;
    linklist::LinkList *LB;
    linklist::LinkList *LC;
    linklist::CreateListR(LA, a, 10);
    linklist::CreateListR(LB, a, 5);
    linklist::CreateListR(LC, a, 10);
    linklist::LinkList *p = LB->next;
    while (p->next != nullptr) {
        p = p->next;
    }
    p->next = LA->next->next->next->next->next;
    linklist::DispList(LA);
    //    Get_Common(LA, LB, LC);
    linklist::DispList(LB);
    linklist::DispList(LC);
    //    linklist::DispList(LB);
    //    Delete_Same_2(LB);
    //    linklist::DispList(LB);
    //    int temp;
    //    if (linklist::GetElem_Bottom_K(LC, 20, temp))
    //        std::cout << temp << std::endl;
    //    DisCreate_1(L, LB);
    //    linklist::DispList(L);
    //    linklist::DispList(LB);
    linklist::LinkList *e;
    Get_First_Common_Node(LA, LB, e);
    std::cout << e << std::endl;
    Get_First_Common_Node_1(LA, LB, e);

    std::cout << e << std::endl;
    linklist::DispList(LA);
    //    Get_Common(LA, LB, LC);
    linklist::DispList(LB);
    linklist::DispList(LC);
    //    Del_X_3(LA,10);
    //    linklist::DispList(LA);
    //    Del_X_2(LB,7);
    //    linklist::DispList(LB);
    //    Del_X_1(LC, 10);
    //    linklist::DispList(LC);
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
