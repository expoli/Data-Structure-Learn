//
// Created by expoli on 2020/9/9.
//

#include "BTree/BTree.h"
#include "ThreadBTree/TBTree.h"
#include "iostream"

ElemType KValue(btree::BTNode *btNode, int k) {
    ElemType leftValue, rightValue;
    if (btNode == nullptr)
        return '#';
    if (k == 1)
        return btNode->data;
    leftValue = KValue(btNode->lchild, k - 1);
    if (leftValue != '#')
        return leftValue;
    rightValue = KValue(btNode->rchild, k - 1);
    return rightValue;
}

int KLevelNumber(btree::BTNode *btNode, int k) {
    int MAXSIZE = 20;
    btree::BTNode *qu[MAXSIZE], *p;
    if (btNode == nullptr)
        return 0;
    if (k < 0)
        return 0;
    int front = -1, rear = -1, last = 0, level = 0, number = 0;
    qu[++rear] = btNode;
    while (front < rear) {
        p = qu[++front];
        if (p->lchild != nullptr) {
            if (level + 1 == k - 1)
                number++;
            qu[++rear] = p->lchild;
        }
        if (p->rchild != nullptr) {
            if (level + 1 == k - 1)
                number++;
            qu[++rear] = p->rchild;
        }
        if (front == last) {
            level++;
            last = rear;
        }
        if (level > k)
            break;
    }
    return number;
}

void Swap1(btree::BTNode *btNode) {
    if (btNode) {
        Swap1(btNode->lchild);
        Swap1(btNode->rchild);
        btree::BTNode *temp;
        temp = btNode->lchild;
        btNode->lchild = btNode->rchild;
        btNode->rchild = temp;
    }
}

void Swap2(btree::BTNode *btNode) {
    if (btNode) {
        btree::BTNode *temp;
        temp = btNode->lchild;
        btNode->lchild = btNode->rchild;
        btNode->rchild = temp;
        Swap2(btNode->lchild);
        Swap2(btNode->rchild);
    }
}

void SearchXParent1(btree::BTNode *btNode, ElemType x) {
    typedef struct {
        btree::BTNode *t;
        int tag;
    } stack;

    stack s[30];
    int top = 0;
    btree::BTNode *p = btNode;
    while (p != nullptr || top > 0) {
        while (p != nullptr && p->data != x) {
            s[++top].t = p;
            s[top].tag = 0;
            p = p->lchild;
        }
        if (top != 0) {
            s[top].tag = 1;
            p = s[top].t->rchild;
        }
        if (p != nullptr && p->data == x) {
            std::cout << "所查节点的祖先为：";
            for (int i = 1; i <= top; i++) {
                std::cout << s[i].t->data;
            }
            return;
        }
        while (top != 1 && s[top].tag == 1)
            top--;
    }
}

void SearchXParent2(btree::BTNode *btNode, ElemType x) {
    typedef struct {
        btree::BTNode *b;
        int parent;
    } Queue;

    Queue qu[30];
    btree::BTNode *p;
    int front = -1, rear = -1, lnum = 0;
    qu[++rear].b = btNode;
    qu[rear].parent = -1;
    while (front < rear) {
        p = qu[++front].b;
        if (p->lchild != nullptr) {
            qu[++rear].b = p->lchild;
            qu[rear].parent = front;
        }
        if (p->rchild != nullptr) {
            qu[++rear].b = p->rchild;
            qu[rear].parent = front;
        }
        if (p->data == x) {
            std::cout << "所查节点的祖先为：";
            lnum = front;
            while (qu[lnum].parent != -1) {
                lnum = qu[lnum].parent;
                std::cout << qu[lnum].b->data;
            }
            return;
        }
    }

}

int main(void) {
    char str1[] = "A(B(D(,G)),C(E,F))";
    btree::BTNode *Tree1;
    btree::CreateBTNode(Tree1, str1);
    btree::DispBTNode(Tree1);
    std::cout << std::endl;

    std::cout << "PreOrder:\t";
    btree::PreOrder(Tree1);
    std::cout << std::endl;

    std::cout << "PreOrder2:\t";
    btree::PreOrder2(Tree1);
    std::cout << std::endl;

    std::cout << "InOrder:\t";
    btree::InOrder(Tree1);
    std::cout << std::endl;

    std::cout << "InOrder2:\t";
    btree::InOrder2(Tree1);
    std::cout << std::endl;

    std::cout << "PostOrder:\t";
    btree::PostOrder(Tree1);
    std::cout << std::endl;

    std::cout << "PostOrder2:\t";
    btree::PostOrder2(Tree1);
    std::cout << std::endl;

    std::cout << "Swap" << std::endl;
    Swap1(Tree1);
    btree::PreOrder(Tree1);
    Swap2(Tree1);
    btree::PreOrder(Tree1);
    std::cout << std::endl;

    std::cout << btree::BtWidth(Tree1);

    SearchXParent1(Tree1, 'F');
    SearchXParent2(Tree1, 'F');

//    std::cout << btree::dnodes(Tree1) << std::endl;
//    std::cout << btree::LeafNodes(Tree1) << std::endl;
//
//    std::cout << KValue(Tree1, 3) << std::endl;
//
//    std::cout<<btree::IsComplete(Tree1)<<std::endl;
//
//    btree::AllPath(Tree1);
//
//    std::cout<<KLevelNumber(Tree1,3)<<std::endl;

//    std::cout<<btree::BtDepth(Tree1)<<std::endl;
}