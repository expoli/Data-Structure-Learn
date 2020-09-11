//
// Created by expoli on 2020/9/9.
//

#include "TBTree.h"
#include "iostream"

namespace tbtree {
    TBTNode *pre;

    void Thread(TBTNode *&p) {
        if (p != NULL) {
            Thread(p->lchild);
            if (p->lchild == NULL) {
                p->lchild = pre;
                p->ltag = 1;
            } else
                p->ltag = 0;
            if (pre->rchild == NULL) {
                pre->rchild = p;
                pre->rtag = 1;
            } else
                pre->rtag = 0;
            pre = p;
            Thread(p->rchild);
        }
    }

    TBTNode *CreateThread(TBTNode *tbtNode) {
        TBTNode *root;
        root = (TBTNode *) malloc(sizeof(TBTNode));
        root->ltag = 0;
        root->rtag = 1;
        root->rchild = tbtNode;
        if (tbtNode == NULL)
            root->lchild = root;
        else {
            root->lchild = tbtNode;
            pre = root;
            Thread(tbtNode);
            pre->rchild = root;
            pre->rtag = 1;
            root->rchild = pre;
        }
        return root;
    }

    // 中序线索遍历
    void ThInOrder(TBTNode *tbtNode) {
        TBTNode *p = tbtNode->lchild;
        while (p != tbtNode) {
            while (p->ltag == 0)
                p = p->lchild;
            std::cout << p->data;
            while (p->rtag = 1 && p->rchild != tbtNode) {
                p = p->rchild;
                std::cout << p->data;
            }
            p = p->rchild;
        }
    }

}