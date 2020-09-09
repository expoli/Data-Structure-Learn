//
// Created by expoli on 2020/9/9.
//

#include "BTree.h"
#include "iostream"

#define MAXSIZE 30

namespace btree {
    void CreateBTNode(BTNode *&b, char *str) {
        BTNode *St[MAXSIZE], *p;
        int top = -1, k, j = 0;
        char ch;
        b = NULL;
        ch = str[j];
        while (ch != '\0') {
            switch (ch) {
                case '(':
                    top++;
                    St[top] = p;
                    k = 1;
                    break;
                case ')':
                    top--;
                    break;
                case ',':
                    k = 2;
                    break;
                default:
                    p = (BTNode *) malloc(sizeof(BTNode));
                    p->data = ch;
                    p->lchild = p->rchild = NULL;
                    if (b == NULL)
                        b = p;
                    else {
                        switch (k) {
                            case 1:
                                St[top]->lchild = p;
                                break;
                            case 2:
                                St[top]->rchild = p;
                                break;
                        }
                    }
            }
            ch = str[++j];
        }
    }

    void DestroyBT(BTNode *&btNode) {
        if (btNode == NULL)
            return;
        else {
            DestroyBT(btNode->lchild);
            DestroyBT(btNode->rchild);
            free(btNode);
        }
    }

    BTNode *FindNode(BTNode *btNode, ElemType x) {
        BTNode *p;
        if (btNode == NULL)
            return NULL;
        else {
            if (btNode->data == x)
                return btNode;
            else {
                p = FindNode(btNode->lchild, x);
                if (p != NULL)
                    return p;
                else
                    return FindNode(btNode->rchild, x);
            }
        }
    }

    BTNode *LchildNode(BTNode *btNode) {
        return btNode->lchild;
    }

    BTNode *RchildNode(BTNode *btNode) {
        return btNode->rchild;
    }

    int BTNodeDepth(BTNode *btNode) {
        int lchilddep, rchilddep;
        if (btNode == NULL)
            return 0;
        else {
            lchilddep = BTNodeDepth(btNode->lchild);
            rchilddep = BTNodeDepth(btNode->rchild);
            return (lchilddep > rchilddep) ? (lchilddep + 1) : (rchilddep + 1);
        }
    }

    void DispBTNode(BTNode *btNode) {
        if (btNode == NULL)
            return;
        else {
            std::cout << btNode->data;
            if (btNode->lchild != NULL || btNode->rchild != NULL) {
                std::cout << '(';
                DispBTNode(btNode->lchild);
                if (btNode->rchild != NULL)
                    std::cout << ',';
                DispBTNode(btNode->rchild);
                std::cout << ')';
            }
        }
    }

    // 二叉树的遍历
    // 先序遍历
    void PreOrder(BTNode *btNode) {
        if (btNode != NULL) {
            std::cout << btNode->data;
            PreOrder(btNode->lchild);
            PreOrder(btNode->rchild);
        }
    }

    // 后序遍历
    void PostOrder(BTNode *btNode) {
        if (btNode != NULL) {
            PostOrder(btNode->lchild);
            PostOrder(btNode->rchild);
            std::cout << btNode->data;
        }
    }

    // 中序遍历
    void InOrder(BTNode *btNode) {
        if (btNode != NULL) {
            InOrder(btNode->lchild);
            std::cout << btNode->data;
            InOrder(btNode->rchild);
        }
    }

    // 层次遍历
    void LevelOrder(BTNode *btNode) {
        // 定义一个环形队列
        BTNode *p;
        BTNode *qu[MAXSIZE];
        int front, rear;
        front = rear = 0;
        if (btNode == NULL)
            return;
        rear = (rear + 1) % MAXSIZE;
        qu[rear] = btNode;
        while (rear != front) {
            front++;
            p = qu[front];
            std::cout << p->data;
            if (p->lchild != NULL) {
                rear = (rear + 1) % MAXSIZE;
                qu[rear] = p->lchild;
            }
            if (p->rchild != NULL) {
                rear = (rear + 1) % MAXSIZE;
                qu[rear] = p->rchild;
            }
        }
    }

    int Nodes(BTNode *btNode) {
        if (btNode == NULL)
            return 0;
        else
            return Nodes(btNode->lchild) + Nodes(btNode->rchild) + 1;
    }

    int LeafNodes(BTNode *btNode) {
        if (btNode == NULL)
            return 0;
        else if (btNode->rchild == NULL && btNode->lchild == NULL) {
            return LeafNodes(btNode->lchild) + LeafNodes(btNode->rchild) + 1;
        }
    }

    void Copy(BTNode *btNode, BTNode *&t) {
        if (btNode == NULL)
            t = NULL;
        else {
            t = (BTNode *) malloc(sizeof(BTNode));
            t->data = btNode->data;
            Copy(btNode->lchild, t->lchild);
            Copy(btNode->rchild, t->rchild);
        }
    }

