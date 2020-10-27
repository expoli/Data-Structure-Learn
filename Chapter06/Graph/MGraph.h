//
// Created by expoli on 2020/9/13.
//

#ifndef CHAPTER06_MGRAPH_H
#define CHAPTER06_MGRAPH_H

#define MaxVertexNum 60// 图中顶点数目的最大值
#define InfoType int   // 网的边权值类型
#define Vertex int     // 顶点数据类型

namespace graph {
    typedef struct {
        int no;
        InfoType info;// 网的边权值
    } VertexType;     // 顶点结构
    typedef struct {
        int edges[MaxVertexNum][MaxVertexNum];// 邻接矩阵、边表
        int vexnum, arcnum;                   // 图的当前顶点数与弧数
        VertexType vexs[MaxVertexNum];        // 顶点表
    } MGraph;                                 // 图的邻接矩阵储存结构

    typedef struct ArcNode {
        int adjvex;             // 改弧所指向的顶点的位置
        struct ArcNode *nextarc;// 指向下一条弧的指针
        InfoType info;          // 网的边权值
    } ArcNode;                  // 边表结点
    typedef struct Vnode {      // 顶点表
        Vertex data;            // 顶点信息
        ArcNode *firstarc;      // 指向第一条依附该顶点的弧的指针
    } VNode;
    // 以邻接表存储的图类型
    typedef struct {                //
        VNode adjlist[MaxVertexNum];// 邻接表
        int vexnum, arcnum;         // 图的当前顶点数与弧数
    } ALGraph;                      // 以邻接表存储的图类型


    void DFS(ALGraph *Graph, int v, int visited[]);

    void BFS(ALGraph *Graph, int v, int visited[]);
}// namespace graph

#endif//CHAPTER06_MGRAPH_H
