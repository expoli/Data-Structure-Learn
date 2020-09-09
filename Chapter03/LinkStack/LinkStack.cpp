//
// Created by expoli on 2020/9/6.
//

#include "LinkStack.h"
#include "iostream"

namespace linkstack {
    void InitStack(LiStack *&stack) {
        stack = (LiStack *) malloc(sizeof(LiStack));
        stack->next = NULL;
    }

    void DestroyStack(LiStack *&stack) {
        LiStack *p = stack, *q = stack->next;
        while (q != NULL) {
            free(p);
            p = q;
            q = p->next;
        }
        free(p);
    }

    bool StackEmpty(LiStack *stack) {
        return stack->next == NULL;
    }

    void Push(LiStack *&stack, ElemType e) {
        LiStack *s;
        s = (LiStack *) malloc(sizeof(LiStack));
        s->data = e;
        s->next = stack->next;
        stack->next = s;
    }

    bool Pop(LiStack *&stack, ElemType &e) {
        LiStack *p;
        if (stack->next == NULL)
            return false;
        p = stack->next;
        e = p->data;
        stack->next = p->next;
        free(p);
        return true;
    }

    bool GetTop(LiStack *stack, ElemType &e) {
        if (stack->next == NULL)
            return false;
        e = stack->next->data;
        return true;
    }
}