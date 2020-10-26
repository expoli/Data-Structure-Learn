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

    void CreateBTNode(BTNode *&b, const char *str);

    void DestroyBT(BTNode *&btNode);

    BTNode *FindNode(BTNode *btNode, ElemType x);

    BTNode *LchildNode(BTNode *btNode);

    BTNode *RchildNode(BTNode *btNode);

    int BTNodeDepth(BTNode *btNode);

    int BtDepth(BTNode *btNode);

    int BtWidth(BTNode *btNode);

    bool IsComplete(BTNode *btNode);

    void DispBTNode(BTNode *btNode);

    void PreOrder(BTNode *btNode);

    void PostOrder(BTNode *btNode);

    void InOrder(BTNode *btNode);

    void PreOrder2(BTNode *btNode);

    void PostOrder2(BTNode *btNode);

    void InOrder2(BTNode *btNode);

    void LevelOrder(BTNode *btNode);

    int Nodes(BTNode *btNode);

    int LeafNodes(BTNode *btNode);

    void Copy(BTNode *btNode, BTNode *&t);

    void Swap(BTNode *btNode, BTNode *&t);

    int Level(BTNode *btNode, ElemType x, int h);

    void AllPath(BTNode *btNode);

    BTNode *CreateBT1(char *pre, char *in, int n);

    BTNode *CreateBT2(char *post, char *in, int n);

    int dnodes(BTNode *btNode);

    void KLevelNumber(BTNode *btNode, int h, int k, int *&n);

    void levelnumber(BTNode *btNode, int h, int a[]);

    int BTWidth1(BTNode *b);

    int BTWidth2(BTNode *b);
}

#endif //CHAPTER05_BTREE_H
