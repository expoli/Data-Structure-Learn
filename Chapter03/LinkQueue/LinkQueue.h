//
// Created by expoli on 2020/9/7.
//

#ifndef CHAPTER03_LINKQUEUE_H
#define CHAPTER03_LINKQUEUE_H

#define ElemType char

namespace linkqueue {
    // 数据节点
    typedef struct linknode {
        ElemType data;
        struct linknode *next;
    } LinkNode;

    // 头节点
    typedef struct {
        LinkNode *front;
        LinkNode *rear;
    } LiQueue;
}

#endif //CHAPTER03_LINKQUEUE_H
