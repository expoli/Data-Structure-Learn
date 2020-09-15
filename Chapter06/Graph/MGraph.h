//
// Created by expoli on 2020/9/13.
//

#ifndef CHAPTER06_MGRAPH_H
#define CHAPTER06_MGRAPH_H

#define MAXV 60
#define InfoType int
#define Vertex int

namespace graph {
    typedef struct {
        int no;
        InfoType info;
    } VertexType;

    typedef struct {
        int edges[MAXV][MAXV];
        int n, e;
        VertexType vexs[MAXV];
    } MGraph;

    typedef struct Anode {
        int adjvex;
        struct Anode *nextarc;
        InfoType info;
    } ArcNode;

    typedef struct Vnode {
        Vertex data;
        ArcNode *firstarc;
    } VNode;

    typedef struct {
        VNode adjlist[MAXV];
        int n, e;
    } ALGraph;
}

#endif //CHAPTER06_MGRAPH_H