    void Swap(BTNode *btNode, BTNode *&t) {
        if (btNode == NULL)
            t = NULL;
        else {
            t = (BTNode *) malloc(sizeof(BTNode));
            t->data = btNode->data;
            Swap(btNode->lchild, t->rchild);
            Swap(btNode->rchild, t->lchild);
        }
    }

    int Level(BTNode *btNode, ElemType x, int h) {
        int l = 0;
        if (btNode == NULL)
            return 0;
        else if (btNode->data == x)
            return h;
        else {
            l = Level(btNode->lchild, x, h + 1);
            if (l == 0)
                return Level(btNode->rchild, x, h + 1);
            else
                return l;
        }
    }

    void AllPath(BTNode *btNode) {
        if (btNode == NULL)
            return;
        struct snode {
            BTNode *node;
            int parent;
        } qu[MAXSIZE];

        BTNode *q;
        int front, rear, p;
        front = rear = -1;
        rear++;
        qu[rear].node = btNode;
        qu[rear].parent = -1;
        while (front != rear) {
            front++;
            q = qu[front].node;
            if (q->rchild == NULL && q->lchild == NULL) {
                p = front;
                while (qu[p].parent != -1) {
                    std::cout << qu[p].node->data;
                    p = qu[p].parent;
                }
            }
            if (q->lchild != NULL) {
                rear++;
                qu[rear].node = q->lchild;
                qu[rear].parent = front;
            }
            if (q->rchild != NULL) {
                rear++;
                qu[rear].node = q->rchild;
                qu[rear].parent = front;
            }
        }
    }

    BTNode *CreateBT1(char *pre, char *in, int n) {
        BTNode *s;
        char *p;
        int k;
        if (n <= 0)
            return NULL;
        s = (BTNode *) malloc(sizeof(BTNode));
        s->data = *pre;
        for (p = in; p < in + n; p++)
            if (*p == *pre)
                break;

        k = p - in;
        s->lchild = CreateBT1(pre + 1, in, k);
        s->rchild = CreateBT1(pre + k + 1, p + 1, n - k - 1);
    }

    BTNode *CreateBT2(char *post, char *in, int n) {
        BTNode *b;
        char r, *p;
        int k;
        if (n <= 0)
            return NULL;
        r = *(post + n - 1);
        b = (BTNode *) malloc(sizeof(BTNode));
        b->data = r;
        for (p = in; p < in; p++)
            if (*p == r)
                break;
        k = p - in;
        b->lchild = CreateBT2(post, in, k);
        b->rchild = CreateBT2(post, p + 1, n - k - 1);
    }

    int dnodes(BTNode *btNode) {
        if (btNode == NULL)
            return 0;
        if (btNode->lchild == NULL && btNode->rchild == NULL)
            return 1 + dnodes(btNode->lchild) + dnodes(btNode->rchild);
        else
            return dnodes(btNode->lchild) + dnodes(btNode->rchild);
    }

    void KLevelNumber(BTNode *btNode, int h, int k, int *&n) {
        if (btNode == NULL)
            return;
        else {
            if (h == k)
                n++;
            else if (h < k) {
                KLevelNumber(btNode->lchild, h + 1, k, n);
                KLevelNumber(btNode->rchild, h + 1, k, n);
            }
        }
    }

    void levelnumber(BTNode *btNode, int h, int a[]) {
        if (btNode == NULL)
            return;
        else {
            a[h]++;
            levelnumber(btNode->lchild, h + 1, a);
            levelnumber(btNode->rchild, h + 1, a);
        }
    }

    int BTWidth1(BTNode *b) {
        int width = 0, i;
        int a[MAXSIZE];
        for (i = 0; i < MAXSIZE; i++)
            a[i] = 0;
        levelnumber(b, 1, a);
        i = 1;
        while (a[i] != 0) {
            if (a[i] > width)
                width = a[i];
            i++;
        }
        return width;
    }

    int BTWidth2(BTNode *b) {
        struct {
            int lno;
            BTNode *p;
        } Qu[MAXSIZE];

        int front, rear, lnum;
        front = rear = 0;

        if (b != NULL) {
            rear++;
            Qu[rear].p = b;
            Qu[rear].lno = 1;
            while (rear != front) {
                front++;
                b = Qu[front].p;
                lnum = Qu[front].lno;
                if (b->lchild != NULL) {
                    rear++;
                    Qu[rear].p = b->lchild;
                    Qu[rear].lno = lnum + 1;
                }
                if (b->rchild != NULL) {
                    rear++;
                    Qu[rear].p = b->rchild;
                    Qu[rear].lno = lnum;
                }
            }
            int width = 0, i = 1;
            lnum = 1;
            while (i <= rear) {
                i++;
                int n = 0;
                int j = 0;
                while (j <= rear && Qu[j].lno == lnum) {
                    n++;
                    j++;
                }
                lnum = Qu[i].lno;
                if (n > width)
                    width = n;
            }
            return width;
        } else return 0;
    }
}