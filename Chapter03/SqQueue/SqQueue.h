//
// Created by expoli on 2020/9/7.
//

#ifndef CHAPTER03_SQQUEUE_H
#define CHAPTER03_SQQUEUE_H

namespace sqqueue {
#define MAXSIZE 30
#define ElemType char
    typedef struct {
        ElemType data[MAXSIZE];
        int front, rear;
    } SqQueue;
}

namespace cirqueue {
    typedef struct {
        ElemType data[MAXSIZE];
        int front;
        int count;
    } CirQueue;
}

#endif //CHAPTER03_SQQUEUE_H
