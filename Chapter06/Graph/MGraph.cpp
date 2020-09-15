//
// Created by expoli on 2020/9/13.
//

#include "MGraph.h"
#include "iostream"

namespace graph {

    void DFS(ALGraph *G, int v, int visited[]) {
        ArcNode *p;
        int w;
        visited[v] = 1;
        std::cout << v;
        p = G->adjlist[v].firstarc;
        while (p != nullptr) {
            w = p->adjvex;
            if (visited[w] == 0)
                DFS(G, w, visited);
            p = p->nextarc;
        }
    }

    void BFS(ALGraph *G, int v) {
        ArcNode *p;
        int w, i;
        int queue[MAXV], front = 0, rear = 0;
        int visited[MAXV];
        for (i = 0; i < G->n; i++) {
            visited[i] = 0;
        }
        std::cout << v;
        rear = (rear + 1) % MAXV;
        queue[rear] = v;
        while (front != rear) {
            front = (front + 1) % MAXV;
            w = queue[front];
            p = G->adjlist[w].firstarc;
            while (p != nullptr) {
                if (visited[p->adjvex] == 0) {
                    std::cout << p->adjvex;
                    visited[p->adjvex] = 1;
                    rear = (rear + 1) % MAXV;
                    queue[rear] = p->adjvex;
                }
                p = p->nextarc;
            }
        }
    }

    void BFS1(ALGraph *G, int visited[]) {
        int i;
        for (i = 0; i < G->n; i++)
            if (visited[i] == 0)
                BFS1(G, visited);
    }

    bool Connect(ALGraph *G, int visited[]) {
        int i;
        bool flag = true;
        for (i = 0; i < G->n; i++)
            visited[i] = 0;
        DFS(G, 0, visited);
        for (i = 0; i < G->n; i++) {
            if (visited[i] == 0) {
                flag = false;
                break;
            }
        }
        return flag;
    }

    void ExistPath(ALGraph *G, int u, int v, bool &has, int visited[]) {
        int w;
        ArcNode *p;
        if (u == v) {
            has = true;
            return;
        }
        p = G->adjlist[u].firstarc;
        while (p != nullptr) {
            w = p->adjvex;
            if (visited[w] == 0)
                ExistPath(G, w, v, has, visited);
            p = p->nextarc;
        }
    }

    void FindAPath(ALGraph *G, int u, int v, int path[], int d, int visited[]) {
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
        p = G->adjlist[u].firstarc;
        while (p != nullptr) {
            w = p->adjvex;
            if (visited[w] == 0) {
                FindAPath(G, w, v, path, d, visited);
            }
            p = p->nextarc;
        }
    }

    void FindPath(ALGraph *G, int u, int v, int path[], int d, int visited[]) {
        int w, i;
        ArcNode *p;
        path[++d] = u;
        visited[u] = 1;
        if (u == v) {
            for (i = 0; i < G->n; i++)
                std::cout << path[i];
            std::cout << std::endl;
        }
        p = G->adjlist[u].firstarc;
        while (p != nullptr) {
            w = p->adjvex;
            if (visited[w] == 0)
                FindPath(G, w, v, path, d, visited);
            p = p->nextarc;
        }
        visited[u] = 0;
    }

    void PathAll(ALGraph *G, int u, int v, int l, int path[], int d, int visited[]) {
        int w, i;
        ArcNode *p;
        path[++d] = u;
        visited[u] = 1;
        if (u == v && d == l) {
            for (i = 0; i < G->n; i++)
                std::cout << path[i];
            std::cout << std::endl;
        }
        p = G->adjlist[u].firstarc;
        while (p != nullptr) {
            w = p->adjvex;
            if (visited[w] == 0)
                PathAll(G, w, v, l, path, d, visited);
            p = p->nextarc;
        }
        visited[u] = 0;
    }

    void ShortPath(ALGraph *G, int u, int v) {
        typedef struct {
            int data;
            int patent;
        } Queue;

        int w, i, visited[MAXV];
        ArcNode *p;
        int front = -1, rear = -1;
        Queue queue[MAXV];
        for (i = 0; i < G->n; i++)
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
            p = G->adjlist[w].firstarc;
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
        for (w = 0; w < g.n; w++)
            if (g.edges[v][w] != 0 && g.edges[v][w] != INT_FAST16_MIN && visited[w] == 0)
                MDFS(g, w, visited);
    }

    void DFS2(ALGraph *G, int v, int &vn, int &en, int visited[]) {
        ArcNode *p;
        visited[v] = 1;
        vn++;
        p = G->adjlist[v].firstarc;
        while (p != nullptr) {
            en++;
            if (visited[p->adjvex] == 0)
                DFS2(G, p->adjvex, vn, en, visited);
            p = p->nextarc;
        }
    }

    bool GIsTree(ALGraph *G) {
        int vn = 0, en = 0, i, visited[MAXV];
        for (i = 0; i < G->n; i++)
            visited[i] = 0;
        DFS2(G, 0, vn, en, visited);
        if (en == 2 * (vn - 1))
            return true;
        else
            return false;
    }

    void Cycle(ALGraph *G, int v, bool &has, int visited[]) {
        ArcNode *p;
        int w;
        visited[v] = 1;
        p = G->adjlist[v].firstarc;
        while (p != nullptr) {
            w = p->adjvex;
            if (visited[w] == 0)
                Cycle(G, w, has, visited);
            else
                has = true;
            p = p->nextarc;
        }
    }

    int Maxdist(ALGraph *G, int v) {
        ArcNode *p;
        int Qu[MAXV], front = 0, rear = 0;
        int visited[MAXV], i, j, k;
        for (i = 0; i < G->n; i++)
            visited[i] = 0;
        Qu[++rear] = v;
        visited[v] = 1;
        while (front != rear) {
            front = (front + 1) % MAXV;
            k = Qu[front];
            p = G->adjlist[k].firstarc;
            while (p != nullptr) {
                j = p->adjvex;
                if (visited[j] == 0) {
                    visited[j] = 1;
                    rear = (rear + 1) % MAXV;
                    Qu[rear] = j;
                }
                p = p->nextarc;
            }
        }
        return k;
    }


}
