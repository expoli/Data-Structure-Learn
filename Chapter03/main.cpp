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

int main() {
    char a[10] = {'a', 'b', 'c', 'b', 'a'};
    sqstack::SqStack *stack;
    sqstack::InitStack(stack);
    std::cout << symmetry(a);

    char b[10] = "())()()()";
    std::cout << Match(b, 8);
    char c[10] = "((()))";
    std::cout << Match(c, 6);
}