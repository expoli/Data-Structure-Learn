//
// Created by expoli on 2020/9/9.
//

#ifndef CHAPTER05_TBTREE_H
#define CHAPTER05_TBTREE_H
#define ElemType char

namespace threadtree {
    typedef struct ThreadNode {
        ElemType data;
        int ltag, rtag;
        struct ThreadNode *lchild;
        struct ThreadNode *rchild;
    } ThreadNode, ThreadTree;

    void InThread(ThreadTree *&p, ThreadTree *&pre);

    ThreadNode *CreateInThreadTree(ThreadNode *threadNode);

    void InThreadOrder(ThreadNode *threadTree);
}

#endif //CHAPTER05_TBTREE_H
