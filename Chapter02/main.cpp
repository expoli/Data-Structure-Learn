#include <iostream>
#include "SqList/SqList.h"

bool delete_same(SqlList *&L) {
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

int main() {
    std::cout << "Hello, World!" << std::endl;

    ElemType a[] = {1, 1, 1, 1, 2, 7};
//    SqlList *L;
//    CreateList(L, a, 11);
//    DispList(L);
//    delete_same(L);
//    DispList(L);

//    ElemType a[] = {11, 13, 15, 17, 19};
    ElemType b[] = {2, 4, 6, 8, 20};
    int n = 5;
//    std::cout << M_Search(a, b, n) << std::endl;
//    std::cout << M_Search_2(a, b, n) << std::endl;
//    std::cout << M_Search_3(a, b, n) << std::endl;
    std::cout << Majaority(a, 6) << std::endl;
    return 0;
}
