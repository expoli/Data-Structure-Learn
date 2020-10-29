//
// Created by expoli on 2020/9/6.
//

#ifndef CHAPTER03_SQSTACK_H
#define CHAPTER03_SQSTACK_H


namespace sqstack {
#define ElemType char
#define MAXSIZE 30
    typedef struct SqStack {
        ElemType data[MAXSIZE];
        int top;
    } SqStack;

    void InitStack(SqStack *&s);

    void DestroyStack(SqStack *&s);

    bool StackEmpty(SqStack *s);

    bool Push(SqStack *&s, ElemType e);

    bool Pop(SqStack *&s, ElemType &e);

    bool GetTop(SqStack *s, ElemType &e);

    bool StackOverflow(SqStack *s);
}// namespace sqstack

#endif//CHAPTER03_SQSTACK_H
