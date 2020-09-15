//
// Created by expoli on 2020/9/9.
//

#ifndef CHAPTER05_TBTREE_H
#define CHAPTER05_TBTREE_H
#define ElemType char

namespace tbtree {
    typedef struct node {
        ElemType data;
        int ltag, rtag;
        struct node *lchild;
        struct node *rchild;
    } TBTNode;
}

#endif //CHAPTER05_TBTREE_H
