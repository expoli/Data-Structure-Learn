//
// Created by expoli on 2020/9/13.
//

#include "MGraph.h"
#include "iostream"

namespace graph {

    void DFSTraverse(ALGraph *alGraph) {
        int visited[MaxVertexNum];
        for (int i = 0; i < alGraph->vexnum; ++i) {// 从0开始
            visited[i] = 0;
        }
        for (int i = 0; i < alGraph->vexnum; ++i) {// 从零号顶点开始遍历
            if (!visited[i])
                DFS(alGraph, i, visited);
        }
    }

    void DFS(ALGraph *Graph, int v, int visited[]) {// 与先序遍历类似
        ArcNode *p;                                 // 临时弧结点
        int w;                                      // 临时顶点
        visited[v] = 1;                             // 标记数组
        std::cout << v;                             // 访问顶点
        p = Graph->adjlist[v].firstarc;             // 查找与该顶点相连的弧
        while (p != nullptr) {                      // 当弧存在时
            w = p->adjvex;                          // 准备访问与弧相连的顶点
            if (visited[w] == 0)                    // 若此顶点还没被访问
                DFS(Graph, w, visited);             // 递归访问该顶点
            p = p->nextarc;                         // 查找还未被访问的顶点
        }
    }
    // 深度优先非递归算法
    void DFS_Non_RC(ALGraph *alGraph, int v) {
        int w, top = -1;
        ArcNode *p;
        int visited[MaxVertexNum];
        int Stack[MaxVertexNum];
        for (int i = 0; i < alGraph->vexnum; ++i) {
            visited[i] = 0;
        }
        Stack[++top] = v;
        visited[v] = 1;
        while (top != -1) {
            w = Stack[top--];
            std::cout << alGraph->adjlist[w].data;
            p = alGraph->adjlist->firstarc;
            while (p != nullptr) {
                p = p->nextarc;
                if (visited[p->adjvex] == 0) {// 若还未访问，则顶点入栈
                    visited[p->adjvex] = 1;   // 置访问标志、防止再次入栈
                    Stack[++top] = p->adjvex; // 将所有可能访问的顶点进栈
                }
            }
        }
    }

    void BFSTraverse(ALGraph *alGraph) {
        int visited[MaxVertexNum];// 访问标记数据
        for (int i = 0; i < alGraph->vexnum; ++i) {
            visited[i] = 0;
        }
        for (int i = 0; i < alGraph->vexnum; ++i) {
            if (visited[i] == 0)
                BFS(alGraph, i, visited);
        }
    }
    // 广度优先搜索
    void BFS(ALGraph *Graph, int v, int visited[]) {
        ArcNode *p;
        int w, i;
        int queue[MaxVertexNum], front = 0, rear = 0;// 定义循环队列
        for (i = 0; i < Graph->vexnum; i++) {        // 初始化标记数组
            visited[i] = 0;
        }
        std::cout << v;                              // 访问结点
        rear = (rear + 1) % MaxVertexNum;            // rear +1
        queue[rear] = v;                             // 顶点入队
        while (front != rear) {                      // 循环队列不空时
            front = (front + 1) % MaxVertexNum;      // 出队
            w = queue[front];                        // 队首顶点
            p = Graph->adjlist[w].firstarc;          // 顶点第一条弧
            while (p != nullptr) {                   // 当弧存在时
                if (visited[p->adjvex] == 0) {       // 如果此顶点还未被访问
                    std::cout << p->adjvex;          // 访问该弧所指顶点
                    visited[p->adjvex] = 1;          // 置访问标志
                    rear = (rear + 1) % MaxVertexNum;// 准备入队
                    queue[rear] = p->adjvex;         // 该弧所指顶点入队
                }
                p = p->nextarc;// 开始处理下一条弧
            }
        }
    }

    void BFS1(ALGraph *Graph, int visited[]) {
        int i;
        for (i = 0; i < Graph->vexnum; i++)
            if (visited[i] == 0)
                BFS1(Graph, visited);
    }

    bool Connect(ALGraph *Graph, int visited[]) {
        int i;
        bool flag = true;
        for (i = 0; i < Graph->vexnum; i++)
            visited[i] = 0;
        DFS(Graph, 0, visited);
        for (i = 0; i < Graph->vexnum; i++) {
            if (visited[i] == 0) {
                flag = false;
                break;
            }
        }
        return flag;
    }

    void ExistPath(ALGraph *Graph, int u, int v, bool &has, int visited[]) {
        int w;
        ArcNode *p;
        if (u == v) {
            has = true;
            return;
        }
        p = Graph->adjlist[u].firstarc;
        while (p != nullptr) {
            w = p->adjvex;
            if (visited[w] == 0)
                ExistPath(Graph, w, v, has, visited);
            p = p->nextarc;
        }
    }

    void FindAPath(ALGraph *Graph, int u, int v, int path[], int d, int visited[]) {
        int w, i;
        ArcNode *p;
        visited[u] = 1;
        path[++d] = u;
        if (u == v) {
            std::cout << "一条简单路径为：" << std::endl;
            for (i = 0; i < d; i++)
                std::cout << path[i];
            std::cout << std::endl;
            return;
        }
        p = Graph->adjlist[u].firstarc;
        while (p != nullptr) {
            w = p->adjvex;
            if (visited[w] == 0) {
                FindAPath(Graph, w, v, path, d, visited);
            }
            p = p->nextarc;
        }
    }

