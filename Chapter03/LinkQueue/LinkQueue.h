//
// Created by expoli on 2020/9/7.
//

#ifndef CHAPTER03_LINKQUEUE_H
#define CHAPTER03_LINKQUEUE_H

#define ElemType char

namespace linkqueue {
    // 数据节点
    typedef struct qnode {
        ElemType data;
        struct qnode *next;
    } QNode;

    // 头节点
    typedef struct {
        QNode *front;
        QNode *rear;
    } LiQueue;
}

#endif //CHAPTER03_LINKQUEUE_H
