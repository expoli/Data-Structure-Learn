//
// Created by expoli on 2020/9/9.
//

#include "TBTree.h"
#include "iostream"

namespace threadtree {

    // 中序线索化
    void InThread(ThreadTree *&p, ThreadTree *&pre) {
        if (p != nullptr) {
            InThread(p->lchild, pre);
            if (p->lchild == nullptr) {
                p->lchild = pre;
                p->ltag = 1;
            } else
                p->ltag = 0;
            if (pre->rchild == nullptr) {
                pre->rchild = p;
                pre->rtag = 1;
            } else
                pre->rtag = 0;
            pre = p;
            InThread(p->rchild, pre);
        }
    }

    void PreThread(ThreadTree *&p, ThreadNode *&pre) {
        if (p != nullptr) {
            if (p->lchild == nullptr) {
                p->lchild = pre;
                p->ltag = 1;
            } else
                p->ltag = 0;
            if (pre->rchild == nullptr) {
                pre->rchild = p;
                pre->rtag = 1;
            } else
                pre->rtag = 0;
            pre = p;
            PreThread(p->lchild, pre);
            PreThread(p->rchild, pre);
        }
    }
    //
    //    void PostThread(ThreadTree *&p, ThreadNode *&pre) {
    //        if (p != nullptr) {
    //            PreThread(p->lchild, pre);
    //            PreThread(p->rchild, pre);
    //            if (p->lchild == nullptr) {
    //                p->lchild = pre;
    //                p->ltag = 1;
    //            } else
    //                p->ltag = 0;
    //            if (pre->rchild == nullptr) {
    //                pre->rchild = p;
    //                pre->rtag = 1;
    //            } else
    //                pre->rtag = 0;
    //            pre = p;
    //        }
    //    }

    // 带头结点的线索二叉树
    ThreadNode *CreateInThreadTree(ThreadNode *threadNode) {
        ThreadNode *root, *pre;
        root = (ThreadNode *) malloc(sizeof(ThreadNode));
        root->ltag = 0;
        root->rtag = 1;
        root->rchild = threadNode;
        if (threadNode == nullptr)
            root->lchild = root;
        else {
            root->lchild = threadNode;
            pre = root;
            InThread(threadNode, pre);
            pre->rchild = root;
            pre->rtag = 1;
            root->rchild = pre;
        }
        return root;
    }

    // 中序线索遍历
    void InThreadOrder(ThreadNode *threadTree) {
        ThreadNode *p = threadTree->lchild;
        while (p != threadTree) {
            while (p->ltag == 0)
                p = p->lchild;
            std::cout << p->data;
            while (p->rtag == 1 && p->rchild != threadTree) {// 后继线索节点
                p = p->rchild;
                std::cout << p->data;
            }
            p = p->rchild;
        }
    }

}// namespace threadtree