    void FindPath(ALGraph *Graph, int u, int v, int path[], int d, int visited[]) {
        int w, i;
        ArcNode *p;
        path[++d] = u;
        visited[u] = 1;
        if (u == v) {
            for (i = 0; i < d; i++)
                std::cout << path[i];
            std::cout << std::endl;
            return;
        }
        p = Graph->adjlist[u].firstarc;
        while (p != nullptr) {
            w = p->adjvex;
            if (visited[w] == 0)
                FindPath(Graph, w, v, path, d, visited);
            p = p->nextarc;
        }
        visited[u] = 0;// 恢复环境使该节点可用
    }

    void PathAll(ALGraph *Graph, int u, int v, int l, int path[], int d, int visited[]) {
        int w, i;
        ArcNode *p;
        path[++d] = u;
        visited[u] = 1;
        if (u == v && d == l) {
            for (i = 0; i < Graph->vexnum; i++)
                std::cout << path[i];
            std::cout << std::endl;
        }
        p = Graph->adjlist[u].firstarc;
        while (p != nullptr) {
            w = p->adjvex;
            if (visited[w] == 0)
                PathAll(Graph, w, v, l, path, d, visited);
            p = p->nextarc;
        }
        visited[u] = 0;
    }

    void ShortPath(ALGraph *Graph, int u, int v) {
        typedef struct {
            int data;
            int patent;
        } Queue;

        int w, i, visited[MaxVertexNum];
        ArcNode *p;
        int front = -1, rear = -1;
        Queue queue[MaxVertexNum];
        for (i = 0; i < Graph->vexnum; i++)
            visited[i] = 0;
        queue[++rear].data = u;
        queue[rear].patent = -1;
        visited[u] = -1;

        while (front != rear) {
            w = queue[++front].data;
            if (w == v) {
                i = front;
                while (queue[i].patent != -1) {
                    std::cout << queue[i].data;
                    i = queue[i].patent;
                }
                std::cout << queue[i].data;
                break;
            }
            p = Graph->adjlist[w].firstarc;
            while (p != nullptr) {
                if (visited[p->adjvex] == 0) {
                    visited[p->adjvex] = 1;
                    rear++;
                    queue[rear].data = p->adjvex;
                    queue[rear].patent = front;
                }
                p = p->nextarc;
            }
        }
    }

    void MDFS(MGraph g, int v, int visited[]) {
        int w;
        std::cout << v;
        visited[v] = 1;
        for (w = 0; w < g.vexnum; w++)
            if (g.edges[v][w] != 0 && g.edges[v][w] != INT_FAST16_MIN && visited[w] == 0)
                MDFS(g, w, visited);
    }

    void DFS2(ALGraph *Graph, int v, int &vn, int &en, int visited[]) {
        ArcNode *p;
        visited[v] = 1;                                 // 置访问标记
        vn++;                                           // 记录定点数
        p = Graph->adjlist[v].firstarc;                 // 查找邻接顶点
        while (p != nullptr) {                          // 弧存在
            en++;                                       // 弧数+1
            if (visited[p->adjvex] == 0)                // 未访问过,递归访问
                DFS2(Graph, p->adjvex, vn, en, visited);// 递归访问
            p = p->nextarc;                             // 处理下一个邻接顶点
        }
    }

    bool GIsTree(ALGraph *Graph) {
        int vn = 0, en = 0, i, visited[MaxVertexNum];
        for (i = 0; i < Graph->vexnum; i++)
            visited[i] = 0;
        DFS2(Graph, 0, vn, en, visited);// 进行深度优先遍历
        if (en == 2 * (vn - 1))         // 无向图中弧数记录了两次
            return true;                // 符合树的条件
        else
            return false;// 不符合树的条件
    }

    void Cycle(ALGraph *Graph, int v, bool &has, int visited[]) {
        ArcNode *p;
        int w;
        visited[v] = 1;
        p = Graph->adjlist[v].firstarc;
        while (p != nullptr) {
            w = p->adjvex;
            if (visited[w] == 0)
                Cycle(Graph, w, has, visited);
            else
                has = true;
            p = p->nextarc;
        }
    }

    int Maxdist(ALGraph *Graph, int v) {
        ArcNode *p;
        int Qu[MaxVertexNum], front = 0, rear = 0;
        int visited[MaxVertexNum], i, j, k;
        for (i = 0; i < Graph->vexnum; i++)
            visited[i] = 0;
        Qu[++rear] = v;
        visited[v] = 1;
        while (front != rear) {
            front = (front + 1) % MaxVertexNum;
            k = Qu[front];
            p = Graph->adjlist[k].firstarc;
            while (p != nullptr) {
                j = p->adjvex;
                if (visited[j] == 0) {
                    visited[j] = 1;
                    rear = (rear + 1) % MaxVertexNum;
                    Qu[rear] = j;
                }
                p = p->nextarc;
            }
        }
        return k;
    }


}// namespace graph
