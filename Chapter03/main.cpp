//
// Created by expoli on 2020/9/6.
//

#include "SqStack/SqStack.h"
#include "LinkStack/LinkStack.h"
#include "iostream"

bool symmetry(char str[]) {
    int i;
    char e;
    sqstack::SqStack *st;
    sqstack::InitStack(st);

    for (i = 0; str[i] != '\0'; i++)
        sqstack::Push(st, str[i]);

    for (i = 0; str[i] != '\0'; i++) {
        sqstack::Pop(st, e);
        if (e != str[i]) {
            sqstack::DestroyStack(st);
            return false;
        }
    }
    sqstack::DestroyStack(st);
    return true;
}

bool Match(char exp[], int n) {
    int i = 0;
    char e;
    bool match = true;
    linkstack::LiStack *st;

    linkstack::InitStack(st);
    while (i < n && match) {
        if (exp[i] == '(')
            linkstack::Push(st, exp[i]);
        else if (exp[i] == ')') {
            if (linkstack::GetTop(st, e)) {
                if (e != '(')
                    match = false;
                else
                    linkstack::Pop(st, e);
            } else
                match = false;
        }
        i++;
    }
    if (st->next != NULL)
        match = false;

    linkstack::DestroyStack(st);
    return match;
}

// 双栈模拟队列
bool EnQueue(sqstack::SqStack *&S1, sqstack::SqStack *&S2, ElemType x) {
    ElemType temp;
    if (!sqstack::StackOverflow(S1)) {
        sqstack::Push(S1, x);
        return true;
    }
    if (sqstack::StackOverflow(S1) && !sqstack::StackEmpty(S2))
        return false;
    if (sqstack::StackOverflow(S1) && sqstack::StackEmpty(S2)) {
        while (sqstack::StackEmpty(S1)) {
            sqstack::Pop(S1, temp);
            sqstack::Push(S2, temp);
        }
    }
    sqstack::Push(S1, x);
    return true;
}

bool DeQueue(sqstack::SqStack *&S1, sqstack::SqStack *&S2, ElemType &x) {
    ElemType temp;
    if (!sqstack::StackEmpty(S2)) {
        sqstack::Pop(S2, x);
        return true;
    }
    if (sqstack::StackEmpty(S1))
        return false;
    if (sqstack::StackEmpty(S2) && !sqstack::StackEmpty(S1)) {
        while (!sqstack::StackEmpty(S1) && !sqstack::StackOverflow(S2)) {
            sqstack::Pop(S1, temp);
            sqstack::Push(S2, temp);
        }
    }
    sqstack::Pop(S2, x);
    return true;
}

int main() {
    char a[] = "abcdefg";
    char temp;
    sqstack::SqStack *stack1;
    sqstack::InitStack(stack1);
    sqstack::SqStack *stack2;
    sqstack::InitStack(stack2);

    for (int i = 0; a[i] != '\0'; i++) {
        EnQueue(stack1, stack2, a[i]);
    }
    for (int i = 0; i < 7; i++) {
        DeQueue(stack1, stack2, temp);
        std::cout << temp;
    }
}