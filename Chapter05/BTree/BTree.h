//
// Created by expoli on 2020/9/9.
//

#ifndef CHAPTER05_BTREE_H
#define CHAPTER05_BTREE_H
#define ElemType char
namespace btree {
    typedef struct node {
        ElemType data;
        struct node *lchild, *rchild;
    } BTNode;
}

#endif //CHAPTER05_BTREE_H
