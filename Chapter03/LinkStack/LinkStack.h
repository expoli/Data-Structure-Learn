//
// Created by expoli on 2020/9/6.
//

#ifndef CHAPTER03_LINKSTACK_H
#define CHAPTER03_LINKSTACK_H

namespace linkstack {
#define ElemType char
    typedef struct linknode {
        ElemType data;
        struct linknode *next;
    } LiStack;

    void InitStack(LiStack *&stack);

    void DestroyStack(LiStack *&stack);

    bool StackEmpty(LiStack *stack);

    void Push(LiStack *&stack, ElemType e);

    bool Pop(LiStack *&stack, ElemType &e);

    bool GetTop(LiStack *Stack, ElemType &e);

}

#endif //CHAPTER03_LINKSTACK_H
